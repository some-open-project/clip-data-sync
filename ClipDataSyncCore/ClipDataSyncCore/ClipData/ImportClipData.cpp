#include "ImportClipData.h"

#ifdef _WIN32
// win, mac, linux 분리 필요
bool ImportClipData::ImportClipDataFromJson(json mJson)
{
	if (false == OpenClipboard(nullptr))
	{
		return false;
	}

	if (false == mJson.contains(CLIPDATAARR) || false == mJson[CLIPDATAARR].is_array())
	{
		return false;
	}

	if (false == EmptyClipboard())
	{
		CloseClipboard();
		return false;
	}

	json::array_t clipDataArray = mJson[CLIPDATAARR];

	for (const auto& mInnerClipData : clipDataArray)
	{
		const int& nEnumType = mInnerClipData[CLIPNUMTYPE];
		const std::string& strClipData = mInnerClipData[CLIPINDATA];
		switch (nEnumType)
		{
		case CF_UNICODETEXT:
		{
			std::wstring wStrClipData;
			wStrClipData.assign(strClipData.begin(), strClipData.end());
			size_t nClipSize = static_cast<int>((wStrClipData.size() + 1) * sizeof(wchar_t));
			if (0 == nEnumType) { continue; }

			HGLOBAL hData = GlobalAlloc(GMEM_MOVEABLE, nClipSize);
			if (nullptr == hData) { continue; }

			memcpy(GlobalLock(hData), wStrClipData.c_str(), nClipSize);
			GlobalUnlock(hData);

			if (nullptr == SetClipboardData(nEnumType, hData))
			{
				continue;
			}
			break;
		}
		default:
		{		
			size_t nClipSize = mInnerClipData[CLIPSIZE];
			if (0 == nEnumType) { continue; }

			HGLOBAL hData = GlobalAlloc(GMEM_MOVEABLE, nClipSize);
			if (nullptr == hData) { continue; }

			memcpy(GlobalLock(hData), strClipData.c_str(), nClipSize);
			GlobalUnlock(hData);

			if (nullptr == SetClipboardData(nEnumType, hData))
			{
				continue;
			}
			break;
		}
		}
	}
	CloseClipboard();
	return true;
}
#endif
#include "ManagerClipDataForWindows.h"
#include "ClipData.h"

std::unique_ptr<ClipData> ManagerClipDataForWindows::extractGetClipData()
{
	// custom clipboard 에 경우에는 후에 찾을 떄마다 추가 진행
	// word의 native, embed source, 
	// hwp의 hwp native가 대표적

	if (false == OpenClipboard(nullptr)) { return nullptr; }
	ClipData* pClipData = new ClipData();
	ClipData* cur = pClipData;

	for (UINT nClipEnum : mClipEnum)
	{
		HANDLE hData = GetClipboardData(nClipEnum);

		if (nullptr == hData) { continue; }

		ClipData* clipPassData = new ClipData();

		clipPassData->setEnumClip(nClipEnum);

		char* insertClipName = const_cast<char*>(mBaseClipName[nClipEnum]);
		clipPassData->setClipName(insertClipName);

		switch (nClipEnum)
		{
		case CF_BITMAP:
		{
			// bitmap 추가 중

			continue;
			
			break;
		}
		case CF_ENHMETAFILE:
		{
			// META 파일 추가 중

			continue;
			break;
		}
		// utf-16이다 보니 다른 처리가 필요하다.
		case CF_UNICODETEXT:
		{
			wchar_t* wCbufferData = static_cast<wchar_t*>(GlobalLock(hData));
			if (nullptr == wCbufferData)
			{
				continue;
			}
			std::wstring strUnicodeText(wCbufferData);
			std::string strConText;
			for (wchar_t cUnicode : strUnicodeText)
			{
				if (cUnicode < 0x80)
				{
					strConText.push_back(static_cast<char>(cUnicode));
				}
				else if (cUnicode < 0x800)
				{
					strConText.push_back(static_cast<char>(0xC0 | (cUnicode >> 6)));
					strConText.push_back(static_cast<char>(0x80 | (cUnicode & 0x3F)));
				}
				else {
					strConText.push_back(static_cast<char>(0xE0 | (cUnicode >> 12)));
					strConText.push_back(static_cast<char>(0x80 | ((cUnicode >> 6) & 0x3F)));
					strConText.push_back(static_cast<char>(0x80 | (cUnicode & 0x3F)));
				}
			}
			char* bufferData = new char[strConText.length() + 1];
			std::copy(strConText.begin(), strConText.end(), bufferData);
			bufferData[strConText.length()] = '\0';

			SIZE_T bufferDataLen = strConText.length() + 1;
			char* insertClipData = new char[bufferDataLen + 1];
			memcpy_s(insertClipData, bufferDataLen + 1, bufferData, bufferDataLen + 1);
			clipPassData->setClipData(insertClipData);
			clipPassData->setClipSize(bufferDataLen);
			break;
		}
		default:
		{
			char* bufferData = static_cast<char*>(GlobalLock(hData));
			if (nullptr == bufferData)
			{
				continue;
			}
			SIZE_T bufferDataLen = GlobalSize(bufferData);
			char* insertClipData = new char[bufferDataLen + 1];
			memcpy_s(insertClipData, bufferDataLen + 1, bufferData, bufferDataLen + 1);
			clipPassData->setClipData(insertClipData);
			clipPassData->setClipSize(bufferDataLen);
			break;
		}
		}

	
		GlobalUnlock(hData);

		cur->setNext(clipPassData);
		cur = clipPassData;

	}

	UINT nClipDataFormat = 0;
	nClipDataFormat = EnumClipboardFormats(nClipDataFormat);
	while (0 != nClipDataFormat)
	{
		switch (nClipDataFormat)
		{
		case CF_UNICODETEXT:
		case CF_BITMAP:
		case CF_ENHMETAFILE:
		{
			nClipDataFormat = EnumClipboardFormats(nClipDataFormat);
			continue;
			break;
		}
		}
		TCHAR chrFormatName[256];
		int resultGetFormatName = GetClipboardFormatName(nClipDataFormat, chrFormatName, 256);

		if (resultGetFormatName <= 0) { break; }

		HANDLE hData = GetClipboardData(nClipDataFormat);

		if (nullptr == hData) { break; }

		ClipData* clipPassData = new ClipData();

		clipPassData->setEnumClip(nClipDataFormat);

		char passClipName[256];
		WideCharToMultiByte(CP_UTF8, 0, chrFormatName, -1, passClipName, 256, nullptr, nullptr);

		SIZE_T passClipNameLen = strlen(passClipName);
		char* insertClipName = new char[passClipNameLen + 1];
		strcpy_s(insertClipName, passClipNameLen + 1, passClipName);
		clipPassData->setClipName(insertClipName);

		char* bufferData = static_cast<char*>(GlobalLock(hData));

		SIZE_T bufferDataLen = GlobalSize(bufferData);

		char* insertClipData = new char[bufferDataLen + 1];
		memcpy_s(insertClipData, bufferDataLen + 1, bufferData, bufferDataLen + 1);
		clipPassData->setClipData(insertClipData);
		clipPassData->setClipSize(bufferDataLen);

		GlobalUnlock(hData);

		nClipDataFormat = EnumClipboardFormats(nClipDataFormat);

		cur->setNext(clipPassData);
		cur = clipPassData;
	}
	CloseClipboard();
	std::unique_ptr<ClipData> uniqueClipData(new ClipData(*pClipData));
	return move(uniqueClipData);
}

void ManagerClipDataForWindows::executeCopy()
{
	clipData = extractGetClipData();
}

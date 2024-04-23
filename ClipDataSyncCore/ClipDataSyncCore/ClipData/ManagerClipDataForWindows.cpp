#include "ManagerClipDataForWindows.h"
#include "ClipData.h"

std::unique_ptr<ClipData> ManagerClipDataForWindows::extractGetClipData()
{
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



			break;
		}
		default:
		{
			char* bufferData = static_cast<char*>(GlobalLock(hData));

			SIZE_T bufferDataLen = GlobalSize(bufferData);
			char* insertClipData = new char[bufferDataLen + 1];
			memcpy_s(insertClipData, bufferDataLen + 1, bufferData, bufferDataLen + 1);
			clipPassData->setClipData(insertClipData);
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

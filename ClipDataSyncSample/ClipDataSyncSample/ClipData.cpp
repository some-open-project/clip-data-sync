#include "ClipData.h"
#include <windows.h>
#include <memory>

std::vector<ClipData::passclip*> ClipData::extract()
{
	std::vector<ClipData::passclip*> vecClipData;

	if (false == OpenClipboard(nullptr)) { return vecClipData; }
	UINT nClipDataFormat = 0; 
	nClipDataFormat = EnumClipboardFormats(nClipDataFormat);
	while (0 != nClipDataFormat)
	{
		TCHAR chrFormatName[256];
		int resultGetFormatName = GetClipboardFormatName(nClipDataFormat, chrFormatName, 256);

		if (resultGetFormatName <= 0) { break; }
		

		HANDLE hData = GetClipboardData(nClipDataFormat);

		if (nullptr == hData) { break; }


		std::unique_ptr<ClipData::passclip> clipPassData(new ClipData::passclip());
		char passClipData[256];
		WideCharToMultiByte(CP_UTF8, 0, chrFormatName, -1, passClipData, 256, nullptr, nullptr);

		SIZE_T passClipDataLen = strlen(passClipData);
		clipPassData->strClipName = new char[passClipDataLen + 1];
		strcpy_s(clipPassData->strClipName, passClipDataLen + 1, passClipData);

		char* bufferData = (char*)GlobalLock(hData);

		SIZE_T bufferDataLen = strlen(bufferData);
		clipPassData->pData = new char[bufferDataLen + 1];
		memcpy_s(clipPassData->pData, bufferDataLen + 1, bufferData, bufferDataLen + 1);
		vecClipData.push_back(clipPassData.get());

		clipPassData.release();

		GlobalUnlock(hData);

		nClipDataFormat = EnumClipboardFormats(nClipDataFormat);
	}
	CloseClipboard();

	return vecClipData;
}
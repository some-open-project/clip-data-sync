#pragma once

#include <windows.h>
#include <vector>
#include <map>
#include <string>

#include "ManagerClipData.h"

class ManagerClipDataForWindows : public ManagerClipData
{
private:
	std::unique_ptr<ClipData> clipData;
	std::map<UINT, const char*> mBaseClipName = {
		{CF_TEXT, "Text"},
		{CF_BITMAP, "Bitmap"},
		{CF_METAFILEPICT, "MetaFilepict"},
		{CF_SYLK, "Sylk" },
		{CF_DIF, "Dif"},
		{CF_TIFF, "Tiff" },
		{CF_DIF, "Dif"},
		{CF_DIB, "Dib"},
		{CF_DIBV5, "Dibv5"},
		{CF_DSPBITMAP, "DspBitmap"},
		{CF_DSPENHMETAFILE, "DspEnhMetafile"},
		{CF_DSPMETAFILEPICT, "DspMetaFilepict"},
		{CF_DSPTEXT, "DspText"},
		{CF_ENHMETAFILE, "EnhMetaFile"},
		{CF_GDIOBJFIRST, "GdiObjFirst"},
		{CF_GDIOBJLAST, "GdiObjLast"},
		{CF_HDROP, "Hdrop"},
		{CF_LOCALE, "Locale"},
		{CF_OEMTEXT, "OemText"},
		{CF_OWNERDISPLAY, "OwnerDisplay"},
		{CF_PALETTE, "Plaette"},
		{CF_PENDATA, "PenData"},
		{CF_PRIVATEFIRST, "PrivateFirst"},
		{CF_PRIVATELAST, "PrivateLaste"},
		{CF_RIFF, "Riff"},
		{CF_UNICODETEXT, "UnicodeText"},
		{CF_WAVE, "Wave"}
	};
	std::vector<UINT> mClipEnum = 
	{ 
		CF_TEXT, 
		CF_BITMAP, 
		CF_METAFILEPICT, 
		CF_SYLK, 
		CF_DIF, 
		CF_TIFF, 
		CF_DIF, 
		CF_DIB, 
		CF_DIBV5, 
		CF_DSPBITMAP, 
		CF_DSPENHMETAFILE, 
		CF_DSPMETAFILEPICT,
		CF_DSPTEXT,
		CF_ENHMETAFILE,
		CF_GDIOBJFIRST,
		CF_GDIOBJLAST,
		CF_HDROP,
		CF_LOCALE,
		CF_OEMTEXT,
		CF_OWNERDISPLAY,
		CF_PALETTE,
		CF_PENDATA,
		CF_PRIVATEFIRST,
		CF_PRIVATELAST,
		CF_RIFF,
		CF_UNICODETEXT,
		CF_WAVE
	};
	const char* mOS = "Windows";

public:
	ManagerClipDataForWindows() 
	{
		clipData = std::unique_ptr<ClipData>(new ClipData());
	}
	~ManagerClipDataForWindows() override
	{
	}
	std::unique_ptr<ClipData> extractGetClipData() override;
	void executeCopy() override;
	ClipData getClipData() override { return *clipData.get(); };
	const char* getOS() { return mOS; }
};

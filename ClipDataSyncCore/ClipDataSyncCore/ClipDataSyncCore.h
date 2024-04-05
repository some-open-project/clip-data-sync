#pragma once

#ifdef CLIPDATASYNCCORE_EXPORTS
#define CLIPDATASYNCCORE_API __declspec(dllexport)
#else
#define CLIPDATASYNCCORE_API __declspec(dllimport)
#endif

#include <memory>

#include "ClipData/ClipData.h"
#include "ClipData/ManagerClipDataForWindows.h"
#include "cpprest/json.h"

CLIPDATASYNCCORE_API class ClipDataSyncCore
{
private:
	std::unique_ptr<ManagerClipData> managerClip;

public:
	CLIPDATASYNCCORE_API ClipDataSyncCore();
	CLIPDATASYNCCORE_API web::json::value getClipData();
	CLIPDATASYNCCORE_API web::json::value updateCLipDataForServer();
	CLIPDATASYNCCORE_API void setClipData();
	CLIPDATASYNCCORE_API bool syncCLipDatafromServer();
	CLIPDATASYNCCORE_API bool setUserData(char* userData);
};

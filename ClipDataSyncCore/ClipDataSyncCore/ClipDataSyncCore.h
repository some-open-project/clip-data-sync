#pragma once

#ifdef CLIPDATASYNCCORE_EXPORTS
#define CLIPDATASYNCCORE_API __declspec(dllexport)
#else
#define CLIPDATASYNCCORE_API __declspec(dllimport)
#endif

#include <memory>

#include "ClipData/ClipData.h"
#include "ClipData/ManagerClipDataForWindows.h"
#include "ClipData/ExportClipData.h"
#include "ClipData/ImportClipData.h"
#include "ThirdParty/json.hpp"

using json = nlohmann::json;

CLIPDATASYNCCORE_API class ClipDataSyncCore
{
private:
	std::unique_ptr<ManagerClipData> managerClip;

public:
	CLIPDATASYNCCORE_API ClipDataSyncCore();
	CLIPDATASYNCCORE_API void executeClipCopy();
	CLIPDATASYNCCORE_API void executeClipPaste();
	CLIPDATASYNCCORE_API json getClientClipData();
	CLIPDATASYNCCORE_API json updateClipDataForServer();
	CLIPDATASYNCCORE_API bool setClipData(json& jsonClipData);
	CLIPDATASYNCCORE_API bool syncClipDatafromServer();
	CLIPDATASYNCCORE_API bool setUserData(char* userData);
};

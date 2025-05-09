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
#include "DBManager/DBPostgre.h"
#include "ThirdParty/json.hpp"

using json = nlohmann::json;

CLIPDATASYNCCORE_API class ClipDataSyncCore
{
private:
	std::unique_ptr<ManagerClipData> managerClip;
	std::unique_ptr<DBPostgre> dbSql;

public:
	CLIPDATASYNCCORE_API ClipDataSyncCore();
	CLIPDATASYNCCORE_API void executeClipCopy();
	CLIPDATASYNCCORE_API void executeClipPaste();
	CLIPDATASYNCCORE_API json getClientClipData();
	CLIPDATASYNCCORE_API json updateClipDataForServer();
	CLIPDATASYNCCORE_API bool setClipData(json& jsonClipData);
	CLIPDATASYNCCORE_API bool syncClipDatafromServer();
	CLIPDATASYNCCORE_API bool setUserData(char* userData);
	CLIPDATASYNCCORE_API bool connectClipSql();
	CLIPDATASYNCCORE_API ClipDataSyncCore& setDBName(const char* pDBName);
	CLIPDATASYNCCORE_API ClipDataSyncCore& setDBUserName(const char* pUserName);
	CLIPDATASYNCCORE_API ClipDataSyncCore& setDBPassWord(const char* pPassWord);
	CLIPDATASYNCCORE_API ClipDataSyncCore& setDBHost(const char* pHost);
	CLIPDATASYNCCORE_API ClipDataSyncCore& setDBPort(const char* pPort);
};

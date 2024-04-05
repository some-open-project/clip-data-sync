#include "ClipDataSyncCore.h"


ClipDataSyncCore::ClipDataSyncCore()
{
#ifdef _WIN32
	managerClip = std::unique_ptr<ManagerClipDataForWindows>(new ManagerClipDataForWindows());
#endif
}

web::json::value ClipDataSyncCore::getClipData()
{
	web::json::value clipDataJson;

	return clipDataJson;
}


#pragma once

#include "../ThirdParty/json.hpp"

#include "ManagerClipData.h"
#include "JsonSetting.h"

#ifdef _WIN32
#include "ManagerClipDataForWindows.h"
#endif
	
using json = nlohmann::json;

class ExportClipData
{
public:
	ExportClipData() = default;
	~ExportClipData() = default;

	[[nodiscard]] json exportClipData(ManagerClipData& mClipData);
};

#pragma once

#include "../ThirdParty/json.hpp"

#include "ManagerClipData.h"

#ifdef _WIN32
#include "ManagerClipDataForWindows.h"
#endif
	
using json = nlohmann::json;

class ExportClipData
{
public:
	ExportClipData() = default;
	~ExportClipData() = default;

	json exportClipData(ManagerClipData& mClipData);
};

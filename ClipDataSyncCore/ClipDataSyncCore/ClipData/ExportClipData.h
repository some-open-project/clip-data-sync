#pragma once

#include "ClipData.h"

class ExportClipData
{
public:
	char* exportClipData(ClipData clipData);
	char* exportClipDataForServer(ClipData clipData);
};

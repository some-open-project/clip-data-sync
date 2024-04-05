#pragma once

#include <windows.h>

#include "ManagerClipData.h"
#include "ImportClipData.h"


class ManagerClipDataForWindows : public ManagerClipData
{
private:
	std::unique_ptr<ClipData> clipData;

public:
	ManagerClipDataForWindows()
	{
		clipData = std::unique_ptr<ClipData>(new ClipData());
	}
	~ManagerClipDataForWindows()
	{
	}
	void extractGetClipData();
	ClipData getClipData() { return *clipData.get(); };
};

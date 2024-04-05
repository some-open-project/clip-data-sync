#pragma once

#include <memory>
#include "ClipData.h"

class ManagerClipData
{
private:
	std::unique_ptr<ClipData> clipData;

public:
	ManagerClipData()
	{
		clipData = std::unique_ptr<ClipData>(new ClipData());
	}
	virtual ~ManagerClipData()
	{
	}
	virtual void extractGetClipData() {};
	virtual ClipData getClipData() { return *clipData.get(); }
};

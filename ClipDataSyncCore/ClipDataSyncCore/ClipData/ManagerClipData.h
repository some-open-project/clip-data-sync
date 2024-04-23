#pragma once

#include <memory>
#include "ClipData.h"

class ManagerClipData
{
private:
	const char* mOS = "";
	std::unique_ptr<ClipData> clipData;

public:
	ManagerClipData()
	{
		clipData = std::unique_ptr<ClipData>(new ClipData());
	}
	virtual ~ManagerClipData() = default;

	virtual std::unique_ptr<ClipData> extractGetClipData() {
		std::unique_ptr<ClipData> val;
		return val;
	}
	virtual void executeCopy() { return; }
	virtual ClipData getClipData() { return *clipData.get(); }
	virtual const char* getOS() { return mOS; }
};

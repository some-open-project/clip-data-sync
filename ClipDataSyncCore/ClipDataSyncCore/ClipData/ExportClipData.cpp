#include "ExportClipData.h"

json ExportClipData::exportClipData(ManagerClipData& mClipData)
{
	json jsonClipData;
	jsonClipData["OS"] = mClipData.getOS();
	ClipData uExportClip = mClipData.getClipData();

	if (nullptr == uExportClip.getNext()) { return jsonClipData; }

	ClipData* curClipData = uExportClip.getNext();

	int index = 0;
	jsonClipData["ClipData"] = json::array();
	while (nullptr != curClipData)
	{
		auto& innerClipData = jsonClipData["ClipData"];
		innerClipData[index]["EnumClip"] = curClipData->getEnumClip();
		innerClipData[index]["ClipName"] = curClipData->getClipName();
		innerClipData[index]["ClipData"] = curClipData->getClipData();
		index++;
		curClipData = curClipData->getNext();
	}


	return jsonClipData;
}

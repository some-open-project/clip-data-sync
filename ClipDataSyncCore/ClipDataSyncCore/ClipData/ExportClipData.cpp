#include "ExportClipData.h"
#include <codecvt>
#include <locale>

[[nodiscard]] json ExportClipData::exportClipData(ManagerClipData& mClipData)
{
	json jsonClipData;
	ClipData uExportClip = mClipData.getClipData();

	if (nullptr == uExportClip.getNext()) { return jsonClipData; }

	ClipData* curClipData = uExportClip.getNext();

	int index = 0;
	jsonClipData[CLIPDATAARR] = json::array();
	while (nullptr != curClipData)
	{
		auto& innerClipData = jsonClipData[CLIPDATAARR];
		innerClipData[index][CLIPSIZE] = curClipData->getClipSize();
		innerClipData[index][CLIPINDATA] = curClipData->getClipData();
		innerClipData[index][CLIPNAME] = curClipData->getClipName();
		innerClipData[index][CLIPNUMTYPE] = curClipData->getEnumClip();
		index++;
		curClipData = curClipData->getNext();
	}
	jsonClipData[OS] = mClipData.getOS();


	return jsonClipData;
}

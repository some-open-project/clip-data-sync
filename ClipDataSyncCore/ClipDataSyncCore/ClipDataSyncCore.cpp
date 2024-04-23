#include "ClipDataSyncCore.h"


ClipDataSyncCore::ClipDataSyncCore()
{
#ifdef _WIN32
	managerClip = std::unique_ptr<ManagerClipDataForWindows>(new ManagerClipDataForWindows());
#endif
}

#include <iostream>
json ClipDataSyncCore::getClientClipData()
{
	std::unique_ptr<ExportClipData> uExportClipData = std::make_unique<ExportClipData>();

	// 이부분이 아니라 copy시랑 UI 선택시 paste 동작처럼 clipSet을 할떄 managerClip 내부 데이터에 변화가 생길 것임
	// 아래 부분은 테스트 용 수정 단계에서 밑 라인 제거
	managerClip->executeCopy();

	json clipDataJson = uExportClipData->exportClipData(*managerClip);

	// json 빌드 확인용
	std::cout << clipDataJson << std::endl;

	return clipDataJson;
}


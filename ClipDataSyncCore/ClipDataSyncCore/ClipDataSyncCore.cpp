#include "ClipDataSyncCore.h"

#define JSON_OUTPUT_TEST 0

#if JSON_OUTPUT_TEST == 1
#include <fstream>
#endif
	

ClipDataSyncCore::ClipDataSyncCore()
{
#ifdef _WIN32
	managerClip = std::unique_ptr<ManagerClipDataForWindows>(new ManagerClipDataForWindows());
#endif
	dbSql = std::unique_ptr<DBPostgre>(new DBPostgre());
}

#include <iostream>
json ClipDataSyncCore::getClientClipData()
{
	std::unique_ptr<ExportClipData> uExportClipData = std::make_unique<ExportClipData>();

	// 이부분이 아니라 copy시랑 UI 선택시 paste 동작처럼 clipSet을 할떄 managerClip 내부 데이터에 변화가 생길 것임
	// 아래 부분은 테스트 용 수정 단계에서 밑 라인 제거
	managerClip->executeCopy();

	json clipDataJson = uExportClipData->exportClipData(*managerClip);
	
#if JSON_OUTPUT_TEST == 1
	// json 빌드 확인용
	// UTF-8 관련 추가
	std::ofstream file("./test.json", std::ios::out | std:: ios::binary);
	file.imbue(std::locale("ko_KR.UTF-8"));
	file << clipDataJson;
	// 빌드 확인 용
#endif

	return clipDataJson;
}

bool ClipDataSyncCore::setClipData(json& jsonClipData)
{	
	std::unique_ptr<ImportClipData> uImportClipData = std::make_unique<ImportClipData>();
	bool bCheckImport = uImportClipData->ImportClipDataFromJson(jsonClipData);

	return bCheckImport;
}

bool ClipDataSyncCore::connectClipSql()
{
	return dbSql->Connect();
}

ClipDataSyncCore& ClipDataSyncCore::setDBName(const char* pDBName)
{
	dbSql->setDBName((char*)pDBName);
	return *this;
}
ClipDataSyncCore& ClipDataSyncCore::setDBUserName(const char* pUserName)
{
	dbSql->setUserName((char*)pUserName);
	return *this;
}

ClipDataSyncCore& ClipDataSyncCore::setDBPassWord(const char* pPassWord)
{
	dbSql->setPassWord((char*)pPassWord);
	return *this;
}

ClipDataSyncCore& ClipDataSyncCore::setDBHost(const char* pHost)
{
	dbSql->setHost((char*)pHost);
	return *this;
}

ClipDataSyncCore& ClipDataSyncCore::setDBPort(const char* pPort)
{
	dbSql->setPort((char*)pPort);
	return *this;
}

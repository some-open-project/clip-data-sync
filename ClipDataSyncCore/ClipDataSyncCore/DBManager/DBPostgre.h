#pragma once
#include "DBManager.h"
#include "libpq-fe.h"

class DBPostgre : DBManager<DBPostgre>
{
private:
	char* cHost = nullptr;
	char* cPort = nullptr;
	char* cDBName = nullptr;
	char* cUserName = nullptr;
	char* cPassWord = nullptr;
	PGconn* pPostgre = nullptr;

public:
	DBPostgre() = default;

	~DBPostgre() = default;

	DBPostgre& setHost(char* cHost_) override;

	char* getHost() { return cHost; }

	DBPostgre& setPort(char* cPort_) override;
	
	char* getPort() { return cPort; }

	DBPostgre& setDBName(char* cDBName_) override;

	char* getDBName() { return cDBName; }

	DBPostgre& setUserName(char* cUserName_) override;

	char* getUserName() { return cUserName; }

	DBPostgre& setPassWord(char* cPassWord_) override;

	char* getPassWord() { return cPassWord; }

	bool Connect();

	bool Check();

	bool Create() override;

	bool Update(json jsonValue) override;

	bool Read(json jsonValue) override;

	bool Delete(json jsonValue) override;

};

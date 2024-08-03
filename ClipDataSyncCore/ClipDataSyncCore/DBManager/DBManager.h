#pragma once
#include "../ThirdParty/json.hpp"

using json = nlohmann::json;

template<typename T>
class DBManager
{
private:
	char* cHost = nullptr;
	char* cPort = nullptr;
	char* cDBName = nullptr;
	char* cUserName = nullptr;
	char* cPassWord = nullptr;

public:
	DBManager() = default;
	
	virtual ~DBManager() = default;

	virtual DBManager<T>& setHost(char* cHost_) = 0;
	virtual DBManager<T>& setPort(char* cPort_) = 0;
	virtual DBManager<T>& setDBName(char* cDBName_) = 0;
	virtual DBManager<T>& setUserName(char* cUserName_) = 0;
	virtual DBManager<T>& setPassWord(char* cPassWord_) = 0;

	virtual bool Create() = 0;

	virtual bool Update(json jsonValue) = 0;

	virtual bool Read(json jsonValue) = 0;

	virtual bool Delete(json jsonValue) = 0;

};

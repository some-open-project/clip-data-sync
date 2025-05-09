#include "DBPostgre.h"

DBPostgre& DBPostgre::setHost(char* cHost_)
{
	cHost = cHost_;
	return *this;
}

DBPostgre& DBPostgre::setPort(char* cPort_)
{
	cPort = cPort_;
	return *this;
}

DBPostgre& DBPostgre::setDBName(char* cDBName_)
{
	cDBName = cDBName_;
	return *this;
}

DBPostgre& DBPostgre::setUserName(char* cUserName_)
{
	cUserName = cUserName_;
	return *this;
}

DBPostgre& DBPostgre::setPassWord(char* cPassWord_)
{
	cPassWord = cPassWord_;
	return *this;
}

bool DBPostgre::Connect()
{
	if (false == Check()) { return false; }

	std::string pConnInfo = "";
	pConnInfo += "dbname=";
	pConnInfo += getDBName();
	pConnInfo += " user=";
	pConnInfo += getUserName();
	pConnInfo += " password=";
	pConnInfo += getPassWord();
	pConnInfo += " hostaddr=";
	pConnInfo += getHost();
	pConnInfo += " port=";
	pConnInfo += getPort();

	pPostgre = PQconnectdb(pConnInfo.c_str());

	if (CONNECTION_BAD == PQstatus(pPostgre))
	{
		PQfinish(pPostgre);
		return false;
	}

	return true;
}

bool DBPostgre::Check()
{
	bool hasHost = (getHost() != nullptr);
	bool hasPort = (getPort() != nullptr);
	bool hasUserName = (getUserName() != nullptr);
	bool hasDBName = (getDBName() != nullptr);
	bool hasPassWord = (getPassWord() != nullptr);
	bool bRetValue = (hasHost && hasPort && hasUserName && hasDBName && hasPassWord);

	return bRetValue;
}

bool DBPostgre::Create()
{
	if (false == Check()) { return false; }

	return true;
}

bool DBPostgre::Update(json jsonValue)
{
	if (false == Check()) { return false; }

	return true;
}

bool DBPostgre::Read(json jsonValue)
{
	if (false == Check()) { return false; }

	return true;
}

bool DBPostgre::Delete(json jsonValue)
{
	if (false == Check()) { return false; }

	return true;
}

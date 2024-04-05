#pragma once

class ClipData
{
private:
	char* pClipName;
	char* pClipData;
	char* encryptionClipName;
	char* encryptionClipData;
	ClipData* next;

public:
	ClipData()
	{
		pClipName = nullptr;
		pClipData = nullptr;
		encryptionClipName = nullptr;
		encryptionClipData = nullptr;
		next = nullptr;
	}

	ClipData(char* pClipName, char* pClipData) 
	{
		this->pClipName = pClipName;
		this->pClipData = pClipData;
		next = nullptr;
	}

	virtual ~ClipData()
	{
		delete(pClipName);
		delete(pClipData);
		delete(next);
	}

	void setNext(ClipData* next)
	{
		this->next = next;
	}

	ClipData* getNext()
	{
		return next;
	}

	void setClipName(char* pClipName)
	{
		this->pClipName = pClipName;
	}

	char* getClipName()
	{
		return pClipName;
	}

	void setClipData(char* pClipData)
	{
		this->pClipData = pClipData;
	}

	char* getClipData()
	{
		return pClipData;
	}
};

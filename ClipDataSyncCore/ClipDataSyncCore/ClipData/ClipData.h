#pragma once

class ClipData
{
private:
	unsigned int mEnumClip;
	char* pClipName;
	char* pClipData;
	char* encryptionClipName;
	char* encryptionClipData;
	ClipData* next;

public:
	ClipData()
	{
		mEnumClip = 0;
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
	}

	void setNext(ClipData* next)
	{
		this->next = next;
	}

	ClipData* getNext()
	{
		return next;
	}

	void setEnumClip(unsigned int mEnumClip)
	{
		this->mEnumClip = mEnumClip;
	}

	unsigned int getEnumClip()
	{
		return mEnumClip;
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

#pragma once
#include <vector>
#include <string>

class ClipData
{
public:
	struct passclip
	{
		char* strClipName;
		char* pData;
	};

private:
	std::vector<passclip*>pClipData;

public:
	ClipData() {};
	~ClipData() {};
	std::vector<passclip*> extract();
	void setClipData(std::vector<passclip*> pClipData) { this->pClipData = pClipData; }
	std::vector<passclip*> getClipData() { return this->pClipData; }
	void run();

};

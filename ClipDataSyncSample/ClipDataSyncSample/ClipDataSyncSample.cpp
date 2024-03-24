#include <memory>
#include "ClipData.h"
#include <iostream>

int main()
{
	std::unique_ptr<ClipData> cp(new ClipData());

	// get Clipboard
	std::vector<ClipData::passclip*> vecClip = cp->extract();

	// C++ Client -> Java Server
	//

}

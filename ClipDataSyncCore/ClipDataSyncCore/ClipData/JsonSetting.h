#pragma once
#include <string_view>
#include <string>
#include <utility>


template <std::size_t S>
const inline std::string makeStringLiteral(const char(&str)[S])
{
	return std::string(str, S - 1);
}

// Export Import str
const std::string OS = makeStringLiteral("OS");
const std::string CLIPDATAARR = makeStringLiteral("ClipDataArr");
const std::string CLIPINDATA = makeStringLiteral("ClipData");
const std::string CLIPNAME = makeStringLiteral("ClipName");
const std::string CLIPNUMTYPE = makeStringLiteral("ClipEnumType");
const std::string CLIPSIZE = makeStringLiteral("ClipSize");
const std::string CLIPINDATAUTF = makeStringLiteral("ClipDataUtf16");

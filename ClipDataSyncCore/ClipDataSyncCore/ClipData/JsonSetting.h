#pragma once
#include <string_view>
#include <string>
#include <utility>


template <std::size_t S>
constexpr auto makeStringLiteral(const char(&str)[S])
{
	return std::string_view(str, S - 1);
}

// Export Import str
constexpr auto OS = makeStringLiteral("OS");
constexpr auto CLIPDATAARR = makeStringLiteral("ClipDataArr");
constexpr auto CLIPINDATA = makeStringLiteral("ClipData");
constexpr auto CLIPNAME = makeStringLiteral("ClipName");
constexpr auto CLIPNUMTYPE = makeStringLiteral("ClipEnumType");
constexpr auto CLIPSIZE = makeStringLiteral("ClipSize");
constexpr auto CLIPINDATAUTF = makeStringLiteral("ClipDataUtf16");

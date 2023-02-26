#pragma once
#include "Global.h"

// Convert int to string
std::string itos(int val)
{
	char buffer[_MAX_U64TOSTR_BASE10_COUNT];
	_ultoa_s(val, buffer, _countof(buffer), 10);
	return buffer;
}
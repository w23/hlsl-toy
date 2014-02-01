#pragma once

#include "windows.h"

namespace toy {

class Console {
public:
	Console();
	~Console();

	static void printf(const char *format, ...);

private:
	HANDLE _out;
	static Console _console;
};

} // namespace toy

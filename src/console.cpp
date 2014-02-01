#include <strsafe.h>
#include "console.h"

namespace toy {

Console Console::_console; // console console

Console::Console() {
	::AllocConsole();
	_out = ::GetStdHandle(STD_OUTPUT_HANDLE);
}

Console::~Console() {
	::FreeConsole();
}

void Console::printf(const char *format, ...) {
	va_list args;
	va_start(args, format);
	char buffer[1024];
	StringCbVPrintfA(buffer, sizeof(buffer)-2, format, args);
	int len = strlen(buffer);
	buffer[len] = '\r';
	buffer[len+1] = '\n';
	WriteFile(_console._out, buffer, len+2, NULL, NULL);
	va_end(args);
}

} // namespace toy

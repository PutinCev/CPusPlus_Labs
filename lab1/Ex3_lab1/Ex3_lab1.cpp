
#include <fmt/core.h>
#include <string>
#include <windows.h>

int main() {

	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	int x = 42;
	std::string name = "Alice";
	// Печать с форматированием
	fmt::print("Hello, {}, the answer is {}!\n", name, x);
	return 0;
}

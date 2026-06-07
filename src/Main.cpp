#include "Application.h"
#include <print>

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		std::println("Usages: rin [script]");
	}
	else if (argc == 1)
	{
		Rin::Application::Handle(argv[1]);
	}
	else
	{
		Rin::Application::RunPrompt();
	}
}

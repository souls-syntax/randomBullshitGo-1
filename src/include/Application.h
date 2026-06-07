#pragma once

namespace Rin {
	class Application
	{
		public:
			Application();
			virtual ~Application();
			void Handle(char* file);
			void runPrompt();
	};
}

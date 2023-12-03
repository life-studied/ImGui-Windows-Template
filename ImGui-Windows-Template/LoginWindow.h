#pragma once
#include "WinRoaming/Window.h"
namespace IBase
{
	namespace IWindows
	{
		using namespace window;

		class LoginWindow : public Window
		{
		public:
			LoginWindow(string name = "Login", string _parent = "");
			virtual string drawNext(unordered_map<string, Window*>& windowlist) override;
		private:

			string account;
			string password;
		};
		
	}
}
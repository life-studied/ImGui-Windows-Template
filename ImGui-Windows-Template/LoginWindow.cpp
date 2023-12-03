#include "LoginWindow.h"
#include "imgui.h"

using namespace IBase::IWindows;
IBase::IWindows::LoginWindow::LoginWindow(string name, string _parent) :Window(name, _parent)
{

}

std::string IBase::IWindows::LoginWindow::drawNext(unordered_map<string, Window*>& windowlist)
{
	using namespace ImGui;
	static char AccountBox[25] = u8"输入你的账号";
	static char PasswordBox[25] = u8"输入你的密码";
	bool isOpen = true;

	Begin("Login", &isOpen);
	auto size = GetWindowSize();
	auto length = size.x;
	auto width = size.y;

	// InputTexts
	SetCursorPosY(width/2);
	InputText(u8"账号", AccountBox, IM_ARRAYSIZE(AccountBox));
	InputText(u8"密码", PasswordBox, IM_ARRAYSIZE(PasswordBox));
	account = AccountBox;
	password = PasswordBox;

	// buttons
	SetCursorPosX(width / 10 * 8);
	bool click = Button(u8"登录"); SameLine();
	bool click_regis = Button(u8"注册");

	End();
	// close the window
	if (!isOpen)	return {};
	
	// check password and set label if wrong
	if (click) return "Admin";
	return getName();
}

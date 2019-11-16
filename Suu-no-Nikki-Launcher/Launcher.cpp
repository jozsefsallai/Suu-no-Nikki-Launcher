#include "Launcher.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void MainWin(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SuunoNikkiLauncher::Launcher launcher;
	Application::Run(%launcher);
}

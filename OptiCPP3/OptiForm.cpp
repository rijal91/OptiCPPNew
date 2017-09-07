#include "OptiForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OptiCPP3::OptiForm form;
	Application::Run(%form);
}

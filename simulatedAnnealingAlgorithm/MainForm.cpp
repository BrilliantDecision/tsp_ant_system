#include "MainForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void Main()
{
	setlocale(LC_ALL, "ru");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	simulatedAnnealingAlgorithm::MainForm form1;
	Application::Run(% form1);
}
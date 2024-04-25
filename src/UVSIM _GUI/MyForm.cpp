#include "UVSim.h"
#include "uvsimulator.h" // Include the header file for UVSimulator

using namespace System;
using namespace System::Windows::Forms;
using namespace UVSIM; // Assuming UVSimulator is defined within the UVSIM namespace

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MyForm form;
    Application::Run(% form);

    return 0;
}


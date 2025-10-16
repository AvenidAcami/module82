#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Создаем и запускаем форму
    module82::MyForm^ form = gcnew module82::MyForm();
    Application::Run(form);

    return 0;
}

#include "Application.h"

int main(void)
{
    Application app;

    app.Init();
    app.Run();
    app.Close();

    return 0;
}
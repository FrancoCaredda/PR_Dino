#include "DinoApplication.h"

int main(void)
{
    DinoApplication app;

    app.Init();
    app.Run();
    app.Close();

    return 0;
}
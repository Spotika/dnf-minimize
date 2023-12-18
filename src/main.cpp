#include "Engine/BaseApp.h"
#include "MainApp.h"

namespace ul = ultralight;

int main() {
    BaseApp::RunServer(); // start the server if it is not running

    // Main part of code, running ultralight app
    MainApp app;
    app.Run();

    BaseApp::StopServer();
}


#include "../BaseApp.h"
#include "AppCore/JSHelpers.h"
#include "windows.h"
#include <thread>


namespace ul = ultralight;
using namespace ultralight;

BaseApp::BaseApp(int width, int height, bool fullscreen, unsigned int window_flags, double device_scale) {
    app_ = ul::App::Create();

    window_ = ul::Window::Create(app_->main_monitor(), width, height,
                                 fullscreen, window_flags);

    overlay_ = ul::Overlay::Create(window_, window_->width(), window_->height(), 0, 0);
    BaseApp::OnResize(window_.get(), window_->width(), window_->height());

    overlay_->view()->set_device_scale(device_scale);

    window_->set_listener(this);

    app_->set_listener(this);

    overlay_->view()->set_load_listener(this);
    overlay_->view()->set_view_listener(this);
    overlay_->view()->LoadURL("http://localhost:3000/"); // TODO: set url you need. localhost:3000 is default for react
}


bool BaseApp::OnMouseEvent(const ultralight::MouseEvent &evt) {
    // Event handling, according to the scale
    auto cp = evt;
    double scale = overlay_->view()->device_scale();
    cp.x = static_cast<int>(cp.x / scale);
    cp.y = static_cast<int>(cp.y / scale);

    overlay_->view()->FireMouseEvent(cp);
    return false;
}

bool BaseApp::OnKeyEvent(const ultralight::KeyEvent &evt) {
    overlay_->view()->FireKeyEvent(evt);
    return false;
}

bool BaseApp::OnScrollEvent(const ultralight::ScrollEvent &evt) {
    overlay_->view()->FireScrollEvent(evt);
    return false;
}

ul::JSValue BaseApp::MakeServerAvailable(const ul::JSObject &thisObject, const ul::JSArgs &args) {
    return ul::JSString("true");
}

void BaseApp::OnResize(ultralight::Window *window, uint32_t width_px, uint32_t height_px) {
    overlay_->Resize(width_px, height_px);
}

void BaseApp::OnClose(ultralight::Window *window) {
    app_->Quit();
}

void BaseApp::Run() const {
    app_->Run();
}

void BaseApp::OnDOMReady(ultralight::View *caller,
                         uint64_t frame_id,
                         bool is_main_frame,
                         const ul::String &url) {}

void BaseApp::OnChangeTitle(ultralight::View *caller,
                            const ul::String &title) {
    window_->SetTitle(title.utf8().data());
}

void BaseApp::RunServer() {
    if (std::system("python ../check_port.py")) {
        _putenv("BROWSER=none"); // it for no browser open

#ifndef PRODUCTION
        // building react, not for production
        std::system("cd ../react-user-interface & npm run build");
#endif
        // starting React server
        static std::thread serverThread([] () {system("cd ../react-user-interface & serve -s build");});

        // waiting for server to start
        while (std::system("python ../check_port.py")) {std::this_thread::sleep_for(std::chrono::seconds(1));}
    }
}

void BaseApp::StopServer() {
    // kill all threads and react server
    DWORD pidToTerminate = GetCurrentProcessId();
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pidToTerminate);
    if (hProcess == nullptr) {
        exit(1);
    }
    TerminateProcess(hProcess, 0);
    CloseHandle(hProcess);
}
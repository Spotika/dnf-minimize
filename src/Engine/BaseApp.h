#pragma once

#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/JSHelpers.h>
#include <Ultralight/Renderer.h>
#include <Ultralight/platform/Config.h>
#include <string>
#include <vector>

namespace ul = ultralight;

class BaseApp : public ul::WindowListener,
                public ul::LoadListener,
                public ul::ViewListener,
                public ul::AppListener {
    ul::RefPtr<ul::App> app_;
    ul::RefPtr<ul::Window> window_;
    ul::RefPtr<ul::Overlay> overlay_;
public:
    BaseApp(int width, int height, bool fullscreen, unsigned int window_flags, double device_scale);

    bool OnMouseEvent(const ul::MouseEvent &evt) override;

    bool OnKeyEvent(const ul::KeyEvent &evt) override;

    bool OnScrollEvent(const ul::ScrollEvent &evt) override;

    void OnResize(ul::Window *window, uint32_t width_px, uint32_t height_px) override;

    void OnClose(ul::Window *window) override;

    void Run() const;

    ul::JSValue MakeServerAvailable(const ul::JSObject &thisObject, const ul::JSArgs &args);

    void OnDOMReady(ul::View *caller,
                    uint64_t frame_id,
                    bool is_main_frame,
                    const ul::String &url) override;

    void OnChangeTitle(ul::View *caller, const ul::String &title) override;

    /// Starting the server if it is not running
    static void RunServer();

    /// Stopping server and whole program
    [[noreturn]] static void StopServer();
};
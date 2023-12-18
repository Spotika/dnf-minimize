#pragma once

#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include <AppCore/JSHelpers.h>
#include <Ultralight/Renderer.h>
#include <Ultralight/platform/Config.h>
#include <string>
#include "config.h"

namespace ul = ultralight;

class BaseApp : public ul::WindowListener,
                public ul::LoadListener,
                public ul::ViewListener,
                public ul::AppListener {
    ul::RefPtr<ul::App> app_;
    ul::RefPtr<ul::Window> window_;
    ul::RefPtr<ul::Overlay> overlay_;
public:
    /// \param width window width
    /// \param height window height
    /// \param fullscreen if window will be fullscreen
    /// \param window_flags special flags, like kWindowFlags_Maximizable or kWindowFlags_Maximizable kWindowFlags_Resizable
    /// \param device_scale scale factor for whole app
    BaseApp(int width, int height, bool fullscreen, unsigned int window_flags, double device_scale);

    bool OnMouseEvent(const ul::MouseEvent &evt) override;
    // see ultralight docs

    bool OnKeyEvent(const ul::KeyEvent &evt) override;
    // see ultralight docs

    bool OnScrollEvent(const ul::ScrollEvent &evt) override;
    // see ultralight docs

    void OnResize(ul::Window *window, uint32_t width_px, uint32_t height_px) override;
    // see ultralight docs

    void OnClose(ul::Window *window) override;
    // see ultralight docs

    /// Running app
    void Run() const;

    /// This is a JS callback function that is needed to notify the server that the server is being accessed via
    /// ultralight
    /// \param thisObject see ultralight docs
    /// \param args see ultralight docs
    /// \return "true" in JSValue
    ul::JSValue MakeServerAvailable(const ul::JSObject &thisObject, const ul::JSArgs &args);


    void OnDOMReady(ul::View *caller,
                    uint64_t frame_id,
                    bool is_main_frame,
                    const ul::String &url) override;
    // see ultralight docs

    void OnChangeTitle(ul::View *caller, const ul::String &title) override;
    // see ultralight docs

    /// Starting the server if it is not running
    static void RunServer();

    /// Stopping server and whole program
    [[noreturn]] static void StopServer();
};
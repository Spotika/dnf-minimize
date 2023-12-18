#pragma once

#include "Engine/BaseApp.h"

namespace ul = ultralight;

class MainApp : public BaseApp {
public:
    MainApp();

    void OnDOMReady(ul::View *caller, uint64_t frame_id, bool is_main_frame, const ul::String &url) override;

    /// Function for an example of binding to JS
    ul::JSValue ExampleMessage(const ul::JSObject &thisObject, const ul::JSArgs &args);
};
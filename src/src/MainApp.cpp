#include "../MainApp.h"

using namespace ultralight;

MainApp::MainApp() : BaseApp(1000, 1000, false, 0, 1.5) {}


void MainApp::OnDOMReady(ul::View *caller, uint64_t frame_id, bool is_main_frame, const ul::String &url) {
    ul::RefPtr<ul::JSContext> context = caller->LockJSContext();
    ul::SetJSContext(context->ctx());

    ///
    /// Get the global object (this would be the "window" object in JS)
    ///
    ul::JSObject global = ul::JSGlobalObject();


    ///
    /// Binding functions
    ///
    global["cppExampleMessage"] = BindJSCallbackWithRetval(&MainApp::ExampleMessage);
    global["cppIsBrowserAllowed"] = BindJSCallbackWithRetval(&BaseApp::MakeServerAvailable); // This function allows the application to load
}

ul::JSValue MainApp::ExampleMessage(const ul::JSObject &thisObject, const ul::JSArgs &args) {
    return ul::JSString("You are in ultralight!");
}
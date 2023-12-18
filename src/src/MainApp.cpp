#include "../MainApp.h"

using namespace ultralight;

MainApp::MainApp() : BaseApp(WIDTH,
                             HEIGHT,
                             FULL_SCREEN,
                             kWindowFlags_Titled | // TODO: set your custom flags. See ultralight docs
                             kWindowFlags_Resizable |
                             kWindowFlags_Maximizable,
                             DEVICE_SCALE) {}


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
    global["cppExampleMessage"] = BindJSCallbackWithRetval(&MainApp::ExampleMessage); // this for example page
    // TODO:
    //  delete if you don`t use example page

    global["cppIsBrowserAllowed"] = BindJSCallbackWithRetval(
            &BaseApp::MakeServerAvailable); // This function allows the application to load
}

// TODO: delete if you don`t use example page
ul::JSValue MainApp::ExampleMessage(const ul::JSObject &thisObject, const ul::JSArgs &args) {
    return ul::JSString("You are in ultralight!");
}
function cppIsBrowserAllowed() {
    return "true"; // TODO: change to "false" if you want to run app only from ultralight
}


function checkBrowserView(evt) {
    // If the function cppIsBrowserAllowed returns false, the page will not load.
    // cppIsBrowserAllowed - is JS bind,
    // This function can be overloaded in c++ and return true, even if its JS version returns false.
    if (cppIsBrowserAllowed() === "false") {
        const rootElement = document.getElementById("root");
        const newText = document.createTextNode('Browser not allowed');
        if (rootElement) {
            rootElement.parentNode.replaceChild(newText, rootElement);
        }
    }
}

/*
This is an example of functions that are bound to C++
You need write interfaces for overloading functions.
 */
function cppExampleMessage() {
    return "You are in browser!";
}

function exampleMessage() {
    return cppExampleMessage();
}
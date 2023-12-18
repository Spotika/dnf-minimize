function cppIsBrowserAllowed() {
    return "true"; // change to "false" if you want to run app only from ultralight
}


function checkBrowserView(evt) {
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
 */
function cppExampleMessage() {
    return "You are in browser!";
}

function exampleMessage() {
    return cppExampleMessage();
}
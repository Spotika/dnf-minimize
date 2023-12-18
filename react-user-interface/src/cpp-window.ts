
declare global {
    interface Window { // TODO: add here signature of functions which used from cpp_functions.js
        exampleMessage(): string;
        checkBrowserView(): void;
    }
}

export default {};

declare global {
    interface Window {
        exampleMessage(): string;
        checkBrowserView(): void;
    }
}

export default {};
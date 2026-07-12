console.log("🚀 DSA Sync Loaded");

chrome.runtime.onMessage.addListener((request, sender, sendResponse) => {

    console.log("Request:", request);

    console.log("window.monaco =", window.monaco);

    sendResponse({
        code: "hello"
    });

    return true;
});
console.log("🚀 DSA Sync Loaded");

// --------------------------------------------------
// Inject page.js into the page context
// --------------------------------------------------
const script = document.createElement("script");

script.src = chrome.runtime.getURL("page_bridge.js");

script.onload = () => script.remove();

(document.head || document.documentElement).appendChild(script);

// --------------------------------------------------
// Receive Monaco code from page.js
// --------------------------------------------------

let latestCode = null;

window.addEventListener("message", (event) => {

    if (event.source !== window) return;

    if (event.data.type === "MONACO_CODE") {

        latestCode = event.data.code;

    }

});

// --------------------------------------------------
// Listen for popup requests
// --------------------------------------------------




chrome.runtime.onMessage.addListener((request, sender, sendResponse) => {

    if (request.type !== "GET_PAGE_DATA")
        return;

    function handler(event) {

        if (event.data?.type !== "DSA_CODE")
            return;

        window.removeEventListener("message", handler);

        sendResponse({

            title: document.title,

            code: event.data.code

        });

    }

    window.addEventListener("message", handler);

    window.postMessage({

        type: "GET_DSA_CODE"

    }, "*");

    return true;

});
console.log("🚀 DSA Sync Loaded");

// --------------------------------------------------
// Inject page.js into the page context
// --------------------------------------------------

const script = document.createElement("script");

script.src = chrome.runtime.getURL("page.js");

script.onload = function () {

    this.remove();

};

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

    if (request.type === "GET_PAGE_DATA") {

        // Ask page.js to fetch latest code

        window.postMessage({

            type: "GET_MONACO_CODE"

        });

        // Give page.js a tiny moment to respond

        setTimeout(() => {

            sendResponse({

                title: document.title,

                code: latestCode

            });

        }, 100);

        return true;
    }

});
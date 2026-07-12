console.log("🚀 DSA Sync Loaded");

// Listen for messages from the popup
chrome.runtime.onMessage.addListener((request, sender, sendResponse) => {

    if (request.type === "GET_PROBLEM_INFO") {

        // Get the page title
        const title = document.title;

        sendResponse({
            title: title
        });
    }

});
// Runs inside the page's JavaScript context

window.addEventListener("message", (event) => {

    if (event.source !== window) return;

    if (event.data.type !== "GET_MONACO_CODE") return;

    let code = null;

    try {

        code = window.monaco
            .editor
            .getEditors()[0]
            .getValue();

    } catch (e) {

        code = null;

    }

    window.postMessage({

        type: "MONACO_CODE",

        code: code

    });

});
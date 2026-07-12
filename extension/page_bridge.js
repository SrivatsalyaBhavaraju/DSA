(function () {

    window.addEventListener("message", (event) => {

        if (event.source !== window) return;

        if (event.data?.type !== "GET_DSA_CODE") return;

        let code = null;

        try {

            code = window.monaco
                ?.editor
                ?.getEditors()?.[0]
                ?.getValue();

        } catch (e) {}

        window.postMessage({

            type: "DSA_CODE",

            code: code

        }, "*");

    });

})();
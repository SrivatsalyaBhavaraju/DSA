// ------------------------------
// Load current problem title
// ------------------------------

let currentTab = null;

chrome.tabs.query({ active: true, currentWindow: true }, (tabs) => {

    currentTab = tabs[0];

    const url = currentTab.url;

    const slug = url
        .split("/problems/")[1]
        .split("/")[0];

    const problemTitle = slug
        .split("-")
        .map(word => word.charAt(0).toUpperCase() + word.slice(1))
        .join(" ");

    document.getElementById("problem").textContent = problemTitle;

});

// ------------------------------
// Approach Buttons
// ------------------------------

const buttons = document.querySelectorAll(".approach");

buttons.forEach(button => {

    button.addEventListener("click", () => {

        buttons.forEach(btn =>
            btn.classList.remove("active")
        );

        button.classList.add("active");

    });

});

// ------------------------------
// Save Button
// ------------------------------

document.getElementById("save").addEventListener("click", async () => {

    const problemNumber =
        document.getElementById("problemNumber").value;

    if(problemNumber === ""){

        alert("Please enter the problem number.");

        return;

    }

    const problemTitle =
        document.getElementById("problem").textContent;

    const category =
        document.getElementById("category").value;

    const pattern =
        document.getElementById("pattern").value;

    const approach =
        document.querySelector(".approach.active").textContent.trim();

    // ---------------------------------------
    // Read code directly from Monaco editor
    // ---------------------------------------

    const codeResult = await chrome.scripting.executeScript({

        target: {

            tabId: currentTab.id

        },

        func: () => {

            return typeof window.monaco;

        }

    });

    console.log(codeResult);

const code = codeResult[0].result;

console.log(code);

    const submission = {

        problem_number: Number(problemNumber),

        problem_title: problemTitle,

        category: category,

        pattern: pattern,

        approach: approach,

        language: "cpp",

        code: code

    };

    try{
        console.log(submission);
        const response = await fetch(

            "http://127.0.0.1:8000/submit",

            {

                method:"POST",

                headers:{
                    "Content-Type":"application/json"
                },

                body:JSON.stringify(submission)

            }

        );

       if (!response.ok) {

    const error = await response.text();

    console.log(error);

    alert(error);

    return;

}

        const result = await response.json();

        console.log(result);

        alert("✅ Saved to GitHub!");

    }

    catch(error){

        console.error(error);

        alert(error.message);

    }

});
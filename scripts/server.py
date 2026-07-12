from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from git_manager import GitManager
from models import Submission
from file_manager import FileManager

app = FastAPI(
    title="DSA Automation API",
    version="1.0"
)

# Allow requests from the Chrome extension
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

@app.get("/")
def home():
    return {
        "status": "running"
    }

@app.post("/submit")
def submit_solution(data: Submission):

    saved_file = FileManager.save_solution(data)

    commit_message = GitManager.commit_and_push(
        saved_file,
        data
    )

    print(
        f"✅ Saved #{data.problem_number} - "
        f"{data.problem_title} "
        f"({data.approach})"
    )

    return {
        "success": True,
        "saved_to": str(saved_file),
        "commit": commit_message
    }
from git import Repo
from pathlib import Path


class GitManager:

    @staticmethod
    def commit_and_push(filepath, submission):
        """
        Adds, commits and pushes the latest solution.
        """

        # Find the repository root (DSA/)
        repo_path = Path(__file__).resolve().parent.parent

        repo = Repo(repo_path)

        # Stage everything
        repo.git.add(A=True)

        # Create commit message
        commit_message = (
            f"✨ Added {submission.approach} solution for "
            f"{submission.problem_number} - {submission.problem_title}"
        )

        # Commit
        repo.index.commit(commit_message)

        # Push to GitHub
        origin = repo.remote(name="origin")
        origin.push()

        return commit_message
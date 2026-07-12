from pathlib import Path

# DSA/
PROJECT_ROOT = Path(__file__).resolve().parent.parent

# DSA/solutions/
SOLUTIONS_DIR = PROJECT_ROOT / "solutions"

LANGUAGE_EXTENSIONS = {
    "cpp": ".cpp",
    "python": ".py",
    "java": ".java",
    "javascript": ".js",
    "typescript": ".ts",
}
APPROACH_MAP = {
    "Brute Force": "01_brute_force",
    "Better": "02_better",
    "Optimal": "03_optimal",
}
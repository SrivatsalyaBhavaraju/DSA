from pathlib import Path
from constants import SOLUTIONS_DIR, LANGUAGE_EXTENSIONS


class FileManager:

    @staticmethod
    def save_solution(data):

        pattern_folder = SOLUTIONS_DIR / data.pattern

        problem_folder = (
            pattern_folder /
            f"{data.problem_number}_{data.problem_title}"
        )

        problem_folder.mkdir(parents=True, exist_ok=True)

        approach_map = {
            "Brute Force": "01_brute_force",
            "Better": "02_better",
            "Optimal": "03_optimal",
        }

        filename = approach_map[data.approach]

        extension = LANGUAGE_EXTENSIONS[data.language]

        filepath = problem_folder / f"{filename}{extension}"

        filepath.write_text(
            data.code,
            encoding="utf-8"
        )

        return filepath
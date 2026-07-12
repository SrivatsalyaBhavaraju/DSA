from pathlib import Path

from constants import SOLUTIONS_DIR, LANGUAGE_EXTENSIONS


class FileManager:

    @staticmethod
    def save_solution(data):
        """
        Saves a LeetCode solution inside:

        solutions/
            Category/
                Pattern/
                    Problem/
                        Approach.cpp
        """

        # ----------------------------
        # Create Folder Structure
        # ----------------------------

        category_folder = SOLUTIONS_DIR / data.category

        pattern_folder = category_folder / data.pattern

        problem_folder = (
            pattern_folder /
            f"{data.problem_number} - {data.problem_title}"
        )

        # Automatically create folders if they don't exist
        problem_folder.mkdir(
            parents=True,
            exist_ok=True
        )

        # ----------------------------
        # Decide filename
        # ----------------------------

        approach_map = {
            "Brute Force": "01_brute_force",
            "Better": "02_better",
            "Optimal": "03_optimal",
        }

        filename = approach_map[data.approach]

        # ----------------------------
        # Decide extension
        # ----------------------------

        extension = LANGUAGE_EXTENSIONS[data.language]

        filepath = problem_folder / f"{filename}{extension}"

        # ----------------------------
        # Save code
        # ----------------------------

        filepath.write_text(
            data.code,
            encoding="utf-8"
        )

        return filepath
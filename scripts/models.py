from pydantic import BaseModel


class Submission(BaseModel):
    problem_number: int
    problem_title: str

    category: str
    pattern: str

    approach: str

    language: str

    code: str
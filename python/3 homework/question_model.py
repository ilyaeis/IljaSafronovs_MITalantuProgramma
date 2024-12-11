from typing import List

class Question:
    def __init__(self, text: str, answer: str, wrong_answer: List[str] = None, type: str = "boolean"):
        self.text = text
        self.answer = answer
        self.wrong_answer = wrong_answer
        self.type = type

    def __str__(self) -> str:
        return f"{self.text}: {self.answer}"
        
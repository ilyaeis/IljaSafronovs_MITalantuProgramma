import requests
import json
from typing import List
from question_model import Question

PARAMETRS = {
    "amount": 10, 
    "category": 18, 
    "type": "boolean"
    }

class Data:
    def __init__(self, params: dict[str, any]):
        response = requests.get(f"https://opentdb.com/api.php", params)
        response.raise_for_status()

        data = response.json()
        self.question_data = data["results"]
        
    def get_question_list(self) -> List[Question]:
        question_list = []
        for question in self.question_data:
            q_text = question["question"]
            q_answer = question["correct_answer"]
            q_wrong_answer = question["incorrect_answers"]

            new_question = Question(q_text, q_answer, q_wrong_answer)
            question_list.append(new_question)
        return question_list

    def __str__(self) -> str:
        questions_str = ""
        for question in self.question_data:
            questions_str += f"{json.dumps(question, indent=4)}, "
        return questions_str

if __name__ == "__main__":
    # Iegūt datus no API
    d = Data(PARAMETRS)
    # Izdrukāt datus konsolē pārbaudei.
    print(d)
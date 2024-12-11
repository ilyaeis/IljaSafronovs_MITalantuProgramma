import html
from typing import List
from data import Data, PARAMETRS
from question_model import Question

class QuizBrain:
    def __init__(self, q_list: List[Question]):
        self.question_number = 0
        self.score = 0
        self.question_list = q_list

    def next_question(self):
        current_question = self.question_list[self.question_number]
        self.question_number += 1

        q_text = html.unescape(current_question.text)
        user_answer = input(f"{self.question_number}: {q_text} (True / False): ")
        self.process_answer(user_answer, current_question.answer)
    
    def process_answer(self, user_answer: str, correct_answer: str):
        if self.answer_is_correct(user_answer, correct_answer):
            self.score += 1
            print("You got it right!")
        else:
            print("That's wrong!")
            print(f"The correct answer was {correct_answer}.")
        print(f"Your current score is {self.score}! Keep going!")
    
    def answer_is_correct(self, user_answer: str, correct_answer: str) -> bool:
        return user_answer.lower() == correct_answer.lower()
    
    def still_has_questions(self) -> bool:
        return self.question_number < len(self.question_list)

    def __str__(self) -> str:
        question_answer_wanswer = ""
        for question in self.question_list:
            q_text = html.unescape(question.text)
            q_answer = html.unescape(question.answer)
            if question.type == "boolean":
                q_wanswer = html.unescape(question.wrong_answer[0])

            question_answer_wanswer += f"Question '{q_text}' \n\tcorrect answer '{q_answer}' \n\twrong answer '{q_wanswer}' \n"
        return question_answer_wanswer
    
if __name__ == "__main__":
    PARAMETRS["amount"] = 3
    q_data = Data(PARAMETRS)

    quizbrain = QuizBrain(q_data.get_question_list())
    print(quizbrain)

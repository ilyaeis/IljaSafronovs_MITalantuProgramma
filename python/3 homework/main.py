from quiz_brain import QuizBrain
from data import Data, PARAMETRS

q_data = Data(PARAMETRS)

quiz = QuizBrain(q_data.get_question_list())

while quiz.still_has_questions():
    quiz.next_question()

print("Thanks for playing with us!")
print(f"Your score this time was {quiz.score}! Nice number!")
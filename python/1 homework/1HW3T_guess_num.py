import random

new_game = True

print("Welcome to the numver guessing game!")

while (new_game):
    new_game = False
    counter = 0

    start = 1
    end = 100

    print(f"I'm thinking of a number between {start} and {end}.\n")
    num_to_guess = random.randint(start, end)
    print(num_to_guess)

    user_guess = 0
    while user_guess != num_to_guess:
        if counter >= 5:
            if (num_to_guess < end//2):
                print(f"This num is between {start} and {end//2. }", end="")
            else:
                print(f"This num is between {end//2} and {end}. ", end="")

        user_guess = input("Enter your guess: ")

        if not user_guess.isnumeric():
            print("Wrong input. ", end="")
            continue
        user_guess = int(user_guess)
        if user_guess < start or user_guess > end:
            print("Wrong input. ", end="")
            continue

        counter += 1

        if user_guess < num_to_guess:
            print("Too low")
        elif user_guess > num_to_guess:
            print("Too high")
        else:
            print(f"You got it, it took you {counter} tries")

    if input("Do you want to continue (jā/nē): ") == "jā":
        print("\nNice, let's start again. ", end="")
        new_game = True


print("Bye!")
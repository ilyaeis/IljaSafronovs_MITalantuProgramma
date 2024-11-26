favourite_food = set({"Pica", "Suši", "Pasta"})
choice = 0

while (choice != 5):
    print('''Izvēlnes opcijas ir šādas:
    1. opcija – Pievienot vienumu sarakstam: Palūdz lietotājam ievadīt ēdiena nosaukumu un pievieno to sarakstam.
    2. opcija – Noņemt vienumu no saraksta: Parāda sarakstu ar numurētiem vienumiem un ļauj lietotājam noņemt vienumu, izvēloties tā numuru.
    3. opcija – Parādīt saraksta garumu: Parāda, cik vienumu pašlaik ir sarakstā.
    4. opcija – Parādīt saraksta vienumus: Izdrukā visus pašreizējos vienumus sarakstā.
    5. opcija – Beigt programmu: Pārtrauc programmu.''')

    choice = input("Enter your choice (number): ")

    if (choice == "1"):
        favourite_food.add(input("Enter new food please: "))
    elif (choice == "2"):
        if (len(favourite_food) == 0): 
            continue
        food_dict = dict()
        counter = 1
        for f in favourite_food:
            print(f"{counter} : {f}")
            food_dict[counter] = f

            counter += 1
        favourite_food.remove(food_dict[int(input("Enter the food you want to delete (num): "))])
    elif (choice == "3"):
        print(f"length is {len(favourite_food)}")
    elif (choice == "4"):
        print("Your favourite food: ")
        for f in favourite_food:
            print(f, end=" ")
        print()
    elif (choice == "5"):
        break
    else:
        print("Wrong input")
import json 

class FavouriteFood:
    def __init__(self, start_set: set):
        self.favourite_food = start_set
        
    def add_food(self):
        self.favourite_food.add(input("Enter new food please: "))
        print("Added!")
        
    def delete_food(self):
        if (len(self.favourite_food) == 0): 
            print("Nothing to delete!")
            return
        
        user_choice = input("Enter the food you want to delete: ")
        
        if user_choice in self.favourite_food:           
            self.favourite_food.remove(user_choice)
            print("Deleted!")
        else:
            print("No such food in list!")
        
    def search_food(self):
        food_to_search = input("What food are you searching for? ")
        if food_to_search in self.favourite_food: 
            print("We have this food in set")
        else:
            print("No such food exists")
            
    def to_str(self) -> str:
        if (len(self.favourite_food) == 0): 
            return "Nothing to show!"
        output = ""
        for f in self.favourite_food:
            output += f + "; "
        return output
    
    def to_json(self) -> dict:
        output = dict()  
        output["favourite_food"] = list(self.favourite_food)
        return output
    
def print_menu():
    menu_options = [
        "Add an item to the list: Asks the user to input a food name and adds it to the list.",
        "Remove an item from the list: Displays the list with numbered items and allows the user to remove an item by selecting its number.",
        "Show the list length: Displays how many items are currently in the list.",
        "Show the list items: Prints all current items in the list.",
        "Check if an item exists.",
        "Exit the program: Terminates the program."
    ]
    print("\nThe menu options are as follows:")
    for index, option in enumerate(menu_options, 1):
        print(f"{index}. option – {option}")

def read_json(path: str) -> set:
    try:
        with open(path, 'r', encoding='utf-8') as file:
            data = json.load(file)
        return set(data["favourite_food"])
    except:
        return set()

def pre_closing_procedrure(path: str, ff: FavouriteFood):
    while True:
        answer = input("Do you want to save your favourite food to file? (Y/n)")
        if answer == "Y":
            with open(path, 'w', encoding='utf-8') as file:
                json.dump(ff.to_json(), file, ensure_ascii=False, indent=4)
            print("Saved data! Bye!")
            return
        elif answer == "n":
            print("Got it! Bye!")
            return
        else: 
            print("Invalid answer! Try again! (Y/n)")
            
if __name__ == "__main__":
    choice = 0
    ff = FavouriteFood(read_json("data.json"))
    
    while (choice != 5):
        print_menu()
        choice = input("Enter your choice (number): ")

        if (choice == "1"):
            ff.add_food()
        elif (choice == "2"):
            ff.delete_food()
        elif (choice == "3"):
            print(f"Length is {len(ff.favourite_food)}")
        elif (choice == "4"):
            print(ff.to_str())
        elif (choice == "5"):
            ff.search_food()
        elif (choice == "6"):
            pre_closing_procedrure("data.json", ff)
            break
        else:
            print("Wrong input")
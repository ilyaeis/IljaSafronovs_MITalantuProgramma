#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 
#include <sstream>

using namespace std;

enum Color {
    Red = 1, Blue, Green, Black, White
};

struct Car {
    string modelis;
    int gads;
    int nobraukums;
    Color krasa;

	string toString() {
		string color;
		switch (krasa) {
		case Color::Red:
			color = "Red";
			break;
		case Color::Blue:
			color = "Blue";
			break;
		case Color::Green:
			color = "Green";
			break;
		case Color::Black:
			color = "Black";
			break;
		case Color::White:
			color = "White";
			break;
		}

		// format string
		stringstream ss;
		ss << left << setw(15) << modelis
			<< setw(10) << gads
			<< setw(15) << (to_string(nobraukums) + " km")
			<< setw(10) << color;

		return ss.str();
	}
};

int getInt(string prompt, int min, int max) {
    try {
        cout << prompt;
        string input;
        getline(cin, input);
        int num = stoi(input);

        if (num < min || num > max) {
            throw out_of_range("Number out of range");
        }
        return num;
    }
    catch (const invalid_argument& e) {
        cout << "Invalid input. Please enter a number." << endl;
        return getInt(prompt, min, max);
    }
    catch (const out_of_range& e) {
        cout << "Invalid input. Please enter a number within the range." << endl;
        return getInt(prompt, min, max);
    }
}

string getString(string prompt) {
	cout << prompt;
	string model;
	getline(cin, model);
	return model;
}

Color getColor() {
	cout << "Choose a color:" << endl;
	cout << "1. Red" << endl;
	cout << "2. Blue" << endl;
	cout << "3. Green" << endl;
	cout << "4. Black" << endl;
	cout << "5. White" << endl;
	int choice = getInt("Enter your choice: ", 1, 5);
	return static_cast<Color>(choice);
}

void addCar(vector<Car>& cars) {
	Car car;
    car.modelis = getString("Enter car's model: ");
	car.gads = getInt("Enter car year: ", 1900, 2021);
	car.nobraukums = getInt("Enter car mileage: ", 0, 1000000);
	car.krasa = getColor();
	cars.push_back(car);
}

void deleteCar(vector<Car>& cars) {
	if (cars.empty()) {
		cout << "No cars to delete." << endl;
		return;
	}
	cout << "Choose a car to delete:" << endl;
	for (int i = 0; i < cars.size(); i++) {
		cout << i + 1 << ". " << cars[i].toString() << endl;
	}
	int choice = getInt("Enter your choice: ", 1, cars.size());
	cars.erase(cars.begin() + choice - 1);
}

void printAllCars(vector<Car>& cars) {
	if (cars.empty()) {
		cout << "No cars to print." << endl;
		return;
	}
	cout << left << setw(15) << "Model"
		<< setw(10) << "Year"
		<< setw(15) << "Mileage"
		<< setw(10) << "Color" << endl;
	for (int i = 0; i < cars.size(); i++) {
		cout << i + 1 << ". " << cars[i].toString() << endl;
	}
}

void printCarsByColor(vector<Car>& cars) {
	if (cars.empty()) {
		cout << "No cars to print." << endl;
		return;
	}
	Color color = getColor();
	vector<Car> carsByColor;

	for (int i = 0; i < cars.size(); i++) {
		if (cars[i].krasa == color) {
			carsByColor.push_back(cars[i]);
		}
	}

	printAllCars(carsByColor);
}

void printChoiceMenu() {
	cout << "Choose an option:" << endl;
	cout << "1. Add a car" << endl;
	cout << "2. Delete a car" << endl;
	cout << "3. Print all cars" << endl;
	cout << "4. Print cars by color" << endl;
	cout << "5. Exit" << endl;
}

int main() {
	vector<Car> cars{
		{ "Audi", 2000, 100000, Color::Red },
		{ "BMW", 2005, 150000, Color::Blue },
		{ "VW", 2010, 200000, Color::Green }
	};

    int choice = 0;
	while (choice != 5) {
		printChoiceMenu();
		choice = getInt("Enter your choice: ", 1, 5);

        switch (choice) {
        case 1:
			addCar(cars);
            break;
        case 2:
			deleteCar(cars);
            break;
        case 3:
			printAllCars(cars);
            break;
        case 4:
			printCarsByColor(cars);
            break;
        case 5:
            break;
        }
	}
    return 0;
}

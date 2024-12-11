#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for left, right, setw
#include <climits> // for INT_MAX
#include <cfloat> // for DBL_MAX
#include <algorithm> // for sort()
#include <fstream> // for working with files
#include <filesystem> // for accesing saved foods

using namespace std;

string format_str(string str);

struct Food {
    string name;
    double price;
    int available_count;
    int sold_count;

    Food() {}
    Food(string p_name, double p_price, int p_available_count, int p_sold_count){
        name = p_name;
        price = p_price;
        available_count = p_available_count;
        sold_count = p_sold_count;
    }

    void food_print() const {
        cout << left << setw(20) << format_str(name)
            << right << setw(15-4) << price << " EUR"
            << setw(15) << available_count
            << setw(10) << sold_count << endl;
    }
};

void load_data_to_file(Food food) {
    string file_name = "Foods/" + format_str(food.name) + ".food";

    fstream file;
    file.open(file_name, ios_base::binary | ios_base::out | ios_base::trunc);
    file << format_str(food.name) << endl;
    file << food.price << endl;
    file << food.available_count << endl;
    file << food.sold_count << endl;
    file.close();
}
Food read_data_from_file(string file_name) {
    //string file_name = "Foods/"+food_name+".food";

    Food food;
    fstream file;
    file.open(file_name, ios_base::binary | ios_base::in);
    file >> food.name;
    file >> food.price;
    file >> food.available_count;
    file >> food.sold_count;
    file.close();

    return food;
}

string format_str(string str) {
    if (!str.empty()) {
        str[0] = std::toupper(str[0]); 
        for (size_t i = 1; i < str.size(); i++) {
            if (str[i] == ' ') {
                str[i] = '_';
            } else {
                str[i] = std::tolower(str[i]);
            }
        }
    }
    return str;
}

// used to compare 2 strings, because working with files Pizza.food == pIzZa.food
bool strings_are_equal(string str1, string str2) {
    return format_str(str1) == format_str(str2);
}

// Sort food_data by price, in ascending order
vector<Food> get_sorted_by_price(vector<Food> food_data) {
    vector<Food> sorted_by_price_food_data = food_data;

    sort(sorted_by_price_food_data.begin(), sorted_by_price_food_data.end(),
        [](const Food& a, const Food& b) {
            return a.price < b.price;
    });

    return sorted_by_price_food_data;
}
// Sort food_data by sold_count, in ascending order
vector<Food> get_sorted_by_sold_count(vector<Food> food_data) {
    vector<Food> sorted_by_sold_count = food_data;

    sort(sorted_by_sold_count.begin(), sorted_by_sold_count.end(),
        [](const Food& a, const Food& b) {
            return a.sold_count < b.sold_count;
        });

    return sorted_by_sold_count;
}
// Sort food_data by sold_count * price, in ascending order
vector<Food> get_sorted_by_profit(vector<Food> food_data) {
    vector<Food> sorted_by_profit = food_data;

    sort(sorted_by_profit.begin(), sorted_by_profit.end(),
        [](const Food& a, const Food& b) {
            return a.sold_count * a.price < b.sold_count * b.price;
        });

    return sorted_by_profit;
}

// Looks for number if range [start_range, end_range], return start_range-1 in case of wrong input, else return input
int get_int(string output, int start_range, int end_range) {
    cout << output;
    string input;
    try {
        getline(cin, input);
        double num = stoi(input);
        if (num < start_range || num > end_range) {
            throw std::invalid_argument("Wrong range.");
        }
        return num;
    }
    catch (const exception&) {
        cout << "Invalid input! Please enter a valid integer." << endl;
        return start_range - 1;
    }
}
double get_double(string output, double start_range, double end_range) {
    cout << output;
    string input;
    try {
        getline(cin, input);
        double num = stod(input);
        if (num < start_range || num > end_range) {
            throw std::invalid_argument("Wrong range.");
        }
        return num;
    }
    catch (const exception&) {
        cout << "Invalid input! Please enter a valid double." << endl;
        return start_range-1;
    }
}

// Function to print food data 
void print_line() {
    cout << string(60, '-') << endl;
}
void print_table_header() {
    print_line();
    cout << left << setw(20) << "Name"
        << right << setw(15) << "Price(EUR)"
        << setw(15) << "Available"
        << setw(10) << "Sold" << endl;
    print_line();
}

void print_food_data(string name, vector<Food>& food_data){
	bool does_exist = false;
	for (Food f : food_data){
		if (strings_are_equal(f.name, name)){
			does_exist = true;
			print_table_header();
			f.food_print();
			print_line();
			break;
		}
	}
	if (!does_exist){
		cout << '"' << name << "\" does not exist." << endl;
	}
}
void print_food_data_all(vector<Food>& food_data) {
    print_table_header();
    for (Food f : food_data) {
        f.food_print();
    } print_line();
}

// Print the Top 5 most / least traded dishes on the screen 
void print_top5_most_traded(vector<Food>& food_data) {
    vector<Food> sorted_data = get_sorted_by_sold_count(food_data);
    print_table_header();
    for (int i = sorted_data.size() - 1; i > sorted_data.size() - 6 && i >= 0; i--) {
        sorted_data[i].food_print();
    } print_line();
}
void print_top5_least_traded(vector<Food>& food_data) {
    vector<Food> sorted_data = get_sorted_by_sold_count(food_data);
    print_table_header();
    for (int i = 0; i < sorted_data.size() && i < 5; i++) {
        sorted_data[i].food_print();
    } print_line();
}

// Print the Top 5 most / least earned dishes on the screen 
void print_top5_most_profit(vector<Food>& food_data) {
    vector<Food> sorted_data = get_sorted_by_profit(food_data);
    print_table_header();
    for (int i = sorted_data.size() - 1; i > sorted_data.size() - 6 && i >= 0; i--) {
        sorted_data[i].food_print();
    } print_line();
}
void print_top5_least_profit(vector<Food>& food_data) {
    vector<Food> sorted_data = get_sorted_by_profit(food_data);
    print_table_header();
    for (int i = 0; i < sorted_data.size() && i < 5; i++) {
        sorted_data[i].food_print();
    } print_line();
}

// Print the Top 5 most / least expensive dishes on the screen
void print_top5_most_expensive(vector<Food>& food_data) {
    vector<Food> sorted_data = get_sorted_by_price(food_data);
    print_table_header();
    for (int i = sorted_data.size() - 1; i > sorted_data.size() - 6 && i >= 0; i--) {
        sorted_data[i].food_print();
    } print_line();
}
void print_top5_least_expensive(vector<Food>& food_data) {
    vector<Food> sorted_data = get_sorted_by_price(food_data);
    print_table_header();
    for (int i = 0; i < sorted_data.size() && i < 5; i++) {
        sorted_data[i].food_print();
    } print_line();
}

// Updates the food data by adding quantity to existing items or adding a new food item if it doesn't exist.
void update_food_data(vector<Food>& food_data) {
    string name;
    cout << "Enter the name for the food: ";  getline(cin, name);

    bool exists = false;
    for (Food& f : food_data) {
        if (strings_are_equal(f.name, name)) {
            int available_count = get_int("Given food exists! Enter the amount to add: ", 0, INT_MAX);
            if (available_count < 0) {
                return;
            }
            f.available_count += available_count;
            exists = true;
            load_data_to_file(f);
        }
    }

    if (!exists) {
        double price = get_double("Enter price for new food: ", 0.01, DBL_MAX) * 100 / 100;
        if (price < 0.01) {
            return;
        }
        int available_count = get_int("Enter available count for new food: ", 0, INT_MAX);
        if (available_count < 0) {
            return;
        }
        int sold_count = get_int("Enter count of what already was sold: ", 0, INT_MAX);
        if (sold_count < 0) {
            return;
        }
        Food new_food(name, price, available_count, sold_count);
        food_data.push_back(new_food);
		load_data_to_file(new_food);
    }
}

void sell_food(string name, vector<Food> &food_data){
	bool does_exist = false;
	for (Food &f : food_data){
		if (strings_are_equal(f.name, name)){
			does_exist = true;
			if (f.available_count > 0){
				f.available_count -= 1;
				f.sold_count += 1;
				load_data_to_file(f);
			} else {
				cout << "Out of " << name << "!" << endl;
			}
            cout << '1 "' << f.name << "\" was sold." << endl;
			break;
		}
	}
	if (!does_exist){
		cout << '"' << name << "\" does not exist." << endl;
	}
}

// works only on cpp 17 version or newer
vector<Food> get_all_food_data(string folder_path) {
    vector<Food> food_data;
    for (const auto& entry : filesystem::directory_iterator(folder_path)) {
        string file_path = entry.path().string();
        Food food = read_data_from_file(file_path);
        food_data.push_back(food);
    }
    return food_data;
}

int main() {
    string file_path = "./Foods";
    vector<Food> food_data = get_all_food_data(file_path);
    
	enum func_menu {
		add_food = 1, 
		show_food_all,
		show_food,
		food_sell,
		top_most_sell,
		top_least_sell,
		top_most_profit,
		top_least_profit,
		top_most_expence,
		top_least_expence,
		end_task
	};
	cout << "Available options: " << endl
		 << " 1 - add / update food" << endl
		 << " 2 - show all foods" << endl
		 << " 3 - show food by name" << endl
		 << " 4 - sell food" << endl
		 << " 5 - show top5 most traded foods" << endl
		 << " 6 - show top5 least traded foods" << endl
		 << " 7 - show top5 most profitable foods" << endl
		 << " 8 - show top5 least profitable foods" << endl
		 << " 9 - show top5 most expensive foods" << endl
		 << "10 - show top5 least expensive foods" << endl
		 << "11 - end program" << endl << endl;

	int action = 0;
	string input_food;
	while (true){
		//Get the action
		while (action==0){
			action = get_int("Choose an option: ", 1, end_task);
		}

		//Do the action
		switch (action)
		{
		case add_food:
			update_food_data(food_data);
			break;
		case show_food_all:
			print_food_data_all(food_data);
			break;
		case show_food:
			cout << "Enter a food to show: ";
            getline(cin, input_food);
			print_food_data(input_food, food_data);
			break;
		case food_sell:
			cout << "Enter a food to sell: ";
            getline(cin, input_food);
			sell_food(input_food, food_data);
			break;
		case top_most_sell:
			print_top5_most_traded(food_data);
			break;
		case top_least_sell:
			print_top5_least_traded(food_data);
			break;
		case top_most_profit:
			print_top5_most_profit(food_data);
			break;
		case top_least_profit:
			print_top5_least_profit(food_data);
			break;
		case top_most_expence:
			print_top5_most_expensive(food_data);
			break;
		case top_least_expence:
			print_top5_least_expensive(food_data);
			break;
		}

		//Do all over again
		if (action==end_task){
			break;
		}
		action = 0;
		cout << endl;
	}
	
    return 0;
}
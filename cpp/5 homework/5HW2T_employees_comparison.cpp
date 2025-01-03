#include <iostream>
#include <string>
using namespace std;

struct Employee {
	string name;
	float salary;
};

Employee findHigherPaidEmpl(const Employee& emp1, const Employee& emp2) {
	if (emp1.salary > emp2.salary) {
		return  emp1;
	}
	else {
		return emp2;
	}
}

int main() {
	Employee emp1 = { "A", 5000.00 };
	Employee emp2 = { "B", 4000.00 };

	Employee higherPaidEmpl = findHigherPaidEmpl(emp1, emp2);
	cout << "Employee with higher salary: " << higherPaidEmpl.name << " with salary " << higherPaidEmpl.salary << endl;

	return 0;
}


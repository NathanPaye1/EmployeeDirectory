#include "employee.h"
#include <limits>
#include <iomanip>
#include <iostream>

using namespace std;

//validation
int getNumber(const string& prompt)
{
	int number;
	while(true)
	{
		cout << prompt;
		if(cin >> number && number > 0)
		{
			//if valid, clear stream and return number
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return number;
		}
		cout << "Please Enter a Valid Positive Number\n";

		if(cin.eof())
		{
			throw runtime_error("Input Stream Closed");
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

int getMenuChoice()
{
	cout << "\nEMPLOYEE DIRECTORY\n\n";
	cout << "1. Display All Employees\n";
	cout << "2. Search By Employee ID\n";
	cout << "3. Add Employee\n";
	cout << "4. Update Employee\n";
	cout << "5. Remove Employee\n";
	cout << "6. Exit\n\n";

	int choice;
	while(true)
	{
		choice = getNumber("Choice: ");
		if(choice >= 1 && choice <= 6)
		{
			return choice;
		}

		cout << "Please Choose a valid Option 1 - 6\n";
	}
}

string getRequiredText(const string& prompt)
{
	string text;
	
	while (true)
	{
		cout << prompt;

		if(!getline(cin, text))
		{
			throw runtime_error("Input Stream Closed\n");
		}

		if(text.find_first_not_of(" \t") != string::npos)
		{
			return text;
		}

		cout << "This Field Cannot be Empty\n";
	}
}

//display and search
void displayAll(const map<int, Employee>& employees)
{
	cout << "\nEmployee Directory\n\n";

	if(employees.empty())
	{
		cout << "No Employees Found\n";
		return;
	}

	int length = 25;

	cout << left << setw(5) << "ID" << setw(length) << "Name" <<
	setw(length) << "Department" << "Email\n\n";

	for(const auto& employee : employees)
	{
        	cout << left << setw(5) << employee.first << setw(length) << employee.second.name <<
	        setw(length) << employee.second.department << employee.second.email << "\n";
	}
}
void searchEmployee(const map<int, Employee>& employees)
{
	int id = getNumber("Enter employee ID: ");
	auto it = employees.find(id);

	if(it == employees.end())
	{
		cout << "Employee Not Found\n";
		return;
	}

	cout << "\nEmployee Found:\n";
	cout << "ID: " << it->first << endl;
	cout << "Name: " << it->second.name << endl;
	cout << "Department: " << it->second.department << endl;
	cout << "Email: " << it->second.email << endl;
}

//edit employee map
void addEmployee(map<int, Employee>& employees)
{
        int id = getNumber("Enter New Employee ID: ");

        if(employees.contains(id))
        {
		cout << "Employee " << id << " Already Exists\n";
		return;
        }

        Employee emp;

        emp.name = getRequiredText("Enter Employee Name: ");
        emp.department = getRequiredText("Enter Employee Department: ");
        emp.email = getRequiredText("Enter Employee Email: ");

        employees.insert({id, emp});
        cout << "Employee Added Successfully\n";

}
void updateEmployee(map<int, Employee>& employees)
{
        int id = getNumber("Enter Employee ID to Update: ");

        if(!employees.contains(id))
        {
                cout << "Employee " << id << " Not Found\n";
                return;
        }

	cout << "\nCurrent Employee: " << employees.at(id).name;
	cout << "\nCurrent Department: " << employees.at(id).department;
	cout << "\nCurrent Email: " << employees.at(id).email << "\n\n";

	employees.at(id).department = getRequiredText("Enter New Department: ");
	employees.at(id).email = getRequiredText("Enter New Email: ");

	cout << "Employee Updated Successfully\n";
}
void removeEmployee(map<int, Employee>& employees)
{
	int id = getNumber("Enter Employee ID to Remove: ");
	int removed = employees.erase(id);

	if(removed > 0)
	{
		cout << "Employee Removed Successfully\n";
	}
	else
	{
		cout << "Employee Not Found\n";
	}
}

#include <iostream>
#include <stdexcept>
#include "employee.h"

using namespace std;

int main()
{
	map<int, Employee> employees {
		{1007, {"Nathan Paye", "IT", "nathanpaye1@outlook.com"}},
		{1000, {"Mr Boss", "HR", "mrboss@outlook.com"}},
		{1004, {"Jim Bo", "MK", "jimbo@outlook.com"}},
		{1003, {"Gerard Geraldson", "AC", "gerardgeraldson@outlook.com"}}
	};

	try
	{
		int choice = 1;
		while(choice != 6)
		{
			choice = getMenuChoice();
			switch(choice)
			{
				case 1:
					displayAll(employees);
					break;
				case 2:
					searchEmployee(employees);
					break;
				case 3:
					addEmployee(employees);
					break;
				case 4:
					updateEmployee(employees);
					break;
				case 5:
					removeEmployee(employees);
					break;
				case 6:
					cout << "Goodbye\n\n";
					break;
			}
		}
	}
	catch (const runtime_error& e)
	{
		cout << "Error: " << e.what() << endl;
	}
}

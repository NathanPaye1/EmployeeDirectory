#pragma once
#ifndef PAYE_EMPLOYEE_H
#define PAYE_EMPLOYEE_H

#include <string>
#include <map>

struct Employee
{
	std::string name;
	std::string department;
	std::string email;
};

//validation
int getNumber(const std::string& prompt);
int getMenuChoice();
std::string getRequiredText(const std::string& prompt);

//display amd search
void displayAll(const std::map<int, Employee>& employees);
void searchEmployee(const std::map<int, Employee>& employees);

//edit employee map
void addEmployee(std::map<int, Employee>& employees);
void updateEmployee(std::map<int, Employee>& employees);
void removeEmployee(std::map<int, Employee>& employees);

#endif

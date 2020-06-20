#include <iostream>
#include "Employees.h"
#include "Interface.h"

using namespace std;

Employee::Employee(int id, string name, int worktime){
	this->id = id;
	this->name = name;
	this->worktime = worktime;
}

void Employee::setPayment(int payment){
	this->payment = payment;
}

int Employee::getId(){
	return id;
}

string Employee::getName(){
	return name;
}

int Employee::getPayment(){
	return payment;
}

string Employee::getPosition(){
	return position;
}

/*int Employee::calculatePayment(){
	if (getPosition() == "cleaner" || getPosition() == "driver")
		setPayment(calculatePaymentByWorkTime(worktime, base));
	if (getPosition() == "programmer" || getPosition() == "tester")
		setPayment(calculatePaymentByWorkTimeAndBonus());
	if (getPosition() == "teamleader")
		setPayment(empcalculatePaymentByAll());
	if (getPosition() == "manager")
		setPayment(calculatePaymentByBonus());
	if (getPosition() == "projectmanager" || getPosition() == "seniormanager")
		setPayment(calculatePaymentByBonusAndHeading());
}*/

Personal::Personal(int id, string name, int base, string position, int worktime) : Employee(id, name, worktime){
	this->base = base;
	this->position = position;
}

void Personal::calculatePayment(){
	setPayment(worktime*base);
}

Engineer::Engineer(int id, string name, int base, string position, int project_bonus, int worktime) : Employee(id, name, worktime){
	this->base = base;
	this->position = position;
	this->project_bonus = project_bonus;
}

void Engineer::calculatePayment(){
	setPayment((worktime*base) + project_bonus);
}

Manager::Manager(int id, string name, string position, int project_bonus, int worktime) : Employee(id, name, worktime){
	this->position = position;
	this->project_bonus = project_bonus;
}

void Manager::calculatePayment(){
	setPayment(project_bonus);
}

Cleaner::Cleaner(int id, string name, int base, string position, int worktime) : Personal(id, name, base, position, worktime) {};

Driver::Driver(int id, string name, int base, string position, int worktime) : Personal(id, name, base, position, worktime) {};

Programmer::Programmer(int id, string name, int base, string position, int project_bonus, int worktime) : Engineer(id, name, base, position, project_bonus, worktime) {};

Tester::Tester(int id, string name, int base, string position, int project_bonus, int worktime) : Engineer(id, name, base, position, project_bonus, worktime) {};

TeamLeader::TeamLeader(int id, string name, int base, string position, int project_bonus, int emps, int emp_base, int worktime) : Programmer(id, name, base, position, project_bonus, worktime){
	this->emps = emps;
	this->emp_base = emp_base;
}

void TeamLeader::calculatePayment(){
	setPayment((worktime*base) + project_bonus + (emps*emp_base));
}

ProjectManager::ProjectManager(int id, string name, string position, int project_bonus, int emps, int emp_base, int worktime) : Manager(id, name, position, project_bonus, worktime){
	this->emps = emps;
	this->emp_base = emp_base;
}

void ProjectManager::calculatePayment(){
	setPayment(project_bonus + (emps*emp_base));
}

SeniorManager::SeniorManager(int id, string name, string position, int project_bonus, int emps, int emp_base, int worktime) : ProjectManager(id, name, position, project_bonus, emps, emp_base, worktime) {};

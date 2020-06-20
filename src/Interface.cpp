#include "Employees.h"
#include "Interface.h"
#include <iostream>

using namespace std;

int WorkTime::calculatePaymentByWorkTime(int worktime, int base){
	return (worktime*base);
};

int Project::calculatePaymentByBonus(int bonus){
	return bonus;
}

int Heading::calculatePaymentByHeading(int emps, int emp_base){
	return (emps*emp_base);
}
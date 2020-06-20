#pragma once

#include <iostream>

using namespace std;

class WorkTime{
	public:
		int calculatePaymentByWorkTime(int worktime, int base);
};

class Project{
	public:
		int calculatePaymentByBonus(int bonus);
};

class Heading{
	public:
		int calculatePaymentByHeading(int emps, int emp_base);
};
#include "Interface.h"
#include "Employees.h"
#include "Creating.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

vector<string> split(const string& str){
	vector<string> data;
	string a;
	istringstream line(str);
	while (getline(line, a, '/'))
		data.push_back(a);
	return data;
}

int main(){
	vector<Employee*> staff;
	char buf[10000];
	Creator creator = Creator();
	ifstream staff_list("st.txt");
	cout << staff_list.is_open() << endl;
	while (!staff_list.eof()){
		string line;
		getline(staff_list, line);
		vector<string> data = split(line);
		staff.push_back(creator.createEmployee(data));
	}
	for (auto emp : staff){
		/*if (emp->getPosition() == "cleaner" || emp->getPosition() == "driver")
			emp->setPayment(emp->calculatePaymentByWorkTime());
		if (emp->getPosition() == "programmer" || emp->getPosition() == "tester")
			emp->setPayment(emp->calculatePaymentByWorkTimeAndBonus());
		if (emp->getPosition() == "teamleader")
			emp->setPayment(emp->calculatePaymentByAll());
		if (emp->getPosition() == "manager")
			emp->setPayment(emp->calculatePaymentByBonus());
		if (emp->getPosition() == "projectmanager" || emp->getPosition() == "seniormanager")
			emp->setPayment(emp->calculatePaymentByBonusAndHeading());*/
		emp->calculatePayment();
		cout << "id: " << emp->getId() << endl;
		cout << "name: " << emp->getName() << endl;
		cout << "payment: " << emp->getPayment() << endl;
	}
}
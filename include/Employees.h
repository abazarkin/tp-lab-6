#pragma once

#include <iostream>
#include <vector>
#include "Interface.h"

using namespace std;

class Employee{
	private:
		int id;
		string name;
		int payment;
	protected:
		int worktime;
		string position;
	public:
		Employee(int id, string name, int worktime);
		void setPayment(int payment);
		int getId();
		string getName();
		int getPayment();
		string getPosition();
		virtual void calculatePayment() = 0;
};

class Personal : public Employee, public WorkTime{
	protected:
		int base;
	public:
		Personal(int id, string name, int base, string position, int worktime);
		string getPosition();
		void calculatePayment() override;
};

class Engineer : public Employee, public WorkTime, public Project{
	protected:
		int base;
		int project_bonus;
	public:
		Engineer(int id, string name, int base, string position, int project_bonus, int worktime);
		string getPosition();
		void calculatePayment() override;
};

class Manager : public Employee, public Project{
	protected:
		int project_bonus;
	public:
		Manager(int id, string name, string position, int project_bonus, int worktime);
		string getPosition();
		void calculatePayment() override;
};

class Cleaner : public Personal{
	public:
		Cleaner(int id, string name, int base, string position, int worktime);
};

class Driver : public Personal{
	public:
		Driver(int id, string name, int base, string position, int worktime);
};

class Programmer : public Engineer{
	public:
		Programmer(int id, string name, int base, string position, int project_bonus, int worktime);
};

class Tester : public Engineer{
	public:
		Tester(int id, string name, int base, string position, int project_bonus, int worktime);
};

class TeamLeader : public Programmer, public Heading{
	private:
		int emps;
		int emp_base;
	public:
		TeamLeader(int id, string name, int base, string position, int project_bonus, int emps, int emp_base, int worktime);
		void calculatePayment() override;
};

class ProjectManager : public Manager, public Heading{
	private:
		int emps;
		int emp_base;
	public:
		ProjectManager(int id, string name, string position, int project_bonus, int emps, int emp_base, int worktime);
		void calculatePayment() override;
};

class SeniorManager : public ProjectManager{
	public:
		SeniorManager(int id, string name, string position, int project_bonus, int emps, int emp_base, int worktime);
};
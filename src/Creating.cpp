#include "Creating.h"
#include <stdlib.h>

using namespace std;

Creator::Creator() {};

Employee* Creator::createEmployee(vector<string> data){
	if (data[2] == "cleaner")
		return new Cleaner(stoi(data[0]), data[1], stoi(data[3]), data[2], stoi(data[4]));
	if (data[2] == "driver")
		return new Driver(stoi(data[0]), data[1], stoi(data[3]), data[2], stoi(data[4]));
	if (data[2] == "programmer")
		return new Programmer(stoi(data[0]), data[1], stoi(data[3]), data[2], stoi(data[5]), stoi(data[4]));
	if (data[2] == "tester")
		return new Tester(stoi(data[0]), data[1], stoi(data[3]), data[2], stoi(data[5]), stoi(data[4]));
	if (data[2] == "teamleader")
		return new TeamLeader(stoi(data[0]), data[1], stoi(data[3]), data[2], stoi(data[5]), stoi(data[6]), stoi(data[7]), stoi(data[4]));
	if (data[2] == "manager")
		return new Manager(stoi(data[0]), data[1], data[2], stoi(data[4]), stoi(data[3]));
	if (data[2] == "projectmanager")
		return new ProjectManager(stoi(data[0]), data[1], data[2], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[3]));
	if (data[2] == "seniormanager")
		return new SeniorManager(stoi(data[0]), data[1], data[2], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[3]));
}
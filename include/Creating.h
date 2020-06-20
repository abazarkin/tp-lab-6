#include "Interface.h"
#include "Employees.h"
#include <vector>
#include <string>

class Creator{
	public:
		Creator();
		Employee* createEmployee(vector<string> data);
};
#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Task.h"

class Organizer
{
public:
	std::list<Task> tasks;

	void PrintTasks()
	{
		std::cout << std::setw(4) << "ID " << std::left << std::setw(28) << " Details\t" << std::setw(7) << "State" << std::endl;
		for (auto item : tasks)
		{
			std::cout << item << std::endl;
		}
	}

private:

};


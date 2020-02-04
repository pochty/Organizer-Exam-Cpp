#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Task.h"

class Organizer
{
public:
	std::list<Task> tasks;

	void PrintTasks();

};


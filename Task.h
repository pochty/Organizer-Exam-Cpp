#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Database.h"

class Task
{
public:
	Task(int TaskId, std::string Details, int State = 0) 
		: TaskId (TaskId), Details(Details), State(State) {}

	Task() : Task(0,std::string("NULL"), 0) {}

	Task(std::string Details, int State, Database& db);

	static int Remove(int id, Database& db);
	static int Update(int id, std::string Details, int State, Database& db);

	friend std::ostream& operator<<(std::ostream& os, const Task& obj);

private:
	int TaskId;
	std::string Details;
	int State;
};


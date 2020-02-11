#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Task.h"
#include "Database.h"

class Organizer
{
public:
	Organizer();
	void GetTasks();
	void PrintTasks();
	void AddTask(std::string Details, int State);
	void RemoveTask(int id);
	void UpdateTask(int id, std::string Details, int State);

private:
	Database db;
	std::list<Task> tasks;

	static int GetTaskCallback(void* data, int argc, char** argv, char** colName);
};



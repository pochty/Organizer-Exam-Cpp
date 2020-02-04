#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Task
{
public:
	Task(int TaskId, std::string Details, int State = 0) 
		: TaskId (TaskId), Details(Details), State(State)
	{

	}
	Task() : Task(-1,std::string("NULL"), 0)
	{

	}
	friend std::ostream& operator<<(std::ostream& os, const Task& obj)
	{
		os << std::right << std::setw(3) << obj.TaskId << ". " << std::left << std::setw(30) << obj.Details << std::setw(7) << (obj.State ? "Done" : "Undone");
		
		return os;
	}

private:
	int TaskId;
	std::string Details;
	int State;
};


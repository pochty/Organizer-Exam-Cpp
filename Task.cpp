#include "Task.h"

std::ostream& operator<<(std::ostream& os, const Task& obj)
{
	os << std::right << std::setw(3) << obj.TaskId << ". " << std::left << std::setw(30) << obj.Details << std::setw(7) << (obj.State ? "Done" : "Undone");
	return os;
}
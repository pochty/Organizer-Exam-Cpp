#include "Task.h"

Task::Task(std::string Details, int State, Database& db) : Details(Details), State(State)
{
	std::stringstream stmt;
	stmt << "INSERT INTO Task (Details, State) \
				VALUES ('" << Details << "', '" << State << "');";
	db.Exec(stmt.str().c_str());
	TaskId = db.LastInsertRowid();
}

int Task::Remove(int id, Database& db)
{
	if (id > 0)
	{
		std::stringstream stmt;
		stmt << "DELETE FROM Task \
					WHERE rowid = " << id << ";";
		db.Exec(stmt.str().c_str());
		return 0;
	}
	return 1;
}

int Task::Update(int id, std::string Details, int State, Database& db)
{
	if (id > 0)
	{
		std::stringstream stmt;
		stmt << "UPDATE Task \
					SET Details = '" << Details << "', State = '" << State << "'\
					WHERE rowid = " << id << ";";
		db.Exec(stmt.str().c_str());
		return 0;
	}
	return 1;
}

std::ostream& operator<<(std::ostream& os, const Task& obj)
{
	os << std::right << std::setw(3) << obj.TaskId << ". " << std::left << std::setw(30) 
		<< obj.Details << std::setw(7) << (obj.State ? "Done" : "Undone");
	return os;
}
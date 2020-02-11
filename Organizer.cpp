#include "Organizer.h"

Organizer::Organizer()
{
	try
	{
		db.Init();
		GetTasks();
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what();
	}
}

void Organizer::GetTasks()
{
	tasks.clear();
	db.Exec("SELECT rowid, Details, State FROM Task;", GetTaskCallback, this);
}

void Organizer::PrintTasks()
{
	std::cout << std::setw(4) << "ID " << std::left << std::setw(28) << " Details\t" << std::setw(7) << "State" << std::endl;
	for (auto item : tasks)
	{
		std::cout << item << std::endl;
	}
}

void Organizer::AddTask(std::string Details, int State)
{
	tasks.push_back(Task(Details, State, db));
}

void Organizer::RemoveTask(int id)
{
	Task::Remove(id, db);
}

void Organizer::UpdateTask(int id, std::string Details, int State)
{
	Task::Update(id, Details, State, db);
}

int Organizer::GetTaskCallback(void* data, int argc, char** argv, char** colName)
{
	Organizer* data_ = static_cast<Organizer*>(data);
	data_->tasks.push_back(Task(std::atoi(argv[0]), static_cast<std::string>(argv[1]), std::atoi(argv[2])));
	return 0;
}

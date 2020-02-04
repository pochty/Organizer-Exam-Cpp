#include <iostream>
#include "Task.h"
#include "Organizer.h"
#include "Database.h"
#include "GetUserInput.cpp"

int GetTaskCallback(void* data, int argc, char** argv, char** colName)
{
	Organizer* o = static_cast<Organizer*>(data);
	o->tasks.push_back(Task(std::atoi(argv[0]), static_cast<std::string>(argv[1]), std::atoi(argv[2])));
	return 0;
}

int main()
{
	Database db;
	Organizer o;
	try
	{
		db.InitDatabase();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
	if (sqlite3_exec(db.dbHandle, "SELECT rowid, Details, State FROM Task;", GetTaskCallback, &o, &db.err))
	{
		std::cout << *db.err;
	}
	
	while (true)
	{
		system("cls");
		std::cout << "Organizer\n\n1. Tasks\n2. Add task\n3. Edit task\n4. Delete task\n0. Exit\n\n";
		switch (GetUserInput(1, 0, 4, "Select"))
		{
		case 1:
			system("cls");
			o.tasks.clear();
			if (sqlite3_exec(db.dbHandle, "SELECT rowid, Details, State FROM Task;", GetTaskCallback, &o, &db.err))
			{
				std::cout << *db.err;
			}
			o.PrintTasks();
			system("pause");
			break;
		case 2:
		{
			std::string details;
			std::cout << "Input task details: ";
			std::cin >> details;
			int state = GetUserInput(1, 0, 1, "Input task state (0 or 1): ");
			try
			{
				db.CreateTask(details, state);
			}
			catch (const std::exception & ex)
			{
				std::cout << ex.what();
			}
			std::cout << "Task added" << std::endl;
			system("pause");
			break;
		}
		case 3:
		{
			int id = GetUserInput(1, 0, static_cast<int>(o.tasks.size()) + 1, "Input task id (or 0 to exit): ");
			if (id > 0)
			{
				std::string details;
				std::cout << "Input task details: ";
				std::cin >> details;
				int state = GetUserInput(1, 0, 1, "Input task state (0 or 1): ");
				try
				{
					db.UpdateTask(id, details, state);
				}
				catch (const std::exception & ex)
				{
					std::cout << ex.what();
				}
				std::cout << "Task updated" << std::endl;
			}
			else
			{
				std::cout << "No task" << std::endl;
			}
			system("pause");
			break;
		}
		case 4:
		{
			int id = GetUserInput(1, 0, static_cast<int>(o.tasks.size()) + 1, "Input task id (or 0 to exit): ");
			if (id > 0)
			{
				try
				{
					db.RemoveTask(id);
				}
				catch (const std::exception & ex)
				{
					std::cout << ex.what();
				}
				std::cout << "Task deleted" << std::endl;
				system("pause");
			}
			else
			{
				std::cout << "No task" << std::endl;
			}
			break;
		}
		case 0:
			return 0;
		}
	}

}
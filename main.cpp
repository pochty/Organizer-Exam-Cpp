#include <iostream>
#include <climits>
#include "Organizer.h"
#include "GetUserInput.cpp"

int main()
{
	Organizer org;
	while (true)
	{
		system("cls");
		std::cout << "Organizer\n\n1. Tasks\n2. Add task\n3. Edit task\n4. Delete task\n0. Exit\n\n";
		switch (GetUserInput(1, 0, 4, "Select"))
		{
		case 1://List tasks
			system("cls");
			org.GetTasks();
			org.PrintTasks();
			system("pause");
			break;
		case 2://Add task
		{
			std::string details;
			std::cout << "Input task details: ";
			std::cin >> details;
			int state = GetUserInput(1, 0, 1, "Input task state (0 or 1): ");
			org.AddTask(details, state);
			std::cout << "Task added" << std::endl;
			system("pause");
			break;
		}
		case 3://Edit task
		{
			int id = GetUserInput(1, 0, INT_MAX, "Input task id (or 0 to exit): ");
			if (id > 0)
			{
				std::string details;
				std::cout << "Input task details: ";
				std::cin >> details;
				int state = GetUserInput(1, 0, 1, "Input task state (0 or 1): ");
				org.UpdateTask(id, details, state);
				std::cout << "Task updated" << std::endl;
			}
			else
			{
				std::cout << "No task" << std::endl;
			}
			system("pause");
			break;
		}
		case 4://Delete task
		{
			int id = GetUserInput(1, 0, INT_MAX, "Input task id (or 0 to exit): ");
			if (id > 0)
			{
				org.RemoveTask(id);
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
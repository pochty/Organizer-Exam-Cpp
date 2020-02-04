#include "Organizer.h"

void Organizer::PrintTasks()
{
	std::cout << std::setw(4) << "ID " << std::left << std::setw(28) << " Details\t" << std::setw(7) << "State" << std::endl;
	for (auto item : tasks)
	{
		std::cout << item << std::endl;
	}
}

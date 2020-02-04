#pragma once
#include <iostream>
#include <sqlite3.h>
#include <string>
#include <sstream>

class Database
{
public:
	sqlite3* dbHandle;
	char* err;

	Database();
	~Database();
	void InitDatabase();
	void CreateTask(std::string Details, int State);
	int RemoveTask(int id);
	int UpdateTask(int id, std::string Details, int State);

private:
	const char* path;
};


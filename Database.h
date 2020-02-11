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
	void Init();
	void Exec(const char* stmt);
	void Exec(const char* stmt, int (*callback)(void*, int, char**, char**), void* obj);
	int LastInsertRowid();
	
private:
	const char* path;

	static int LastInsertRowidCallback(void* data, int argc, char** argv, char** colName);
};


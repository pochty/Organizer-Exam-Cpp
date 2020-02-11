#include "Database.h"

Database::Database()
{
	err = nullptr;
	path = "data.db";
	if (sqlite3_open(path, &dbHandle)) throw std::exception("Error open DB");
}

Database::~Database()
{
	sqlite3_close(dbHandle);
	delete err;
}

void Database::Init()
{
	const char* stmt = "\
			CREATE TABLE IF NOT EXISTS Task(\
				Details TEXT,\
				State INT\
			);\
			";
	Exec(stmt);
}

void Database::Exec(const char* stmt)
{
	if (sqlite3_exec(dbHandle, stmt, NULL, NULL, &err)) throw std::exception(err);
}

void Database::Exec(const char* stmt, int (*callback)(void*, int, char**, char**), void* obj)
{
	if (sqlite3_exec(dbHandle, stmt, callback, obj, &err)) throw std::exception(err);
}

int Database::LastInsertRowid()
{
	const char* stmt = "SELECT last_insert_rowid();";
	//int* res = new(int){0};
	int res = 0;
	if (sqlite3_exec(dbHandle, stmt, LastInsertRowidCallback, &res, &err)) throw std::exception(err);
	std::cout << std::endl << res << std::endl;
	return res;
}

int Database::LastInsertRowidCallback(void* data, int argc, char** argv, char** colName)
{
	int* data_ = static_cast<int*>(data);
	*data_ = std::atoi(argv[0]);
	return 0;
}




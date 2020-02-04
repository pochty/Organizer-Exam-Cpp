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

	Database()
	{
		err = nullptr;
		path = "data.db";
		if (sqlite3_open(path, &dbHandle)) throw std::exception("Error open DB");
	}
	~Database()
	{
		sqlite3_close(dbHandle);
		delete err;
	}
	void InitDatabase()
	{
		const char* stmt = "\
			CREATE TABLE IF NOT EXISTS Task(\
				Details TEXT,\
				State INT\
			);\
			";
		if (sqlite3_exec(dbHandle, stmt, NULL, NULL, &err)) throw std::exception(err);
	}
	void CreateTask(std::string Details, int State)
	{
		std::stringstream stmt;
		stmt << "INSERT INTO Task (Details, State) \
				VALUES ('" << Details << "', '" << State << "');";
		if (sqlite3_exec(dbHandle, stmt.str().c_str(), NULL, NULL, &err)) throw std::exception(err);
	}
	int RemoveTask(int id)
	{
		if (id > 0)
		{
			std::stringstream stmt;
			stmt << "DELETE FROM Task \
					WHERE rowid = " << id << ";";
			if (sqlite3_exec(dbHandle, stmt.str().c_str(), NULL, NULL, &err)) throw std::exception(err);
			return 0;
		}
		return 1;
	}
	int UpdateTask(int id, std::string Details, int State)
	{
		if (id > 0)
		{
			std::stringstream stmt;
			stmt << "UPDATE Task \
					SET Details = '" << Details << "', State = '" << State << "'\
					WHERE rowid = " << id << ";";
			if (sqlite3_exec(dbHandle, stmt.str().c_str(), NULL, NULL, &err)) throw std::exception(err);
			return 0;
		}
		return 1;
	}

private:
	const char* path;
};


#ifndef INC_01_OP2_2_CRUD_FUNCTIONS_SQLITE_H
#define INC_01_OP2_2_CRUD_FUNCTIONS_SQLITE_H

#include <sqlite3/sqlite3.h>
#include <iostream>
#include <string.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName);
int createRecord(std::string table, std::string values, sqlite3* db);
int select(std::string values, std::string table, sqlite3* db);
int deleteRecord(std::string table, std::string condition, sqlite3* db);
int updateRecord(std::string table, std::string set, std::string condition, sqlite3* db);


#endif
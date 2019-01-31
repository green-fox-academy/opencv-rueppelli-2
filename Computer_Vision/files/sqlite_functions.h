#ifndef INC_01_OP2_2_CRUD_FUNCTIONS_SQLITE_H
#define INC_01_OP2_2_CRUD_FUNCTIONS_SQLITE_H

#include <sqlite3/sqlite3.h>
#include <iostream>
#include <string.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName);
int SQLgeneralConvert(const std::string &sqlCommand, sqlite3* db);
int SQLcreateRecord(std::string tableName, std::string path, long long int processTime, int circles, sqlite3* db);
int SQLselectQuery(std::string values, std::string table, sqlite3* db);
int SQLdeleteById(const std::string &table, int id, sqlite3* db);
int SQLdeleteLast(const std::string &table, sqlite3* db);
int SQLupdateRecord(const std::string &table, std::string setNewValue, int id, sqlite3* db);


#endif
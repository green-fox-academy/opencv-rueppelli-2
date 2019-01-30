#include "sqlite_functions.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


int generalSQLconvert(std::string sqlCommand, sqlite3* db)
{
    char buffer[100];
    char* errorMsg = 0;

    char *cSqlCommand = new char[sqlCommand.length() + 1];
    strcpy(cSqlCommand, sqlCommand.c_str());


    sprintf(buffer, "%s;",cSqlCommand); // table, set, condition

    sqlite3_exec(db, buffer, callback, 0, &errorMsg);

    return 1;
}


int createRecord(std::string tableName, std::string values, sqlite3* db)
{
    char buffer[100];
    char* errorMsg = 0;

    char *cValues = new char[values.length() + 1];
    strcpy(cValues, values.c_str());

    char *cTableName = new char[tableName.length() + 1];
    strcpy(cTableName, tableName.c_str());

    sprintf(buffer, "INSERT INTO %s VALUES(%s);",cTableName, cValues);

    sqlite3_exec(db, buffer, callback, 0, &errorMsg);

    return 1;
}


int select(std::string values, std::string table, sqlite3* db)
{
    char buffer[100];
    char* errorMsg = 0;

    char *cValues = new char[values.length() + 1];
    strcpy(cValues, values.c_str());

    char *cTable = new char[table.length() + 1];
    strcpy(cTable, table.c_str());

    sprintf(buffer, "SELECT %s FROM %s;",cValues, cTable);

    sqlite3_exec(db, buffer, callback, 0, &errorMsg);

    return 1;
}

int deleteRecord(std::string table, std::string condition, sqlite3* db)
{
    char buffer[100];
    char* errorMsg = 0;

    char *cTable = new char[table.length() + 1];
    strcpy(cTable, table.c_str());

    char *cCondition = new char[condition.length() + 1];
    strcpy(cCondition, condition.c_str());

    sprintf(buffer, "DELETE FROM %s WHERE %s;",cTable, cCondition);

    sqlite3_exec(db, buffer, callback, 0, &errorMsg);

    return 1;
}


int updateRecord(std::string table, std::string set, std::string condition, sqlite3* db)
{
    char buffer[100];
    char* errorMsg = 0;

    char *cTable = new char[table.length() + 1];
    strcpy(cTable, table.c_str());

    char *cSet = new char[set.length() + 1];
    strcpy(cSet, set.c_str());

    char *cCondition = new char[condition.length() + 1];
    strcpy(cCondition, condition.c_str());

    sprintf(buffer, "UPDATE %s  SET %s WHERE %s;",cTable, cSet, cCondition); // table, set, condition

    sqlite3_exec(db, buffer, callback, 0, &errorMsg);

    return 1;
}




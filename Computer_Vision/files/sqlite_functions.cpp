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


int SQLgeneralConvert(const std::string &sqlCommand, sqlite3* db)
{
    char buffer[100];
    char* errorMsg = 0;

    char *cSqlCommand = new char[sqlCommand.length() + 1];
    strcpy(cSqlCommand, sqlCommand.c_str());


    sprintf(buffer, "%s;",cSqlCommand); // table, set, condition

    sqlite3_exec(db, buffer, callback, 0, &errorMsg);

    return 1;
}


int SQLcreateRecord(std::string tableName, std::string path, long long int processTime, int circles, sqlite3* db)
{
    char buffer[100];
    char* errorMsg = 0;

    char *cTableName = new char[tableName.length() + 1];
    strcpy(cTableName, tableName.c_str());

    char *cPath = new char[path.length() + 1];
    strcpy(cPath, path.c_str());

    sprintf(buffer, "INSERT INTO %s(path, process_time, circles) VALUES(\'%s\', %lld, %d);",cTableName, cPath, processTime, circles);

    sqlite3_exec(db, buffer, callback, 0, &errorMsg);

    return 1;
}


int SQLselectQuery(std::string values, std::string table, sqlite3* db)
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

int SQLdeleteById(const std::string &table, int id, sqlite3* db)
{
    char buffer[100];
    char* errorMsg = 0;

    char *cTable = new char[table.length() + 1];
    strcpy(cTable, table.c_str());

    sprintf(buffer, "DELETE FROM %s WHERE id = %d;",cTable, id);

    sqlite3_exec(db, buffer, callback, 0, &errorMsg);

    return 1;
}

int SQLdeleteLast(const std::string &table, sqlite3* db)
{
    char buffer[100];
    char* errorMsg = 0;

    char *cTable = new char[table.length() + 1];
    strcpy(cTable, table.c_str());

    sprintf(buffer, "DELETE FROM %s WHERE id = ( SELECT MAX(id) FROM %s );;",cTable, cTable);

    sqlite3_exec(db, buffer, callback, 0, &errorMsg);

    return 1;
}

int SQLupdateRecord(const std::string &table, std::string setNewValue, int id, sqlite3* db)
{
    char buffer[100];
    char* errorMsg = 0;

    char *cTable = new char[table.length() + 1];
    strcpy(cTable, table.c_str());

    char *cSet = new char[setNewValue.length() + 1];
    strcpy(cSet, setNewValue.c_str());

    sprintf(buffer, "UPDATE %s  SET %s WHERE id = %d;",cTable, cSet, id); // table, set, condition

    sqlite3_exec(db, buffer, callback, 0, &errorMsg);

    return 1;
}




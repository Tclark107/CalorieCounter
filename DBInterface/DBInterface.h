#ifndef DBINTERFACE_H 
#define DBINTERFACE_H 

#include <iostream>
#include <vector>
#include <string>

class DBInterface {
public:
    virtual ~DBInterface() {}
    virtual bool connect() = 0;  // Connect to the database (or file)
    virtual void loadData() = 0;  // Load data from the database
    virtual void saveData() = 0;  // Save data to the database
    virtual void displayData() = 0;  // Display the data
};

#endif

#ifndef DBINTERFACE_H 
#define DBINTERFACE_H 

#include <vector>
#include <string>

class DBInterface {
public:
    virtual ~DBInterface() {}
    virtual bool connect() = 0;  // Connect to the database (or file)
    virtual bool disconnect() = 0;
    virtual void loadData() = 0;  // Load data from the database
    virtual void saveData() = 0;  // Save data to the database
    virtual void displayData() = 0;  // Display the data
    virtual std::vector<std::string> getData() = 0;
    virtual void addItem(const std::string& item) = 0;
};

#endif

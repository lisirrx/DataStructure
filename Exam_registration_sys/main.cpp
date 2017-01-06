#include <iostream>

#include "Database.hpp"
#include "list.hpp"


using namespace std;


int main() {
	Database database;
	database.event_loop(cin);   // create a database and do the event loop.
}
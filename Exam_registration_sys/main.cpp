#include <iostream>

#include "Database.hpp"

int main() {
	Database data;

	data.insert_entry(Entry(1, "hhh", Entry::Gender::Male, 20, "软件工程师"));

	data.show();



}
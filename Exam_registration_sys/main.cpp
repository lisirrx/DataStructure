#include <iostream>

#include "Database.hpp"

int main() {
	Database data;

	data.insert_entry(Entry(1, "hhh", Entry::Gender::Male, 20, "软件工程师"));
    data.insert_entry(Entry(2, "hhh", Entry::Gender::Male, 20, "软件工程师"));
    data.insert_entry(Entry(3, "hhh", Entry::Gender::Male, 20, "软件工程师"));
    data.insert_entry(Entry(4, "hhh", Entry::Gender::Male, 20, "软件工程师"));
    data.insert_entry(Entry(5, "hhh", Entry::Gender::Male, 20, "软件工程师"));
	data.show();


}
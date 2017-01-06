//
// Created by 李晗 on 2016/10/17.
//

#ifndef EXAM_REGISTRATION_SYS_DATABASE_HPP
#define EXAM_REGISTRATION_SYS_DATABASE_HPP

#include "Entry.hpp"
#include "list.hpp"
#include <iostream>
#include <string>

class Entry;
class Database {
public:
	Database();

	void notify(std::string _input);
	void event_loop(std::istream& _input);

	~Database();

	void insert_entry(Entry _entry);
	void delete_entry(int _id);
	Entry &search(int _id);
	void show();

protected:
	tiny::list<Entry> entry_list;
};


#endif //EXAM_REGISTRATION_SYS_DATABASE_HPP

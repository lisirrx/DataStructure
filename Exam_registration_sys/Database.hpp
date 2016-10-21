//
// Created by 李晗 on 2016/10/17.
//

#ifndef EXAM_REGISTRATION_SYS_DATABASE_HPP
#define EXAM_REGISTRATION_SYS_DATABASE_HPP

#include <list>
#include "Entry.hpp"

class Entry;
class Database {
public:
	Database();

	~Database();

	void insert_entry(Entry _entry);
	void delete_entry(int _id);
	const Entry &search(int _id) const;
	Entry &search(int _id);
	void show();

protected:
	std::list<Entry> entry_list;
};


#endif //EXAM_REGISTRATION_SYS_DATABASE_HPP

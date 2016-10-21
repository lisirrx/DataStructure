//
// Created by 李晗 on 2016/10/17.
//
#include <iostream>
#include "Database.hpp"
#include <algorithm>

Database::Database() { }

Database::~Database() { }

void Database::insert_entry(Entry _entry) {
	entry_list.push_back(_entry);
}

void Database::delete_entry(int _id) {
	entry_list.remove(Entry(_id));

}

const Entry &Database::search(int _id) const {
	Entry t(_id);
	for(auto i = entry_list.cbegin(); i != entry_list.cend(); ++i) {
		if(*i == t) {
			return *i;
		}
	}
	std::cerr << "Not found" << std::endl;
}

Entry &Database::search(int _id) {
	Entry t(_id);
	for(auto i = entry_list.begin(); i != entry_list.end(); ++i) {
		if(*i == t) {
			return *i;
		}
	}

	std::cerr << "Not found" << std::endl;

}

void Database::show() {
	for(auto &item : entry_list) {
		std::cout << item.__id << "\t" << item.__name << "\t";
		std::cout << (item.__gender == Entry::Gender::Female) ? "女" : "男";
		std::cout << "\t" << item.__age << "\t" << item.__type << std::endl; //TODO: output
	}
}

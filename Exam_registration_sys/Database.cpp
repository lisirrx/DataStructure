//
// Created by 李晗 on 2016/10/17.
//

#include "Database.hpp"

Database::Database() { }

Database::~Database() { }

void Database::insert_entry(Entry _entry){
	entry_list.push_back(_entry);

}
void Database::delete_entry(int _id){
	entry_list.remove(Entry(_id));

}
//const Entry &Database::search(int _id) const;
//Entry &Database::search(int _id);
//void Database::show();

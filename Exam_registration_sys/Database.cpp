//
// Created by 李晗 on 2016/10/17.
//
#include <iostream>
#include <memory>
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

Entry &Database::search(int _id) {
	std::shared_ptr<Entry> t = std::make_shared<Entry>(Entry(_id));
	bool found = false;
	for(auto i = entry_list.begin(); i != entry_list.end(); ++i) {
		if(*i == *t) {
			found = true;
			return *i;
		}
	}

	for(auto i = entry_list.begin(); i != entry_list.end(); ++i) {
		//do something.
	}

	if(!found) {
		notify("Not found!");
		t->set_id(-1);
		return *t;
	}

}



void Database::notify(std::string _input) {
	std::cout << _input << std::endl;
}

void Database::event_loop(std::istream& _input = std::cin) {

	int init_num = 0;
	int temp_id;
	std::string temp_name;
	std::string temp_gender;
	int temp_age;
	std::string temp_type;


	notify("Please create a examinee system database");
	notify("Please input the number of examinees:");


	_input >> init_num;
	notify("Please input the examinee's id, name, gender(Male or Female), age and exam type sequentially.");
	for(int i= 0; i < init_num; ++i){


		_input >> temp_id >> temp_name >> temp_gender >> temp_age >> temp_type;

		Entry::Gender gender = temp_gender == "Male" ? Entry::Gender::Male : Entry::Gender::Female;
		entry_list.push_back(Entry(temp_id, temp_name, gender, temp_age, temp_type));
	}

	show();

	notify("Please chose your operator: 1.Insert 2.Delete 3.Search 4.Modify 5.Print 0.Cancel");
	int operation = 0x3f3f3f;

	while(true) {  // the input and preocess loop
		notify("Please chose your operator :");
		_input >> operation;

		Entry result;
		switch(operation) {
			case 0:
				break;
			case 1:
				notify("Please input the examinee's id, name, gender(Male or Female), age and exam type sequentially.");
				_input >> temp_id >> temp_name >> temp_gender >> temp_age >> temp_type;
				insert_entry(Entry(temp_id, temp_name,temp_gender,temp_age,temp_type));
				show();

				break;
			case 2:
				notify("Please input the id of the examinee.");
				_input >> temp_id;
				delete_entry(temp_id);
				show();

				break;
			case 3:
				notify("Please input the id of the examinee");
				_input >> temp_id;
				result = search(temp_id);
				result.show();
				break;
			case 4:
				notify("Please input the id of the examinee");
				_input >> temp_id;
				result = search(temp_id);
				result.show();
				notify("Please input the examinee's id, name, gender(Male or Female), age and exam type sequentially.");

				_input >> temp_id >> temp_name >> temp_gender >> temp_age >> temp_type;
				result.set_age(temp_id)
						.set_name(temp_name)
						.set_gender(temp_gender)
						.set_age(temp_age).set_type(temp_type);
				result.show();
				break;
			case 5:
				show();
				break;
			default:
				break;
		}
	}



}


void Database::show() {
	for(auto i : entry_list){
		i.show();
	}
}
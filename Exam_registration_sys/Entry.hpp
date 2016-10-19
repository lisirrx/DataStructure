//
// Created by 李晗 on 2016/10/17.
//

#ifndef EXAM_REGISTRATION_SYS_ENTRY_HPP
#define EXAM_REGISTRATION_SYS_ENTRY_HPP

#include <string>


class Entry {
	friend class Database;
public:
	enum Gender {
		Male, Female
	};

	Entry(int _id, std::string _name, Gender _gender, int _age, std::string _type) :
			__id(_id), __name(_name), __gender(_gender), __age(_age), __type(_type) { }
	Entry(int _id):__id(_id){ }

	bool operator==(const Entry& _t) const {
		return __id == _t.__id;
	}

	~Entry(){};

protected:

	int __id;
	std::string __name;
	Gender __gender;
	int __age;
	std::string __type;
};


#endif //EXAM_REGISTRATION_SYS_ENTRY_HPP

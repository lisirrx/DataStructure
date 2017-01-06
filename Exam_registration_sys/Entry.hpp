//
// Created by 李晗 on 2016/10/17.
//

#ifndef EXAM_REGISTRATION_SYS_ENTRY_HPP
#define EXAM_REGISTRATION_SYS_ENTRY_HPP

#include <string>
#include <iostream>


class Entry {
	friend class Database;
public:
	enum Gender {
		Male, Female
	};
	Entry(){}
	Entry(int _id, std::string _name, Gender _gender, int _age, std::string _type) :
			__id(_id), __name(_name), __gender(_gender), __age(_age), __type(_type) { }

	Entry(int _id, std::string _name, std::string _gender, int _age, std::string _type) :
			__id(_id), __name(_name), __gender(_gender == "Male" ? Male : Female), __age(_age), __type(_type) { }

	Entry(int _id):__id(_id){ }

	bool operator==(const Entry& _t) const;
    bool operator<(const Entry& _t) const;
    bool operator>(const Entry& _t) const;

    Gender get_gender() const;
	int get_id(){ return __id;}
	int get_age(){ return __age;}
	std::string get_name(){ return __name;}
	std::string get_type(){ return __type;}

	std::string to_string(Gender gender){
		return gender == Male ? "Male" : "Female";
	}

	Entry& set_id(int _id){__id = _id;
		return *this;}
	Entry& set_age(int _age) {__age = _age;return *this;}
	Entry& set_name(std::string _name){__name = _name;return *this;}
	Entry& set_gender(Gender _gender){__gender = _gender;return *this;}
	Entry& set_gender(std::string _gender){__gender = (_gender == "Male" ? Male : Female);return *this;}
	Entry& set_type(std::string _type){__type = _type;return *this;}

	void show(std::ostream& output = std::cout){
		if(__id == -1){
			return;
		}
		output << __id << " " << __name << " "
				<< to_string(__gender) << " " << __age << " "
				<< __type << std::endl;
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

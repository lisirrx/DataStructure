//
// Created by 李晗 on 2016/12/12.
//

#ifndef EXPRESSION_TOKEN_HPP
#define EXPRESSION_TOKEN_HPP


#include <string>
#include <sstream>

class Token {
	enum id {OPERATOR, NUMBER};
private:
	std::string name;

public:
	explicit Token(){};
	~Token(){};
	std::string toString();
	int toInt();
};





#endif //EXPRESSION_TOKEN_HPP

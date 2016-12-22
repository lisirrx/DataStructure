//
// Created by 李晗 on 2016/12/12.
//

#include "Token.hpp"

std::string Token::toString(){
	return name;
}

int Token::toInt() {
	std::stringstream ss;
	ss << name;
	int temp;
	ss >> temp;
	return temp;
}


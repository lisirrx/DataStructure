
// Created by 李晗 on 2016/11/17.
//

#include "StrBlob.hpp"


void StrBlob::check(StrBlob::size_type i, const std::string &msg) const {

	if(i >= data->size()){
		throw std::out_of_range(msg);
	}

}

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()){

}

StrBlob::~StrBlob(){

}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)){

}

void StrBlob::pop_back(){
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
std::string& StrBlob::front(){
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back(){
	check(0, "back on empty StrBlob");
	return data->back();
}








//
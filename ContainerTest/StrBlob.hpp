//
// Created by 李晗 on 2016/11/17.
//

#ifndef CONTAINERTEST_STRBLOB_HPP
#define CONTAINERTEST_STRBLOB_HPP

#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
class StrBlob{
private:
	std::shared_ptr<std::vector<std::string>> data;

	void check(size_type i, const std::string &msg) const;

public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	~StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size();}
	bool empty() const { return data->empty();}

	void push_back(const std::string &t) { data->push_back(t);}
	void pop_back();
	std::string& front();
	std::string& back();
};


#endif //CONTAINERTEST_STRBLOB_HPP

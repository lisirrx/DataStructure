//
// Created by 李晗 on 2016/11/17.
//

#ifndef CONTAINERTEST_STRBLOB_HPP
#define CONTAINERTEST_STRBLOB_HPP

#include <memory>
#include <vector>
#include <string>
#include <stdexcept>


class StrBlob;

class StrBlobPtr {
public:

	StrBlobPtr() : curr(0) {};

	StrBlobPtr(StrBlob& a, size_t sz);

	std::string& deref() const;

	StrBlobPtr& incr();


private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};


class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	friend class StrBlobPtr;
	StrBlobPtr begin() {
		StrBlobPtr a = StrBlobPtr(*this, 0);
		return a;
	}

	StrBlobPtr end() {
		auto ret = StrBlobPtr(*this, data->size());
		return ret;
	}

	StrBlob();
	~StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	std::string& front();
	std::string& back();
private:
	std::shared_ptr<std::vector<std::string>> data;

	void check(size_type i, const std::string &msg) const;

};




#endif //CONTAINERTEST_STRBLOB_HPP

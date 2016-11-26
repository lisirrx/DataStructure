//
// Created by 李晗 on 2016/10/19.
//

#ifndef EXAM_REGISTRATION_SYS_LIST_HPP
#define EXAM_REGISTRATION_SYS_LIST_HPP

#include <memory>
#include <iostream>
#include <lber.h>


template<typename ValueType>
class List_node{

public:
	typedef List_node<ValueType>* Node_ptr;
	Node_ptr __pre_ptr;
	Node_ptr __nxt_ptr;
	ValueType __item;
	List_node();
	List_node(const ValueType& _item);
	List_node(const List_node& _node);
	List_node &operator=(const List_node& _node);
	bool operator==(const List_node& _node) const;
	~List_node(){
		std::cout << " List Node destory" << std::endl;
	};
};

template <typename ValueType>
List_node<ValueType>::List_node() {
	__pre_ptr = nullptr;
	__nxt_ptr = nullptr;
	std::cout << "List node : Default" << std::endl;
}

template <typename ValueType>
List_node<ValueType>::List_node(const ValueType& _item) {
	__item = _item;
	std::cout << "List node : By ValueType " << std::endl;
}

template <typename ValueType>
List_node<ValueType>::List_node(const List_node& _node){
	__item = _node.__item;
	__pre_ptr = _node.__pre_ptr;
	__nxt_ptr = _node.__nxt_ptr;
	std::cout << "List node : Copy" << std::endl;
}

template <typename ValueType>
List_node<ValueType>& List_node<ValueType>::operator=(const List_node &_node) {
	__item = _node.__item;
	__pre_ptr = _node.__pre_ptr;
	__nxt_ptr = _node.__nxt_ptr;
}

template <typename ValueType>
bool List_node<ValueType>::operator==(const List_node& _node) const {
	return __item == _node.__item;
}



template<typename ValueType>
class List {


public:
	typedef List_node<ValueType>* Node_ptr;
	List();
	~List(){
		std::cout << "List destroy" << std::endl;

		while(__tail != __head){
			auto t  = __tail;
			__tail = __tail->__pre_ptr;
			delete t;
		}

		delete __head;
	};

	void push_back(const ValueType &_item);
	void push_back(List_node<ValueType>& _node);
//	void remove(const ValueType &_item);
//	ValueType &search(const ValueType &_item) const;

	void print();
protected:
	Node_ptr __head;
	Node_ptr __tail;
	Node_ptr __curr;

};




template <typename ValueType>
List<ValueType>::List() {
	__head = new List_node<ValueType>();
	__tail = new List_node<ValueType>();
	__curr = __head;
	__head->__nxt_ptr = __tail;
	__head->__pre_ptr = __tail;

	__tail->__nxt_ptr = __head;
	__tail->__pre_ptr = __head;
}


template <typename ValueType>
void List<ValueType>::push_back(const ValueType &_item) {
	auto nodde_ptr = new List_node<ValueType>(_item);
	__tail->__pre_ptr->__nxt_ptr = nodde_ptr;

	nodde_ptr->__nxt_ptr = __tail;
	nodde_ptr->__pre_ptr = __tail->__pre_ptr;
	__tail->__pre_ptr = nodde_ptr;

}

template <typename ValueType>
void List<ValueType>::push_back(List_node<ValueType> &_node) {
	_node.__pre_ptr = __tail->__pre_ptr;
	_node.__nxt_ptr = __tail;

	__tail->__pre_ptr = &_node;

}

template <typename ValueType>
void List<ValueType>::print() {
	while(__curr != __tail){
		std::cout << __curr->__item << std::endl;
	}
}






#endif //EXAM_REGISTRATION_SYS_LIST_HPP

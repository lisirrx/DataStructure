//
// Created by 李晗 on 2016/10/19.
//

#ifndef EXAM_REGISTRATION_SYS_LIST_HPP
#define EXAM_REGISTRATION_SYS_LIST_HPP

#include <memory>
#include <iostream>


template<typename ValueType>
class List_node{

public:
	typedef std::shared_ptr<List_node<ValueType>> Node_ptr;
	Node_ptr __pre;
	Node_ptr __nxt;
	ValueType __item;
	List_node();
	List_node(const ValueType& _item);
	List_node(const List_node& _node);
	List_node &operator=(const List_node& _node);
	bool operator==(const List_node& _node) const;
	~List_node(){
		std::cout << "List node destroy." << std::endl;
	}
};

template <typename ValueType>
List_node<ValueType>::List_node() {
	__pre = nullptr;
	__nxt = nullptr;
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
	__pre = _node.__pre;
	__nxt = _node.__nxt;
	std::cout << "List node : Copy" << std::endl;
}

template <typename ValueType>
List_node<ValueType>& List_node<ValueType>::operator=(const List_node &_node) {
	__item = _node.__item;
	__pre = _node.__pre;
	__nxt = _node.__nxt;
}

template <typename ValueType>
bool List_node<ValueType>::operator==(const List_node& _node) const {
	return __item == _node.__item;
}


template<typename ValueType>
class List {


public:
	typedef std::shared_ptr<List_node<ValueType>> Node_ptr;
	List();
	~List(){

		std::cout << __head.use_count() << std::endl;
		std::cout << "List destroy" << std::endl;
	};

	void push_back(const ValueType &_item);
	void push_back(const List_node<ValueType> &_node);
//	void remove(const ValueType &_item);
//	ValueType &search(const ValueType &_item) const;

	void print();
protected:
	Node_ptr __head;
	Node_ptr __tail;

};




template <typename ValueType>
List<ValueType>::List() {
	__head = std::make_shared<List_node<ValueType>>();
	__tail = std::make_shared<List_node<ValueType>>();

	__head->__nxt = __tail;
	__head->__pre = nullptr;

	__tail->__nxt = nullptr;
	__tail->__pre = __head;
}


template <typename ValueType>
void List<ValueType>::push_back(const ValueType &_item) {
	auto nodde_ptr = std::make_shared<List_node<ValueType>>(_item);
	__tail->__pre->__nxt = nodde_ptr;

	nodde_ptr->__nxt = __tail;
	nodde_ptr->__pre = __tail->__pre;
	__tail->__pre = nodde_ptr;

}

template <typename ValueType>
void List<ValueType>::push_back(const List_node<ValueType> &_node) {
	_node.__pre = __tail->__pre;
	_node.__nxt = __tail;

	__tail->__pre = std::make_shared<List_node<ValueType>>(_node);

}








#endif //EXAM_REGISTRATION_SYS_LIST_HPP

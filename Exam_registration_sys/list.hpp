//
// Created by 李晗 on 2016/10/19.
//

#ifndef EXAM_REGISTRATION_SYS_LIST_HPP
#define EXAM_REGISTRATION_SYS_LIST_HPP

#include <memory>

namespace lisirrx {
	template<typename ValueType>
	class List_node{
	protected:
		std::shared_ptr<List_node<ValueType>> __pre;
		std::shared_ptr<List_node<ValueType>> __nxt;
		ValueType __item;

	public:

		friend class List;
		List_node(){};
		List_node(const ValueType& _item);
		List_node(const List_node& _node);
		List_node &operator=(const List_node& _node);
		bool operator==(const List_node& _node) const;
		~List_node(){}
	};


	template<typename ValueType>
	class List {
	protected:
		std::shared_ptr<List_node<ValueType>> __head;
		std::shared_ptr<List_node<ValueType>> __tail;

	public:
		List();
		~List(){};

//		void push_back(const ValueType &_node);
//		void remove(const ValueType &_node);
//		ValueType &search(const ValueType &_node) const;


	};
}

template <typename ValueType>
lisirrx::List_node::List_node(const ValueType& _item) {
	__item = _item;
}

template <typename ValueType>
lisirrx::List_node::List_node(const List_node& _node){
	__item = _node.__item;
	__pre = _node.__pre;
	__nxt = _node.__nxt;
}

template <typename ValueType>
List_node& lisirrx::List_node::operator=(const List_node &_node) {
	__item = _node.__item;
	__pre = _node.__pre;
	__nxt = _node.__nxt;
}

template <typename ValueType>
bool lisirrx::List_node::operator==(const List_node& _node) const {
	return __item == _node.__item;
}


lisirrx::List::List() {
	List_node head;
	List_node tail;
	__head = std::make_shared(head);
	__tail = std::make_shared(tail);
	__tail = __head->__nxt;
	__head = __tail->__pre;
}

//
//template <typename ValueType>
//void lisirrx::List::push_back(const ValueType &_node) {
//
//}
//




#endif //EXAM_REGISTRATION_SYS_LIST_HPP

//
// Created by lisirrx on 16-9-29.
//

#ifndef BST_BST_HPP
#define BST_BST_HPP

#include <ctime>

template <typename KEY, typename VALUE>
class BST_node {
	friend class BST;

public:
	BST_node();

	BST_node(KEY _Key, VALUE _value) : __key(_Key), __value(_value) { };

	BST_node(const BST_node &_n);

	BST_node &operator=(const BST_node &_n);

	bool operator<(const BST_node &_n);

	bool operator>(const BST_node &_n);

	bool operator==(const BST_node &_n);

protected:
	BST_node *__parent = nullptr;
	BST_node *__left_child = nullptr;
	BST_node *__right_child = nullptr;
	KEY __key;
	VALUE __value;
};

template <typename KEY, typename VALUE>
BST_node<KEY, VALUE>::BST_node(const BST_node &_n) {
	__parent = _n.__parent;
	__left_child = _n.__left_child;
	__right_child = _n.__right_child;
	__key = _n.__key;
	__value = _n.__value;
}

template <typename KEY, typename VALUE>
BST_node<KEY, VALUE> &BST_node<KEY, VALUE>::operator=(const BST_node &_n) {

	__parent = _n.__parent;
	__left_child = _n.__left_child;
	__right_child = _n.__right_child;
	__key = _n.__key;
	__value = _n.__value;

	return *this;
}

template <typename KEY, typename VALUE>
bool BST_node<KEY, VALUE>::operator<(const BST_node &_n) {
	return this->__key < _n.__key;
}

template <typename KEY, typename VALUE>
bool BST_node<KEY, VALUE>::operator>(const BST_node &_n) {
	return this->__key > _n.__key;
}

template <typename KEY, typename VALUE>
bool BST_node<KEY, VALUE>::operator==(const BST_node &_n) {
	return this->__key == _n.__key;
}


template <typename KEY, typename VALUE>
class BST {

public:
	explicit BST();

	BST_node &init();

	virtual ~BST();

	BST_node &insert_node(BST_node _node);

	void delete_node(KEY _key);

	void inorder_walk();

	void preorder_walk();

	void postorder_walk();

	BST_node *search(KEY _key);


protected:
	BST_node __root;

};


#endif //BST_BST_HPP

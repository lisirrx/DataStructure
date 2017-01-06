//
// Created by lisirrx on 16-9-29.
//

#ifndef BST_BST_HPP
#define BST_BST_HPP

#include <memory>

#include <stdio.h>



template <typename KEY, typename VALUE>
class BST_node {


public:
	BST_node(){};

	BST_node(KEY _Key, VALUE _value) : __key(_Key), __value(_value) { };
    BST_node(KEY _Key) : __key(_Key) { };

	BST_node(const BST_node &_n);

	BST_node &operator=(const BST_node &_n);

	bool operator<(const BST_node &_n);

	bool operator>(const BST_node &_n);

	bool operator==(const BST_node &_n);

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
    enum Dic{LEFT, RIGHT, NIL};
    typedef BST_node<KEY, VALUE>* node_ptr;
    typedef BST_node<KEY, VALUE>& node_ref;
    typedef BST_node<KEY, VALUE>  node;

    BST(){}
	BST(node_ptr _root) : __root(new decltype(*_root) (_root)){}

	~BST(){
        clear(__root);
    }

    void clear(node_ptr _root){
        std::cout << " clear " << std::endl;

        if(_root == nullptr){
            return;
        }
        clear(_root->__left_child);
        clear(_root->__right_child);
        delete _root;
        _root = nullptr;
        return;
    }

    node_ref insert_node(node _node){

        node_ptr new_node = new node(_node);
        node_ptr parent = nullptr;
        node_ptr temp = __root;
        while(temp != nullptr)
        {
            parent = temp;
            if(new_node->__key > temp->__key)
                temp= temp->__right_child;
            else {
                temp = temp->__left_child;
            }
        }
        new_node->__parent = parent;
        if(parent == nullptr) {
            __root = new_node;
        }
        else if(new_node->__key>parent->__key) {
            parent->__right_child = new_node;
        } else {
            parent->__left_child = new_node;
        }

        return *new_node;
    }


    node_ref insert(KEY _key){
        return insert_node(node(_key));

    }

	void delete_node(KEY _key);

	void inorder_walk();

	void preorder_walk();

	void postorder_walk();

    node_ref search(KEY _key);


protected:
    node_ptr __root = nullptr;

};







#endif //BST_BST_HPP

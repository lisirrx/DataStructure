//
// Created by lisirrx on 16-9-29.
//

#ifndef BST_BST_HPP
#define BST_BST_HPP

#include <ctime>

template<typename KEY, typename VALUE>
class BST_node {
    friend class BST;

public:
    BST_node() : __parent(nullptr), __left_child(nullptr), __right_child(nullptr);

    BST_node(KEY _key) : 

protected:
    BST_node *__parent;
    BST_node *__left_child;
    BST_node *__right_child;
    KEY __key;
    VALUE __value;
};

template<typename KEY, typename VALUE>
class BST {

public:
    BST() {}

    BST(BST_node _root) : __root(_root) {}

    virtual ~BST();

    void insert_node(BST_node _node);

    void delete_node();

    void inorder_walk();

    void preorder_walk();

    void postorder_walk();

    BST_node *search(KEY _key);


protected:
    BST_node __root;

};

template<typename KEY, typename VALUE>


#endif //BST_BST_HPP

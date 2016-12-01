//
// Created by 李晗 on 2016/12/1.
//

#ifndef LIST_LIST_HPP
#define LIST_LIST_HPP

#include <memory>
#include <iterator>
#include <cstddef>
#include <iostream>

namespace stl {
	template <typename ValueType>
	struct __list_node {
		typedef __list_node <ValueType> *__node_pointer;
		__node_pointer __ptr_nxt;
		__node_pointer __ptr_pre;
		ValueType __item;

		__list_node(const ValueType &_item) : __item(_item) {
			std::cout << " list node construct" << std::endl;
		}

		~__list_node() { std::cout << " list node destory" << std::endl; }
	};


	template <typename ValueType, typename Ref = ValueType &, typename Ptr = ValueType *>
	struct __list_iterator {

		typedef __list_iterator <ValueType, ValueType &, ValueType *> __iterator;
		typedef __list_iterator <ValueType, Ref, Ptr> __self;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef ValueType value_type;
		typedef Ptr pointer;
		typedef Ref reference;
		typedef __list_node <ValueType> *__node_pointer;
		typedef size_t size_typef;
		typedef ptrdiff_t difference_type;


		__node_pointer __node;

		__list_iterator() { };

		__list_iterator(__node_pointer x) : __node(x) { }

		__list_iterator(const __iterator &_iter) : __node(_iter.__node) { }

		reference operator*() {
			return __node->__item;
		}

		pointer operator->() {
			return (&(operator*()));
		}

		bool operator==(const __self &_i) const {
			return __node == _i.__node;
		}

		bool operator!=(const __self &_i) const {
			return __node != _i.__node;
		}

		__self &operator++() {
			__node = __node->__ptr_nxt;
			return *this;
		}

		__self operator++(int) {
			__self tmp = *this;

			++*this;
			return tmp;
		}

		__self &operator--() {
			__node = __node->__ptr_pre;
			return *this;
		}

		__self operator--(int) {
			__self tmp = *this;
			--*this;
			return tmp;
		}


	};


	template <typename Iterator>
	struct __iterator__traits {
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
	};

	template <typename T>
	struct __iterator__traits <T *> {
		typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
	};


	template <typename T>
	struct __iterator__traits <const T *> {
		typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef const T *pointer;
		typedef const T &reference;
	};


	template <typename ValueType, class Alloc = std::allocator <__list_node <ValueType>>>
	class list {

	protected:
		typedef __list_node <ValueType> __node_type;

	public:
		typedef __node_type *__node_pointer;
		typedef __list_iterator <ValueType, ValueType &, ValueType *> __iterator;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef ValueType value_type;

		typedef typename __iterator__traits <__list_iterator <ValueType>>::pointer pointer;
		typedef typename __iterator__traits <__list_iterator <ValueType>>::reference reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;

	protected:
		__node_pointer __node;
		Alloc alloc;

	public:
		__iterator begin() {
			return __node->__ptr_nxt;
		}

		__iterator end() {
			return __node;
		}

		bool empty() const {
			return __node->__ptr_nxt == __node;
		}

		size_type size() const {
			size_type result = 0;
			//distance(begin(), end(), result);
			return result;
		}

		reference front() {
			return *begin();
		}

		reference back() {
			return *(--end());
		}

		__node_pointer get_node() {
			return alloc.allocate(1);
		}

		void put_node(__node_pointer p) {
			alloc.deallocate(p);
		}

		__node_pointer create_node(const ValueType &x) {
			__node_pointer new_node = get_node();
			alloc.construct(new_node, x);
			return new_node;
		}

		void destory_node(__node_pointer p) {
			alloc.destroy(p);
		}

		list() {
			__node = get_node();
			__node->__ptr_nxt = __node;
			__node->__ptr_pre = __node;
		}

		__iterator insert(__iterator position, const ValueType &x) {
			__node_pointer tmp = create_node(x);
			tmp->__ptr_nxt = position.__node;
			tmp->__ptr_pre = position.__node->__ptr_pre;

			position.__node->__ptr_pre->__ptr_nxt = tmp;

			position.__node->__ptr_pre = tmp;
			return tmp;
		}

		void push_back(const ValueType &x) {
			insert(end(), x);
		}

		void clear() {
			__node_pointer cur = __node->__ptr_nxt;
			while(cur != __node) {
				__node_pointer tmp = cur;
				cur = cur->__ptr_nxt;
				destory_node(tmp);
			}

			__node->__ptr_nxt = __node;
			__node->__ptr_pre = __node;
		}

		~list() {
			clear();
			destory_node(__node);
			std::cout << " list destory" << std::endl;
		}
	};

}


#endif //LIST_LIST_HPP

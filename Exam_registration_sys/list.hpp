//
// Created by 李晗 on 2016/10/19.
//

#ifndef EXAM_REGISTRATION_SYS_LIST_HPP
#define EXAM_REGISTRATION_SYS_LIST_HPP

#include <memory>

namespace lisirrx {
	template <typename ValueType>
	class list {
	protected:
		std::shared_ptr<ValueType> __head;
		std::shared_ptr<ValueType> __current;

	public:
//		list();
//		~list();
//		void push_back(const ValueType &_node);
//		void remove(const ValueType &_node);
//		ValueType &search(const ValueType &_node) const;


	};
}




#endif //EXAM_REGISTRATION_SYS_LIST_HPP

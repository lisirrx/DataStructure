//
// Created by 李晗 on 2016/10/17.
//

#include "Entry.hpp"

bool Entry::operator==(const Entry& _t) const {
    return __id == _t.__id;
}

bool Entry::operator<(const Entry& _t) const{
    return __id < _t.__id;
}
bool Entry::operator>(const Entry& _t) const {
    return __id > _t.__id;
}

Entry::Gender Entry::get_gender() const{
    return __gender;
}
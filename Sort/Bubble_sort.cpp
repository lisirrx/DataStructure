//
// Created by lisirrx on 16-10-21.
//

#include "Sort_functions.hpp"

void bubble_sort(std::vector<int> &_array) {

    for (int i = 0; i < _array.size(); ++i) {
        for (int j = i + 1; j < _array.size(); ++j) {
            if (_array.at(i) > _array.at(j)) {
                std::swap(_array.at(i), _array.at(j));
            }
        }
    }
}

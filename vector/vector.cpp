#include "vector.h"

namespace nonstd {
    template<typename T>
    vector<T>::vector() {
        _begin = new T[INIT_SIZE];
        _MAX_SIZE = INIT_SIZE;
        _end = _begin;
    }

    template<typename T>
    vector<T>::~vector() {
        delete[] _begin; // deletes container
    }

    template<typename T>
    void vector<T>::push_back(T elem){
        if (_end - _begin >= _MAX_SIZE - 1){
            _MAX_SIZE *= 2;
            T* tempPtr = new T[_MAX_SIZE];
            for (size_t i = 0; i < _end - _begin; i++){
                tempPtr[i] = _begin[i];
            }
            delete[] _begin;
            _begin = tempPtr;
            push_back(elem);
        }
        else{
            _begin[_end++] = elem;
        }
    }

    template<typename T>
    size_t vector<T>::size(){
        return _end - _begin;
    }

    template<typename T>
    T vector<T>::operator[](size_t iter) const{
        if (iter >= size())
            throw std::out_of_range("index is invalid.");
        return _begin[iter];
    }

    template<typename T>
    // friend function
    std::ostream& operator<<(std::ostream& os, const vector<T>& vector){
        for (T* i = vector._begin; i < vector._end; i++){
            std::cout << *i << ' ';
        }
        std::cout << '\n';
    }
}

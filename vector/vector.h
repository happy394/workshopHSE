#ifndef INC_3KONTEST_VECTOR_H
#define INC_3KONTEST_VECTOR_H

#include <iostream>

namespace nonstd
{
    const size_t INIT_SIZE = 10;
    template <typename T>
    class vector{
    public:
        vector(); // constructor
        ~vector(); // destructor (deletes)
        void push_back(T);
        size_t size() const;
        T& operator[](size_t);
        T operator[](size_t) const;
//        friend std::ostream& operator<<(std::ostream&, const vector<T>&);

    private:
        T* _begin;
        T* _end;
        size_t _MAX_SIZE;
    };

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
            *_end = elem;
            _end++;
        }
    }

    template<typename T>
    size_t vector<T>::size() const {
        return _end - _begin;
    }

    template<typename T>
    T& vector<T>::operator[](size_t iter) {
        if (iter >= size())
            throw std::out_of_range("index is invalid.");
        return _begin[iter];
    }

    template<typename T>
    T vector<T>::operator[](size_t iter)const {
        if (iter >= size())
            throw std::out_of_range("index is invalid.");
        return _begin[iter];
    }

    template<typename T>
    // friend function
    std::ostream& operator<<(std::ostream& os, const vector<T>& vector){
//        for (T* i = vector._begin; i < vector._end; i++){
//            os << *i << ' ';
//        }
//        os << '\n';
        for (size_t i = 0; i < vector.size(); i++){
            os << vector[i] << ' ';
        }
        return os;
    }
}



#endif //INC_3KONTEST_VECTOR_H

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
        size_t size();
        T operator[](size_t) const;
        friend std::ostream& operator<<(std::ostream&, const vector<T>&);

    private:
        T* _begin, _end;
        size_t _MAX_SIZE;
    };

}



#endif //INC_3KONTEST_VECTOR_H

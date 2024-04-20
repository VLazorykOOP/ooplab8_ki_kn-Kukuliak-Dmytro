#pragma once
template <typename T>
class SortFind {
private:
    size_t n;
    T* arr;
public:
    SortFind(size_t N){
        this->n = N;
        arr = new T[N]; // Allocate memory for the array of pointers
    }

    ~SortFind() {
        delete[] arr;
    }
    void randomize() {
        srand(time(NULL));
        for (size_t i = 0; i < n; i++) {
            arr[i] = static_cast<T>(rand() % 128 );
        }
    }
    friend std::ostream& operator<<(std::ostream& os, SortFind<T>& a) {
        for (int i = 0; i < a.n; i++) {
            os << a.arr[i] << " ";
        }
        os << std::endl;
        return os;
    }
    template <typename T> int find(T a) {
        int index=-1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == a)index = i;
        }
        return index;
    }

};

#pragma once
#include <vector>
#include <cstring>

template <typename T>
class SortFind {
private:
    static const long int min_range = 10000;
    static const long int max_range = 10000;
    size_t n;
    T* arr;

public:
    SortFind(size_t N) {
        this->n = N;
        arr = new T[N];
    }

    ~SortFind() {
        delete[] arr;
    }

    void randomize() {
        srand(time(NULL));
        for (size_t i = 0; i < n; i++) {
            arr[i] = static_cast<T>(rand() % (2 * max_range) - min_range);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, SortFind<T>& a) {
        for (int i = 0; i < a.n; i++) {
            os << a.arr[i] << " ";
        }
        os << std::endl << std::endl;
        return os;
    }

    int find(T a) {
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == a) {
                index = i;
                break;
            }
        }
        return index;
    }

    void countingSort() {
        std::vector<int> count(min_range + max_range);
        for (int i = 0; i < n; i++) {
            count[arr[i] + min_range]++;
        }
        size_t position = 0;
        for (int i = 0; i < count.size(); i++) {
            for (int j = 0; j < count[i]; j++) {
                arr[position] = i - max_range;
                position++;
            }
        }
    }

    T& operator[](size_t index) {
        return arr[index];
    }


    SortFind& operator=(const SortFind& other) {
        if (this != &other) {
            delete[] arr;
            n = other.n;
            arr = new T[n];
            for (size_t i = 0; i < n; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }


    SortFind operator+(const SortFind& other) {
        if (this->n == other.n)
        {
            SortFind result(n);
            for (int i = 0; i < n; i++) {
                result[i] = this->arr[i] + other.arr[i];
            }
        }
        else
        {
        std::cout << "The objects don`t match";
        return *this;
        }
    }


    SortFind operator-(const SortFind& other) {
        if (this->n == other.n) {
            SortFind result(n);
                for (int i = 0; i < n; i++) {
                    result[i] = this->arr[i] - other.arr[i];
                }
        }
        else
        {
        std::cout << "The objects don`t match";
        return *this;
        }
    }


};

// спеціалізація для char*
template <>
void SortFind<char*>::randomize() {
    srand(time(NULL));
    for (size_t i = 0; i < n; i++) {
        int len = rand() % 20 + 1; 
        arr[i] = new char[len + 1]; 
        for (int j = 0; j < len; j++) {
            arr[i][j] = 'a' + rand() % 26; 
        }
        arr[i][len] = '\0'; 
    }
}


template <>
void SortFind<char*>::countingSort() {
    std::vector<int> count(128); 
    for (int i = 0; i < n; i++) {
        count[strlen(arr[i])]++;
    }
    size_t position = 0;
    for (int i = 0; i < count.size(); i++) {
        for (int j = 0; j < count[i]; j++) {
            int len = i; 
            char* temp = new char[len + 1]; 
            for (int k = 0; k < len; k++) {
                temp[k] = 'a' + rand() % 26; 
            }
            temp[len] = '\0'; 
            arr[position] = temp; 
            position++;
        }
    }
}


template <>
int SortFind<const char*>::find(const char* a) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], a) == 0) { 
            index = i;
            break;
        }
    }
    return index;
}

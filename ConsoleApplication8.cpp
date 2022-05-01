#include <iostream>

template <class T> 
class List {
private:
    T* list;
    int n;
public:
    List(int n) {
        this->n = n;
        T* list = new T[n];
        this->list = list;
    }
    ~List() { delete[] list; }
    List(const List& l) {
        n = l.n;
        T* list = new T[n];
        for (size_t i = 0; i < n; i++)
        {
            list[i] = l.list[i];
        }
    }
    template <class U> friend std::ostream& operator << (std::ostream&, const List<U>&);
    template <class U> friend std::istream& operator >> (std::istream&, List<U>&);
    void operator += (const T& m) {
        n++;
        T* list = new T[n];
        for (size_t i = 0; i < n; i++)
        {
            list[i] = this->list[i];
        }
        list[n - 1] = m;
        this->list = list;
    }

    T& operator[] (int n) { return list[n]; }
};


template <class T> std::ostream& operator << (std::ostream& stream, const List<T>& arr) {
    for (size_t i = 0; i < arr.n; i++)
    {
        stream << arr.list[i] << " ";
    }
    return stream;
}

template <class T> std::istream& operator >> (std::istream& stream, List<T>& arr) {
    for (size_t i = 0; i < arr.n; i++)
    {
        stream >> arr.list[i];
    }
    return stream;
}

int main() {
    int n;
    std::cin >> n;
    List<int> arr(n);
    std::cin >> arr;
    //arr += 4;
    arr[2]+=1;
    //std::cout << arr[2];
    std::cout << arr;
    return 0;
}
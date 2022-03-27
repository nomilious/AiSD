#include <cstring>
#include <iostream>
#include <sstream>
template <class T>
class Deque {
public:
    Deque();
    ~Deque() { delete[] array; };
    Deque(const Deque&);
    void push_back(const T&);
    void push_front(const T&);
    T pop_back();
    T pop_front();
    void grow();
    bool is_empty() const { return (length == 0); }
    // проверяет если указатель начала указывает на первый элемент //
    bool head_at_beg() const { return (&array[0] == head); }
    // проверяет если указатель конца указывает на последний элемент //
    bool tail_at_end() const { return (&array[capacity - 1] == tail); }

private:
    T* head = nullptr;
    T* tail = nullptr;
    T* array = nullptr;
    int capacity = 0;
    int length = 0;
};
template <class T>
Deque<T>::Deque(const Deque& q) {
    this->array = new T[q.capacity];
    std::memcpy(array, q.array, sizeof(T) * q.length);
    this->length = q.length;
    this->head = &array[q.head - &q.array[0]];
    this->tail = &array[q.tail - &q.array[0]];
}

template <class T>
void Deque<T>::grow() {
    T* newvar;

    capacity *= 2;
    newvar = new T[capacity];

    if (head > tail) {  //был не обычный сдвиг
        int j = 0;
        //вставляем начиная с [0] элемента в новый массив элементы старого начиная с head
        for (int i = head - tail; i < length; ++i, ++j)
            newvar[j] = array[i];
        //вставляем начиная смещенные элементы в конец нового массива
        for (int i = 0; i < (head - tail); ++i, ++j)
            newvar[j] = array[i];
    } else {
        std::memcpy(newvar, array, sizeof(T) * length);
    }

    delete[] array;
    array = newvar;
    head = &newvar[0];
    tail = &newvar[length - 1];
}
template <class T>
void Deque<T>::push_back(const T& newElement) {
    if (length == capacity)
        grow();

    if (is_empty()) {
        head = tail = &array[0];
        *tail = newElement;
    } else if (!tail_at_end()) {  // сдвигаем по-обычному, т.е вправо
        *(++tail) = newElement;
    } else {  // не обычный сдвиг
        tail = &array[0];
        *tail = newElement;
    }
    ++length;
}
template <class T>
void Deque<T>::push_front(const T& newElement) {
    if (length == capacity)
        grow();

    if (is_empty()) {
        head = tail = &array[0];
        *head = newElement;
    } else if (!head_at_beg()) {  //сдвигаем по-обычному, т.е влево
        *(--head) = newElement;
    } else {  // не обычный сдвиг
        head = &array[capacity - 1];
        *head = newElement;
    }
    ++length;
}
template <class T>
Deque<T>::Deque() {
    capacity = 4;
    array = new T[capacity];
}

template <class T>
T Deque<T>::pop_back() {
    --length;
    return *(tail--);
}
template <class T>
T Deque<T>::pop_front() {
    --length;
    return *(head++);
}

template <typename Stream>
std::string run(Stream& stream) {
    Deque<int> deq;
    int n = 0;
    bool result = true;

    stream >> n;
    for (int i = 0; i < n; ++i) {
        int command, value;
        stream >> command >> value;
        switch (command) {
            case (1):
                deq.push_front(value);
                break;
            case (2):
                if (deq.is_empty())
                    result = result && value == -1;
                else
                    result = result && deq.pop_front() == value;
                break;
            case (3):
                deq.push_back(value);
                break;
            case (4):
                if (deq.is_empty())
                    result = result && value == -1;
                else
                    result = result && deq.pop_back() == value;
                break;
        }
    }
    return (result ? "YES" : "NO");
}
int test() {
    std::stringstream s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;

    s1 << "3\n1 44\n 3 50\n 2 44\n";
    s2 << "2\n2 -1\n 1 10\n";
    s3 << "2\n3 44\n 4 66\n";
    s4 << "7\n1 44\n 3 50\n 2 44\n2 50\n 1 10\n3 44\n 4 44\n";
    s5 << "30\n1 1\n3 2\n 1 2\n1 4\n 3 5\n1 1\n3 2\n 1 2\n1 4\n 3 5\n1 1\n3 2\n 1 2\n1 4\n 3 5\n1 1\n3 2\n 1 2\n1 4\n 3 5\n2 - 1\n 4 - 1\n2 - 1\n 4 - 1\n2 - 1\n 4 - 1\n2 - 1\n 4 - 1\n2 - 1\n 4 - 1\n";
    s6 << "9\n3 11\n 3 12\n 3 14\n 3 15\n2 11\n 2 12\n 3 19\n 3 18\n 3 17\n";
    s7 << "9\n1 11\n 1 12\n 1 14\n 1 15\n4 11\n 4 12\n 1 19\n 1 18\n 1 17\n";
    s8 << "18\n3 11\n 3 12\n 3 14\n 3 15\n2 11\n 2 12\n 3 19\n 3 18\n 3 17\n1 11\n 1 12\n 1 14\n 1 15\n4 11\n 4 12\n 1 19\n 1 18\n 1 17\n";
    s9 << "18\n1 11\n 1 12\n 1 14\n 1 15\n4 11\n 4 12\n 1 19\n 1 18\n 1 17\n3 11\n 3 12\n 3 14\n 3 15\n2 11\n 2 12\n 3 19\n 3 18\n 3 17\n";
    s10 << "36\n1 11\n 1 12\n 1 14\n 1 15\n4 11\n 4 12\n 1 19\n 1 18\n 1 17\n3 11\n 3 12\n 3 14\n 3 15\n2 11\n 2 12\n 3 19\n 3 18\n 3 17\n3 11\n 3 12\n 3 14\n 3 15\n2 11\n 2 12\n 3 19\n 3 18\n 3 17\n1 11\n 1 12\n 1 14\n 1 15\n4 11\n 4 12\n 1 19\n 1 18\n 1 17\n";
    std::cout
        << (run(s1) == "YES") << (run(s2) == "YES")
        << (run(s3) == "NO") << (run(s4) == "YES")
        << (run(s5) == "NO") << (run(s6) == "YES")
        << (run(s9) == "NO") << (run(s8) == "NO")
        << (run(s7) == "YES") << (run(s10) == "YES") << std::endl;
    return 0;
}
int main() {
    // std:: cout << run(std::cin);
    test();

    return 0;
}
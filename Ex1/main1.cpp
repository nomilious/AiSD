/*
Использование арифметических операций запрещено.

1.1 Подсчитать кол-во единичных бит в входном числе , стоящих на четных позициях. Позиции битов нумеруются с 0.
*/
#include <iostream>
#include <sstream>
int countBit(int);
template <typename Stream>
int run(Stream&);
int test();

int main() {
    std::cout << run(std::cin);
    // test();

    return 0;
}
int countBit(int n) {
    int i = (n & 1);
    while (n) {
        if (n & (1 << 2))
            i++;
        n >>= 2;
    }
    return i;
}
int test() {
    std::stringstream s1, s2;

    s1 << "5" << std::endl;
    s2 << "1" << std::endl;
    std::cout << (run(s1) == 2) << std::endl
              << (run(s2) == 1) << std::endl;

    return 0;
}
template <typename Stream>
int run(Stream& stream) {
    int N;

    stream >> N;
    return countBit(N);
}
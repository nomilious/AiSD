/*
   1.4 Инвертируйте значение бита в числе N по его номеру K.
   Формат входных данных. Число N, номер бита K.
   Формат выходных данных. Число с инвертированным битом в десятичном виде.
*/
#include <iostream>
#include <sstream>
int flipBit(unsigned int, unsigned int);
template <typename Stream>
int run(Stream&);
int test();

int main() {
    std::cout << run(std::cin);
    // test();

    return 0;
}
int flipBit(unsigned int n, unsigned int k) {
    return (n ^ (1 << k));
}
int test() {
    std::stringstream s1, s2, s3;

    s1 << 25 << std::endl
       << 1 << std::endl;
    s2 << 25 << std::endl
       << 4 << std::endl;
    s3 << 1 << std::endl
       << 0 << std::endl;
    std::cout
        << (run(s1) == 27) << std::endl
        << (run(s2) == 9) << std::endl
        << (run(s3) == 0) << std::endl;

    return 0;
}
int test2() {
    std::stringstream s1, s2, s3;
    int i = 0;
    s1 << 31 << std::endl
       << i++ << std::endl;
    std::cout << (run(s1) == 30);
    s1.str("");
    s1 << 31 << std::endl
       << i++ << std::endl;  // 1
    std::cout << (run(s1) == 29);
    s1.str("");
    s1 << 31 << std::endl
       << i++ << std::endl;  // 2
    std::cout << (run(s1) == 27);
    s1.str("");
    s1 << 31 << std::endl
       << i++ << std::endl;  // 3
    std::cout << (run(s1) == 23);
    s1.str("");
    s1 << 31 << std::endl
       << i++ << std::endl;  // 4
    std::cout << (run(s1) == 15);
    s1.str("");
    i = 0;
    s1 << 32 << std::endl
       << i++ << std::endl;  // 0
    std::cout << (run(s1) == 33);
    s1.str("");
    s1 << 32 << std::endl
       << i++ << std::endl;  // 1
    std::cout << (run(s1) == 34);
    s1.str("");
    s1 << 32 << std::endl
       << i++ << std::endl;  // 2
    std::cout << (run(s1) == 36);
    s1.str("");
    s1 << 32 << std::endl
       << i++ << std::endl;  // 3
    std::cout << (run(s1) == 40);
    s1.str("");
    s1 << 32 << std::endl
       << i++ << std::endl;  // 4
    std::cout << (run(s1) == 48);
    s1.str("");
    s1 << 32 << std::endl
       << i++ << std::endl;  // 5
    std::cout << (run(s1) == 0);
    s1.str("");
    s1 << 32 << std::endl
       << i++ << std::endl;  // 6
    std::cout << (run(s1) == 96);
    s1.str("");
    return 0;
}
template <typename Stream>
int run(Stream& stream) {
    unsigned int N, k;

    stream >> N >> k;
    return flipBit(N, k);
}
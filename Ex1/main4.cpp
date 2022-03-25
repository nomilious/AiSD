#include <iostream>
#include <sstream>
int countBit(int, int);
template <typename Stream>
int run(Stream&);
int test();

int main() {
    // std::cout << run(std::cin);
    test();

    return 0;
}
int countBit(int n, int k) {
    return (n ^ (1 << k));
}
int test() {
    std::stringstream s1, s2, s3;

    s1 << "25 1" << std::endl;
    s2 << "25 4" << std::endl;
    s3 << "1 0" << std::endl;
    std::cout
        << (run(s1) == 27) << std::endl
        << (run(s2) == 9) << std::endl
        << (run(s3) == 0) << std::endl;

    return 0;
}
template <typename Stream>
int run(Stream& stream) {
    int N, k;

    stream >> N >> k;
    return countBit(N, k);
}
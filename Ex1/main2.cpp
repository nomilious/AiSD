#include <iostream>
#include <sstream>
int hasOnly1Bit(int, int);
template <typename Stream>
int run(Stream&);
int test();

int main() {
    // std::cout << run(std::cin);
    test();

    return 0;
}
int hasOnly1Bit(int n, int k) {
    return ((n & (1 << k)) > 0);
}
int test() {
    std::stringstream s1, s2, s3, s4;

    s1 << "1 1" << std::endl;
    s2 << "1 0" << std::endl;
    s4 << "25 2" << std::endl;
    s3 << "25 3" << std::endl;
    std::cout
        << (run(s1) == 0) << std::endl
        << (run(s2) == 1) << std::endl
        << (run(s4) == 0) << std::endl
        << (run(s3) == 1) << std::endl;

    return 0;
}
template <typename Stream>
int run(Stream& stream) {
    int N, k;

    stream >> N >> k;
    return hasOnly1Bit(N, k);
}
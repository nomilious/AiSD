/*
    1.3 Если в числе содержится только один бит со значением 1, записать в выходной поток OK. Иначе записать FAIL
*/
#include <iostream>
#include <sstream>
#include <string>
int hasOnly1Bit(int);
template <typename Stream>
std::string run(Stream&);
int test();

int main() {
    std::cout << run(std::cin);
    // test();

    return 0;
}
int hasOnly1Bit(int n) {
    int i = 0;
    while (n) {
        if (n & 1)
            i++;
        n >>= 1;
    }
    return i;
}
int test() {
    std::stringstream s1, s2;

    s1 << "1" << std::endl;
    s2 << "0" << std::endl;
    std::cout << (run(s1) == "OK") << std::endl
              << (run(s2) == "FAIL") << std::endl;

    return 0;
}
template <typename Stream>
std::string run(Stream& stream) {
    int N;

    stream >> N;
    if (hasOnly1Bit(N) == 1)
        return "OK";
    return "FAIL";
}
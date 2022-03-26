#include <iostream>
#include <sstream>
int find_inflection_ind(int *, int);
int bin_search(int *, int, int);

template <typename Stream>
int run(Stream &);
int test();
int main() {
    // std::cout << run(std::cin);
    test();

    return 0;
}
template <typename Stream>
int run(Stream &stream) {
    int n, res;
    int *array;

    stream >> n;
    array = new int[n];
    for (int i = 0; i < n; i++)
        stream >> array[i];

    res = find_inflection_ind(array, n);

    delete[] array;
    return res;
}
int test() {
    std::stringstream s1, s2, s3, s4;
    std::stringstream s5, s6, s7, s8, s9, s10;

    s1 << "10\n10 9 8 7 6 5 4 3 2 1\n";
    s2 << "10\n1 2 3 4 7 6 5 4 3 2\n";
    s3 << "10\n3 4 5 6 7 8 4 3 2 1\n";
    s4 << "10\n1 2 5 4 3 2 1 0 -1 -2\n";

    s5 << "10\n1 2 3 4 5 4 3 2 1 0\n";
    s6 << "10\n1 2 3 4 6 5 3 2 1 0\n";
    s7 << "10\n1 2 3 5 6 4 3 2 1 0\n";
    s8 << "10\n1 2 3 5 6 5 3 2 1 0\n";
    s9 << "15\n0 1 2 3 4 5 6 7 8 9 7 6 5 4 3\n";
    s10 << "12\n0 1 2 3 4 15 16 70 8 3 2 1\n";
    std::cout
        << (run(s1) == 0) << std::endl
        << (run(s2) == 4) << std::endl
        << (run(s3) == 5) << std::endl
        << (run(s4) == 2) << std::endl
        << (run(s5) == 4) << std::endl
        << (run(s6) == 4) << std::endl
        << (run(s7) == 4) << std::endl
        << (run(s8) == 4) << std::endl
        << (run(s9) == 9) << std::endl
        << (run(s10) == 7) << std::endl;

    return 0;
}
int find_inflection_ind(int *array, int size) {
    int i = 1;
    while ((i * 2 < size) && array[i] < array[i * 2]) {
        i *= 2;
        if (array[i] < array[i - 1])  // из-за итерации проскачили максимум
            return bin_search(array, i / 2, i);
    }
    if (array[0] > array[1])  // if array[0] is maximum
        i--;
    return bin_search(array, i, std::min(i * 2, size));
}
int bin_search(int *array, int from, int to) {
    while (from < to) {
        int mid = (to + from) / 2;

        if (to - from == 1)
            return array[from] > array[to] ? from : to;

        if (array[mid] > std::max(array[mid + 1], array[mid - 1]))  // если попал на максимум
            return mid;
        else if (array[mid - 1] <= array[mid + 1])  // на стороне возрастания
            from = mid;
        else  // проскачили максимум, на стороне убывания
            to = mid;
    }
    return from;
}
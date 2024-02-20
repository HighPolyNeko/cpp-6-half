#include "Funcs.h"

#include <iostream>

void funcs::N1() {
    for (int i = 0; i < 100 - 1; ++i) {
        std::cout << i + 1 << ", ";
    }
    std::cout << "100\n";
}

void funcs::N2() {
    int n, ans = 1;
    std::cout << "Введиете число: ";
    std::cin >> n;
    if (n > 1) {
        for (int i = 1; i < n + 1; ++i) {
            ans *= i;
        }
    }

    std::cout << "Факториал числа " << n << ": " << ans << '\n';
}

void funcs::N3() {
    std::cout << "Введите числа, чтоб остановить ввод напишите \"\\0\": ";
    int* arr = new int[0];
    int n, len = 0;
    while (std::cin >> n) {
        int* newArr = new int[len + 1];
        for (int i = 0; i < len; ++i) {
            *(newArr + i) = *(arr + i);
        }
        *(newArr + len++) = n;
        delete[] arr;
        arr = newArr;
    }

    std::cout << "Исходний массив: [";
    for (int i = 0; i < len - 1; ++i) {
        std::cout << *(arr + i) << ", ";
    }
    std::cout << *(arr + len - 1) << "]\n";

    // Сортировка
    for (int i = 1; i < len; ++i) {
        int buff = *(arr + i);

        int j = i;
        while (j > 0 && *(arr + j - 1) > buff) {
            *(arr + j) = *(arr + j - 1);
            j--;
        }

        *(arr + j) = buff;
    }
    // Конец сортировки

    std::cout << "Отсортированный массив: [";
    for (int i = 0; i < len - 1; ++i) {
        std::cout << *(arr + i) << ", ";
    }
    std::cout << *(arr + len - 1) << "]\n";

    delete[] arr;
}

void funcs::N4() {
    int sum = 0;
    for (int i = 1; i < 100; i += 2) {
        sum += i;
    }
    std::cout << "Сумма всех нечетных чисел от 1 до 100: " << sum << '\n';
}

void funcs::N5() {
    std::cout << "Введите числа, чтоб остановить ввод напишите \"\\0\": ";
    int* arr = new int[0];
    int n, len = 0;
    while (std::cin >> n) {
        int* newArr = new int[len + 1];
        for (int i = 0; i < len; ++i) {
            *(newArr + i) = *(arr + i);
        }
        *(newArr + len++) = n;
        delete[] arr;
        arr = newArr;
    }

    float ans = 0;
    for (int i = 0; i < len; ++i) {
        ans += *(arr + i);
    }
    ans /= len;

    std::cout << "Среднее арифметическое: " << ans << '\n';
    delete[] arr;
}

void funcs::N6() {
    std::cout << "Введите 2 числа, длинну и ширину: ";
    int length, width;

    std::cin >> length >> width;
    std::cout << "Площадь: " << area(length, width) << '\n';
    std::cout << "Периметр: " << perimeter(length, width) << '\n';
}

void funcs::N7() {
    std::cout << "Введите числа, чтоб остановить ввод напишите \"\\0\": ";
    int* arr = new int[0];
    int n, len = 0;
    while (std::cin >> n) {
        int* newArr = new int[len + 1];
        for (int i = 0; i < len; ++i) {
            *(newArr + i) = *(arr + i);
        }
        *(newArr + len++) = n;
        delete[] arr;
        arr = newArr;
    }

    int min = *arr, max = *arr;
    for (int i = 1; i < len; ++i) {
        if (min > *(arr + i)) {
            min = *(arr + i);
        }
        if (max < *(arr + i)) {
            max = *(arr + i);
        }
    }
    std::cout << "Минимум: " << min << '\n';
    std::cout << "Максимум: " << max << '\n';
}

int funcs::area(int length, int width) {
    return length * width;
}

int funcs::perimeter(int length, int width) {
    return (length + width) * 2;
}

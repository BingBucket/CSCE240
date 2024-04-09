#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <array>

void bubbleSortVector(std::vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int main() {
    int testNum = 100;
    srand(time(0));
    std::cout << "Testing for 100 elements" << std::endl;
    std::vector<int> arr(1);
    for (int i = 0; i < testNum; i++) {
        arr.push_back(rand() % 100);
    }
    auto start = std::chrono::steady_clock::now();
    bubbleSortVector(arr);
    auto end = std::chrono::steady_clock::now();
    std::cout << "Time taken to sort a vector of 100 elements: " << std::chrono::duration<double>(end - start).count() << " seconds." << std::endl;
    std::array <int, 100> arr2;
    for (int i = 0; i < testNum; i++) {
        arr2[i] = rand() % 100;
    }
    start = std::chrono::steady_clock::now();
    bubbleSortArray(arr2.data(), testNum);
    end = std::chrono::steady_clock::now();
    std::cout << "Time taken to sort an array of 100 elements: " << std::chrono::duration<double>(end - start).count() << " seconds." << std::endl;

    std::cout << "Testing for 1000 elements" << std::endl;
    std::vector<int> arr3(1);
    for (int i = 0; i < testNum * 10; i++) {
        arr3.push_back(rand() % 1000);
    }
    start = std::chrono::steady_clock::now();
    bubbleSortVector(arr3);
    end = std::chrono::steady_clock::now();
    std::cout << "Time taken to sort a vector of 1000 elements: " << std::chrono::duration<double>(end - start).count() << " seconds." << std::endl;
    std::array <int, 1000> arr4;
    for (int i = 0; i < testNum * 10; i++) {
        arr4[i] = rand() % 1000;
    }
    start = std::chrono::steady_clock::now();
    bubbleSortArray(arr4.data(), testNum * 10);
    end = std::chrono::steady_clock::now();
    std::cout << "Time taken to sort an array of 1000 elements: " << std::chrono::duration<double>(end - start).count() << " seconds." << std::endl;

    std::cout << "Testing for 10000 elements" << std::endl;
    std::vector<int> arr5(1);
    for (int i = 0; i < testNum * 100; i++) {
        arr5.push_back(rand() % 10000);
    }
    start = std::chrono::steady_clock::now();
    bubbleSortVector(arr5);
    end = std::chrono::steady_clock::now();
    std::cout << "Time taken to sort a vector of 10000 elements: " << std::chrono::duration<double>(end - start).count() << " seconds." << std::endl;
    
    std::array <int, 10000> arr6;
    for (int i = 0; i < testNum * 100; i++) {
        arr6[i] = rand() % 10000;
    }
    start = std::chrono::steady_clock::now();
    bubbleSortArray(arr6.data(), testNum * 100);
    end = std::chrono::steady_clock::now();
    std::cout << "Time taken to sort an array of 10000 elements: " << std::chrono::duration<double>(end - start).count() << " seconds." << std::endl;

    std::cout << "Testing for 100000 elements" << std::endl;
    std::vector<int> arr7(1);
    for (int i = 0; i < testNum * 1000; i++) {
        arr7.push_back(rand() % 100000);
    }
    start = std::chrono::steady_clock::now();
    bubbleSortVector(arr7);
    end = std::chrono::steady_clock::now();
    std::cout << "Time taken to sort a vector of 100000 elements: " << std::chrono::duration<double>(end - start).count() << " seconds." << std::endl;

    std::array <int, 100000> arr8;
    for (int i = 0; i < testNum * 1000; i++) {
        arr8[i] = rand() % 100000;
    }
    start = std::chrono::steady_clock::now();
    bubbleSortArray(arr8.data(), testNum * 1000);
    end = std::chrono::steady_clock::now();
    std::cout << "Time taken to sort an array of 100000 elements: " << std::chrono::duration<double>(end - start).count() << " seconds." << std::endl;

    return 0;
}
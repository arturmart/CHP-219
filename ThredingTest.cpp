// ThredingTest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <random>
#include <ctime>
#include <mutex>
#include <vector>


std::mutex mtx;


int arr[100000000];

long long arrSum = 0;

void arrRandom(int* arr, int size) {

    srand(time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 11;

    }
}

void sumArr(int* arr, int from, int to) {

    long long localSum = 0;

    for (int i = from; i < to; i++) {
        localSum += arr[i];
    }
    mtx.lock();
    arrSum += localSum;
    mtx.unlock();


}

void sumArrMultiThreadin(int* arr, int tCnt, int size) {

    
    std::vector<std::thread> threads;
    for (int i = 0; i < tCnt; ++i) {
        int from = (size / tCnt) * i;
        int to = (i == tCnt - 1) ? size : (size / tCnt) * (i + 1);
        threads.emplace_back(sumArr, arr, from, to);
    }

    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }


}

int main()
{
    arrRandom(arr, 100000000);
    
    auto start = std::chrono::high_resolution_clock::now();
    sumArr( arr, 0, 100000000);
    
    auto end = std::chrono::high_resolution_clock::now(); // Конечное время
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "time: " << duration.count() << " milliseconds" << std::endl;
    std::cout << "arrSum: " << arrSum << std::endl;

    arrSum = 0;

    start = std::chrono::high_resolution_clock::now();
    sumArrMultiThreadin(arr, 8, 100000000);

    end = std::chrono::high_resolution_clock::now(); // Конечное время
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "time: " << duration.count() << " milliseconds" << std::endl;
    std::cout << "arrSum multiThread: " << arrSum << std::endl;
}

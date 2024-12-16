#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;



void print(std::string str) {
	mtx.lock();
	std::cout << str << std::endl;
	mtx.unlock();
}

void doEvryTime(int threadNum, long long time) {
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(time));
		auto now = std::chrono::high_resolution_clock::now();
		long long milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

		print("t" + std::to_string(threadNum) + "(" + std::to_string(time) + ") time:" + std::to_string(milliseconds));
	}
}




int main() {

	std::vector<std::thread> threads;

	threads.emplace_back(doEvryTime, 1, 100);
	threads.emplace_back(doEvryTime, 2, 500);
	threads.emplace_back(doEvryTime, 3, 1000);
	threads.emplace_back(doEvryTime, 4, 5000);

	for (auto& it : threads) {
		if (it.joinable()) {
			it.join();
		}
	}

	
}
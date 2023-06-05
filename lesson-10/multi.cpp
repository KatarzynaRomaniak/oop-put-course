#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>

std::mutex mutx;
std::atomic<int> FA(0);
std::atomic<int> FT(0);
std::atomic<int> FC(0);
std::atomic<int> FG(0);

void calculate(const std::string& seq, int start, int end) {
	int localFA = 0;
	int localFT = 0;
	int localFC = 0;
	int localFG = 0;

	for (int i = start; i < end; ++i) {
		switch (seq[i]) {
		case 'A':
			++localFA;
			break;
		case 'T':
			++localFT;
			break;
		case 'C':
			++localFC;
			break;
		case 'G':
			++localFG;
			break;
		}
	}

	std::lock_guard<std::mutex> lock(mutx);
	FA += localFA;
	FT += localFT;
	FC += localFC;
	FG += localFG;
}

int main() {
	std::string dna = "CCGGCAGGCTTACGTATTGCACG";
	int num_threads = 4;
	int sectionSize = dna.size() / num_threads;
	std::vector<std::thread> threads;

	for (int i = 0; i < num_threads; ++i) {
		int start = i * sectionSize;
		int end = (i == num_threads - 1) ? dna.size() : (i + 1) * sectionSize;
		threads.emplace_back(calculate, std::ref(dna), start, end);
	}

	for (auto& thread : threads) {
		thread.join();
	}

	int totalFA = FA;
	int totalFT = FT;
	int totalFC = FC;
	int totalFG = FG;

	std::cout << "A: " << totalFA << std::endl;
	std::cout << "T: " << totalFT << std::endl;
	std::cout << "C: " << totalFC << std::endl;
	std::cout << "G: " << totalFG << std::endl;

	return 0;
}

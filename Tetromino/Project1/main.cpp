
#include <iostream>

#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int main(int argc, char* argv[])
{
	std::cout << "begin" << std::endl;

	std::thread t{ []() {
		std::this_thread::sleep_for(1s);

		std::cout << "end" << std::endl;
		} };

	std::this_thread::sleep_for(1s);
	std::cout << "aspetto la fine del thread" << std::endl;
	t.join();

	return 0;
}
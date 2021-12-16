#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <future>

// zad 1
// funkcja zwracajaca identyfikator watku
int getThreadId() {
    static int id = 0;
    return id++;
}

// zad 2
std::mutex m;
void getText(std::string text) {
    std::lock_guard <std::mutex> lock(m);
    std::cout << "Thread " << getThreadId() << ": " + text << '\n';
}

// zad 3
int count = 0;
void getAsync(std::launch mode) {
    if (count < 3) {
        count++;
        std::future <void> f = async(mode, getAsync, mode);
        getText("async x" + std::to_string(count));
    }
}

int main() {
    // test
    std::thread thread1(getText, "Test nr. 1");
    std::thread thread2(getText, "Text nr. 2");
    thread1.join();
    thread2.join();

    getAsync(std::launch::async);
}
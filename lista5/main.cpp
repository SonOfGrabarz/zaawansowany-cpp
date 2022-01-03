#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <future>

// zad 1
// funkcja zwracajaca identyfikator watku
int getThreadId() {
    static std::mutex m;
    static int count = 0;
    thread_local int id = ++count;
    // static int id = 0;
    return id++;
}

// zad 2
void getText(std::string text) {
    static std::mutex m;
    std::lock_guard <std::mutex> lock(m);
    std::cout << "Thread " << getThreadId() << ": " + text << '\n';
}

// zad 3
void getAsync(std::launch mode) {
    static int count = 0;
    if (count < 3) {
        count++;
        std::future <void> f = async(mode, getAsync, mode);
        getText("async x" + std::to_string(count));
        f.get();
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
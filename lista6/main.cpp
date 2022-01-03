#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <mutex>

void get_product( const std::vector <double> x, const std::vector <double> y, std::promise <double> p){
    static std::mutex m;
    std::lock_guard <std::mutex> l(m);
    static int i = -1;
    
    // wektory puste
    if (x.size() == 0 || y.size() == 0) {
        throw std::logic_error("Vector is empty");
    }

    // wektory rozniace sie rozmiarem
    else if (x.size() != y.size()) {
        throw std::logic_error("Vectors are different size");
    }

    else {
        i++;
        p.set_value(x[i] * y[i]);
    }
}

int main(){
    std::vector <double> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector <double> y = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 10 watkow
    int numberOfThreads = 10;
    double sum = 0.0;

    std::vector <std::pair < std::thread, std::future <double> > > threadBuffor;

    try {
        for (int i = 0; i < numberOfThreads; i++) {
            std::promise <double> p1;
            std::future <double> f1 = p1.get_future();
            std::thread t1(get_product, x, y, move(p1));
            threadBuffor.push_back(std::make_pair(std::move(t1), std::move(f1)));
            // std::cout <<  threadBuffor.size() << '\n';
        }

        for (auto &e : threadBuffor) {
            auto t2 = std::move(e.first);
            auto f2 = std::move(e.second);
            sum += f2.get();
            t2.join();
        }

        std::cout << "sum: " << sum << '\n';
    }

    catch (const std::logic_error &e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
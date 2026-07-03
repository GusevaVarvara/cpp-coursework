#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>
#include <string>
#include <cmath>

double calculate_integral(int num_points, int num_threads) {
    std::atomic<int> points_inside(0);
    std::vector<std::thread> threads;
    int points_per_thread = num_points / num_threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([&points_inside, points_per_thread]() {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0.0, 1.0);

            int local_count = 0;
            for (int i = 0; i < points_per_thread; ++i) {
                double x = dis(gen);
                double y = dis(gen);
                if (y <= x * x) {
                    ++local_count;
                }
            }
            points_inside += local_count;
            });
    }

    for (auto& t : threads) {
        t.join();
    }

    return static_cast<double>(points_inside) / num_points;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <number_of_points> <number_of_threads>\n";
        return 1;
    }

    int num_points = std::stoi(argv[1]);
    int num_threads = std::stoi(argv[2]);

    auto start_time = std::chrono::high_resolution_clock::now();
    double integral_estimate = calculate_integral(num_points, num_threads);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end_time - start_time;

    std::cout << "Estimated integral = " << integral_estimate << '\n';
    std::cout << "Time taken = " << duration.count() << " seconds\n";

    return 0;
}


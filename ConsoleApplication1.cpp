/*
#include <iostream>
#include <chrono>
#include <thread>

class FPS {
private:
    unsigned int fps;
    unsigned int fpsCount;
    std::chrono::time_point<std::chrono::steady_clock> lastTime;

public:
    FPS() : fps(0), fpsCount(0), lastTime(std::chrono::steady_clock::now()) {}

    void update() {
        fpsCount++;
        auto currentTime = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();

        if (duration > 1000) {
            fps = fpsCount;
            fpsCount = 0;
            lastTime = currentTime;
        }
    }

    unsigned int getFPS() const {
        return fps;
    }
};

int main() {
    FPS fpsCounter;

    while (true) {
       
        
       fpsCounter.update();
       std::cout << "FPS: " << fpsCounter.getFPS() << std::endl;
        // Simulate some work
        //std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Simulate work without limiting FPS
       // system("cls");
    }

    return 0;
}
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

class FPS {
private:
    unsigned int fps;
    unsigned int fpsCount;
    std::chrono::time_point<std::chrono::steady_clock> lastTime;

public:
    FPS() : fps(0), fpsCount(0), lastTime(std::chrono::steady_clock::now()) {}

    void update() {
        fpsCount++;
        auto currentTime = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastTime).count();

        if (duration > 1000) {
            fps = fpsCount;
            fpsCount = 0;
            lastTime = currentTime;
        }
    }

    unsigned int getFPS() const {
        return fps;
    }
};

void runFPSCounter(FPS& fpsCounter) {
    while (true) {
        fpsCounter.update();
        std::cout << "FPS: " << fpsCounter.getFPS() << std::endl;
    }
}

int main() {
    FPS fpsCounter;
    std::vector<std::thread> threads;

    // Create multiple threads running the FPS counter
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(runFPSCounter, std::ref(fpsCounter));
    }

    // Join threads to the main thread
    for (auto& t : threads) {
        t.join();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Simulate work without limiting FPS

    return 0;
}

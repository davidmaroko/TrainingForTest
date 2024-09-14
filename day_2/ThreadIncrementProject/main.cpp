#include <iostream>

void run_unsafe_increment();
void run_mutex_increment();
void run_semaphore_increment();

int main() {
    int choice;

    std::cout << "Choose the version to run:\n";
    std::cout << "1. Unsafe Increment\n";
    std::cout << "2. Mutex Increment\n";
    std::cout << "3. Semaphore Increment\n";
    std::cout << "Enter choice (1-3): ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        run_unsafe_increment();
        break;
    case 2:
        run_mutex_increment();
        break;
    case 3:
        run_semaphore_increment();
        break;
    default:
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}

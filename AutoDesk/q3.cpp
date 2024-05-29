#include <iostream>

// Function to calculate the Nth Fibonacci number
long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    
    long long a = 0, b = 1, c = 1;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    
    return c;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    long long result = fibonacci(n);
    std::cout << "The " << n << "th Fibonacci number is: " << result << std::endl;

    return 0;
}

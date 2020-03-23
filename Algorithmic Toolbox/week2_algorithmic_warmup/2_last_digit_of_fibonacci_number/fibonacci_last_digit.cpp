#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    std::vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    if(n <= 1)
        return dp[n];
    for(int i = 2; i <= n; i++) 
        dp[i] = ((dp[i-1]%10)+(dp[i-2]%10))%10;
    return dp[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long)numbers[first] * (long long)numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
	int largest = 0, second_largest = 0;
	int n = numbers.size();
	std::vector<int> fre(1e5+7, 0);
	for(auto x: numbers)
		fre[x]++;
	for(int i = 0; i < n; i++) {
		if(numbers[i] > largest) 
			largest = numbers[i];
	}
	for(int j = 0; j < n; j++) {
		if(numbers[j] > second_largest && (numbers[j] != largest || fre[numbers[j]] > 1))
			second_largest = numbers[j];
	}
	return ((long long)largest*(long long)second_largest);
}

void stress_test() {
	while(1) {
		int n = rand()%10 + 2;
		std::cout << "n = " << n << "\n";
		std::vector<int> a;
		for(int i = 0; i < n; i++)
			a.push_back(rand()%100000);
		long long ans1 = MaxPairwiseProduct(a);
		long long ans2 = MaxPairwiseProductFast(a);
		if(ans1 != ans2) {
			std::cout << "Wrong Answer!\n";
			std::cout << "ans1 = " << ans1 << "\n";
			std::cout << "ans2 = " << ans2 << "\n";
			break;
		}
		else std::cout << "Correct answer\n";
	}
}

int main() {
	//stress_test();
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}

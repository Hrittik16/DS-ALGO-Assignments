#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
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

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}

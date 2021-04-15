#include <iostream>

int main()
{
	int row;
	std::cin >> row;

	int *matrix = new int[ row * row ];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			std::cin >> matrix[i * row + j ];
		}
	}

	int sum = 0;
	for (int i = 0; i < row * row; i++) {
		if (i >= (row - 1) && i % (row - 1) == 0) {
			std::cout << "i = " << i << std::endl;
			continue;
		}
		if (i > row * row - row ) {
			std::cout << "i = " << i << std::endl;
			continue;
		}
		sum += matrix[i];
	}

	std::cout << sum << std::endl;
	return 0;
}
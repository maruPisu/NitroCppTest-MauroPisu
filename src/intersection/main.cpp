#include "rectangle.h"
#include <iostream>

int main(){
	Rectangle rec(5, 3, 30, 15);
	Rectangle big(15, 13, 10, 10);

	std::cout << rec.stringify();
	std::cout << big.stringify();
	auto inter = rec.intersection(big);
	std::cout << inter.stringify();
    return 0;
}

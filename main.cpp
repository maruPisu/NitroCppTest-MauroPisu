#include "rectangle.h"
#include <iostream>

int main(){
	Rectangle rec(5, 3, 1, 2);

	std::cout << rec.stringify();
    return 0;
}

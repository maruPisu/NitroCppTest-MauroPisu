#include "rectangle.h"
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

int main(){
	Rectangle rec(5, 3, 30, 15);
	Rectangle big(15, 13, 10, 10);

	std::cout << rec.stringify();
	std::cout << big.stringify();
	auto inter = rec.intersection(big);
	std::cout << inter.stringify();
    return 0;
}

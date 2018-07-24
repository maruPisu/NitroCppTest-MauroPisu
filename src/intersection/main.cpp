#include "rectangle.h"
#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;

int main(int argc, char *argv[]){
	if(argc < 2){
		cout << "please specify the input file" << endl;
		exit(0);
	}
	//read file
	string filename = argv[1];
	string line;
	ifstream myfile (filename);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file"; 
  
	Rectangle rec(5, 3, 30, 15);
	Rectangle big(15, 13, 10, 10);

	std::cout << rec.stringify();
	std::cout << big.stringify();
	auto inter = rec.intersection(big);
	std::cout << inter.stringify();
    return 0;
}

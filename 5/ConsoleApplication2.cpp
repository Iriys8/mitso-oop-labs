#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
int main()
{
	setlocale(0, "ru");
	int N = 15;
	std::string LINE = "line1";
	std::cout << std::setfill('$') << std::setw(N) << LINE << std::setw(N - LINE.length()) << " " << std::endl;
	int a = 0;
	std::cin >> std::hex >> a;
	std::cout << std::endl << a;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::ifstream in_file;
	std::ofstream out_file;
	
	in_file.open("file.txt", std::ios::binary);
	if (!(in_file.is_open())) {
		in_file.close();
		out_file.open("file.txt", std::ios::binary);
		srand((unsigned)time(NULL));
		int temp = rand(); // Visual studio moment
		for (int i = 0; i < 100; i++) {
			out_file << rand() % 100 - 50 << std::endl;
		}
		out_file.close();
		in_file.open("file.txt", std::ios::binary);
	}
	int first = 0, last = 0;
	std::string temp_string;
	std::getline(in_file, temp_string);
	first = stoi(temp_string);
	while (std::getline(in_file, temp_string)) {
		last = stoi(temp_string);
	}
	in_file.clear();
	in_file.seekg(0, std::ios::beg);
	out_file.open("out_file.txt", std::ios::binary);
	for (int i = 1; std::getline(in_file, temp_string); i++) {
		if (i % 3 == 0) {
			out_file << stoi(temp_string) * (first + last) * 2 << std::endl;
		}
		else {
			out_file << stoi(temp_string) << std::endl;
		}
	}
	in_file.close();
	out_file.close();
	return 0;
}

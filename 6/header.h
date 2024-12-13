#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <limits>

#ifndef LOGGER
#define LOOGER

class loggerStrategy {
public:
	virtual void use(std::string str) = 0;
};

class consoleLogger : public loggerStrategy {
public:
	void use(std::string str) {
		std::cout << std::endl << "Logger_message: " << str << std::endl;
	}
};

class simpleFileLogger : public loggerStrategy {
public:
	void use(std::string str) {
		std::ifstream check_file;
		std::ofstream out_file;
		std::string file_name;
		for (unsigned int i = 1; i < std::numeric_limits<int>::max(); i++) {
			file_name = "Logger_message " + std::to_string(i) + ".txt";
			check_file.open(file_name, std::ios::binary);
			if (!(check_file.is_open())) {
				check_file.close();
				out_file.open(file_name, std::ios::binary);
				out_file << str;
				out_file.close();
				return;
			}
			else {
				check_file.close();
			}
		}
	}
};

class timedFileLogger : public loggerStrategy {
public:
	void use(std::string str) {
		std::ifstream check_file;
		std::ofstream out_file;
		std::string file_name;
		for (unsigned int i = 1; i < std::numeric_limits<int>::max(); i++) {
			file_name = "Logger_message " + std::to_string(i) + ".txt";
			check_file.open(file_name, std::ios::binary);
			if (!(check_file.is_open())) {
				check_file.close();
				out_file.open(file_name, std::ios::binary);
				time_t seconds = time(NULL);
				tm* timeinfo = localtime(&seconds);
				out_file << "Time : " << std::to_string(1900 + timeinfo->tm_year) << "." << std::to_string(1 + timeinfo->tm_mon) <<
					"." << std::to_string(timeinfo->tm_mday) << " " << std::to_string(timeinfo->tm_hour) <<
					":" << std::to_string(timeinfo->tm_min) << ":" << std::to_string(timeinfo->tm_sec) << std::endl <<str;
				out_file.close();
				return;
			}
			else {
				check_file.close();
			}
		}
	}
};

class logger {
protected:
	loggerStrategy* current_strat;
public:
	virtual void setStrategy(loggerStrategy* strat) = 0;
	virtual void log(std::string str) = 0;

};

class userLogger : logger {
public:
	void setStrategy(loggerStrategy* strat) {
		current_strat = strat;
	}

	void log(std::string str) {
		current_strat->use(str);
	}
};
#endif //LOGGER
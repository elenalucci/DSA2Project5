//Elena Lucci COP4534
#ifndef LCS_HPP
#define LCS_HPP
#include <string>
#include <iostream>
#include <fstream>

class LCS{

	private:
		std::string s1;
		std::string s2;
		int c[1000][1000];
		std::ifstream inFile;
		int m;
		int n;
		void LoadTwoStrings();
		//void LoadMultiStrings();
		

	public:
		LCS();
		void RunLCS(std::string s1, std::string s2);
		void PrintLCS(int x, int y);
		void RunPart1();
		//void RunPart2();

};
#endif

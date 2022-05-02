//Elena Lucci COP4534
#include "LCS.hpp"

LCS::LCS(){
	m = 0;
	n = 0;	
}

void LCS::RunLCS(std::string s1, std::string s2){

	for(int i = 1; i < m +1; i++){
		c[i][0] = 0;
	}
	for(int j = 0; j < n + 1; j++){
		c[0][j] = 0;
	}

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(s1[i] == s2[j]){
				c[i][j] = c[i-1][j-1] +1;
			}
			else{
				if(c[i-1][j] >= c[i][j-1]){
					c[i][j] = c[i-1][j];
				}
				else{
					c[i][j] = c[i][j-1];
				}
			}
		}
	}
	
}

void LCS::PrintLCS(int i, int j){
	if(i==0 || j==0){
		return;
	}
	if(s1[i] == s2[j]){
		PrintLCS((i-1),(j-1));
		std::cout << s1[i];
	}
	else if(c[i-1][j] >= c[i][j-1]){
		PrintLCS((i-1),j);
	}
	else{
		PrintLCS(i,(j-1));
	}
}

void LCS::RunPart1(){
	LoadTwoStrings();
	RunLCS(s1,s2);

	std::cout << "STRING 1" << std::endl;
	std::cout << s1 << std::endl;
	std::cout << std::endl;

    std::cout << "STRING 2" << std::endl;
    std::cout << s2 << std::endl;
	std::cout << std::endl;

    std::cout << "size of String 1 : " << m << std::endl;
    std::cout << "size of String 2 : " << n << std::endl;
	std::cout << std::endl;
	
	std::cout << "LONGEST COMMON SUBSEQUENCE" << std::endl;
	PrintLCS(m,n);
	std::cout << std::endl;

}

void LCS::LoadTwoStrings(){
	inFile.open("twoStrings.txt");
	inFile >> s1;
	inFile >> s2;
	inFile.close();

	m = s1.size();
	n = s2.size();

	std::string temp = " ";
    temp += s1;
    s1 = temp;
    temp = " ";
    temp += s2;
    s2 = temp;

}

void LCS::LoadMultiStrings(){
	
	std::string tempString;

	inFile.open("multiStrings.txt");
	inFile >> numStrings;
	while(!inFile.eof()){
		inFile >> tempString;
	}

	inFile.close();


}

void LCS::RunPart2(){
	
	std::cout << std::endl << std:: endl;
	std::cout << "PART 2";
	std::cout << std::endl << std::endl;


	LoadMultiStrings();

	std::cout << "     01   02   03   04   05   06   07   08" << std::endl;
	std::cout << "01   -    D    D    D    L    D    M    D" << std::endl;
    std::cout << "02   -    -    D    D    D    D    D    H" << std::endl;
 	std::cout << "03   -    -    -    M    D    M    D    D" << std::endl;	
	std::cout << "04   -    -    -    -    D    H    D    D" << std::endl;
	std::cout << "05   -    -    -    -    -    D    M    D" << std::endl;
 	std::cout << "06   -    -    -    -    -    -    D    D" << std::endl;
 	std::cout << "07   -    -    -    -    -    -    -    D" << std::endl;
	std::cout << "08   -    -    -    -    -    -    -    -" << std::endl;
}

/*FullName: Shamisa Kaspour
  StudentNum: 9423087*/

#include<iostream>
#include<string>
#include<fstream>

int main() {
	std::fstream inFile; // file
	std::string str; // words of file 
	std::string vowelChar{"iouea"}; 
	char chars[]{" ()!:;.,\"\'\n"}; // separators in a text

	inFile.open("Error_find.txt"); // open file
	if(!inFile)
		std::cout << "Unable to open inFile"; 

	while(inFile >> str) {
		/* delete chars from words */
		for(unsigned int i{0}; i < sizeof(chars)/sizeof(chars[0]); ++i) {
			std::string output;
			
			for(char c : str) 
				if(c != chars[i])
					output += c;
			
			str = output;
		}
		/* check them Only when word's length is greater than 4 */
		if(str.length() >= 5) {
			int count{0}; // number of silent characters
			for(size_t i{0}; i < str.length(); i++) {
				bool flag{false};
				for(size_t j{0}; j < vowelChar.length(); j++) {
					if(str[i] == vowelChar[j]) {
						count = 0;
						flag = true;
						break;
					}
				}
				if(flag == false) {
					count++;
					if(count == 5) {
						break;
					}
				}
			}
			
			/* wrong word */
			if(count == 5) {
				for(char c : str) {
					/* upper case check */ 
					if(c >= 'a' && c <= 'z') {
						std::cout << str << std::endl;
						break; 
					}
				}
			}	
		}
	}
	inFile.close();
	return 0;
}

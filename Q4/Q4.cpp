/*FullName: Shamisa Kaspour
  StudentNum: 9423087*/

#include<iostream>
#include<vector>

int main() {

  double num{1}; // input number
  double min{0};
  int i{0}; // iterator 
  int minIndex{0};
  std::vector<double> totalN; // numbers
  std::cout << "Please enter some numbers terminated by 0" << std::endl;

  while(num != 0) {
    std::cin >> num;
    totalN.push_back(num);
    i++;
  }

  /* Sort */
  for(int k{0}; k < i - 1; k++) {
    min = totalN[k];
    minIndex = k;
    
    /* find minimum */
    for(int j{k}; j < i - 1; j++) {
      if( min > totalN[j]) {
        min = totalN[j];
        minIndex = j;
      }
    }
    /* replace elements */
    if(k != minIndex) {
      totalN[minIndex] = totalN[k];
      totalN[k] = min;
    }
  }

  /* Print */
  for(int m{0}; m < i - 1; m ++)
    std::cout << totalN[m] << std::endl;
   
  return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int main() {
  std::ifstream plik("dane.txt");
  char ciag;
  std::vector<char> ciag2;
  while(plik >> ciag){
      ciag2.push_back(ciag);
      std::cout<<ciag;
    }

  std::cout<<"\n";
  for(int i = 0; i<ciag2.size(); i++){
      
  }
  return 0;
}

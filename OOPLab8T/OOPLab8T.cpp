#include <iostream>
#include "example.h"

int main() {
    SortFind<int> sf(5);
    sf.randomize();

    std::cout << "Original array: " << sf;
    int index = sf.find(sf[2]);
    if (index != -1) {
        std::cout << "Element found at index: " << index << std::endl;
    }
    else {
        std::cout << "Element not found" << std::endl;
    }

    SortFind<int> sf2(5);
    sf2.randomize();
    std::cout << "Second array: " << sf2;


    SortFind<int> sf3 = sf + sf2;
    std::cout << "Result of addition: " << sf3;


    SortFind<int> sf4 = sf - sf2;
    std::cout << "Result of subtraction: " << sf4;

    sf.countingSort();
    std::cout << "After counting sort: " << sf;

   
    SortFind<char*> sf_char(5);

    
    sf_char.randomize();
    std::cout << "Original char array: " << sf_char;

 
    sf_char.countingSort();
    std::cout << "After counting sort (char): " << sf_char;


   // const char* to_find = "abc";
    //index = sf_char.find(to_find);
   // if (index != -1) {
   //     std::cout << "Element '" << to_find << "' found at index: " << index << std::endl;
  //  }
   // else {
   //     std::cout << "Element '" << to_find << "' not found" << std::endl;
   // }

    return 0;
}

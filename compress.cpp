#include <iostream>
#include <cstring>
#include <map>
#include <vector>

int main(int argc, char* argv[]) {
    // your program's main execution code
    if (argc != 3) {
        cerr << "ERROR: Bad Input" << endl; exit(1);
    }

    FancyInputStream inputFile = new FancyInputStream(argv[1]);

    std::map<int, int> aMap;
    std::vector<int> freqVector;
    while (int byteValue = inputFile.read_byte() != -1) {
        for (int i = 0; i < inputFile.filesize(); i++) {
            aMap[i] = 0;
        }
        for (int i = 0; i < inputFile.filesize(); i++) {
            aMap[byteValue] = aMap[byteValue]++;
        }
        for (int i = 0; i < inputFile.filesize(); i++) {
            freqVector.push_back(aMap[i]);
        }
    }
    HCTree freqMap;
    freqMap.build(freqVector);

    FancyOutputStream outputFile = new FancyOutputStream(argv[2]);
    
    //encode(unsigned char symbol, FancyOutputStream & out)
    
    
    
}

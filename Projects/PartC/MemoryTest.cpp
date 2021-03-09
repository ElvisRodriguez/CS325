#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

#include "../PartB/Bus.h"
#include "Memory.h"

using namespace std;

void populateMemoryFile(string filename) {
    int lines = rand() % 100 + 32;
    fstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < 32; j++) {
                file << rand() % 2;
            }
            file << endl;
        }
    }
    file.close();
}

int main() {
    srand(time(0));
    populateMemoryFile("memory.txt");
    return 0;
}
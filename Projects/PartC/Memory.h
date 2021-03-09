#ifndef MEMORY_H
#define MEMORY_H

#include <fstream>
#include <string>

#include "../PartB/Bus.h"

using namespace std;

#define DEFAULT_FILENAME "memory.txt"

class Memory {
    private:
        Memory(const Memory&);
        void Read();
        void Write();
        void operator = (const Memory&);
        bool isBinaryString(string);
        Bus *bus;
        fstream memoryFile;
        string filename;
    public:
        Memory();
        void setBus(Bus&);
        void setMemoryFile(string);
        bool Valid();
        void Process();
};

Memory::Memory() {
    bus = NULL;
    filename = DEFAULT_FILENAME;
}

void Memory::setBus(Bus& bus) {
    this->bus = & bus;
}

void Memory::setMemoryFile(string filename) {
    this->filename = filename; 
}

bool Memory::isBinaryString(string line) {
    for (char bit: line) {
        if (!(bit == '0' or bit == '1')) {
            return false;
        }
    }
    return true;
}

bool Memory::Valid() {
    if (bus == NULL) {
        return false;
    }
    memoryFile.open(filename);
    if (memoryFile.fail()) {
        return false;
    }
    string line;
    while (getline(memoryFile, line)) {
        if (!(isBinaryString(line))) {
            return false;
        }
    }
    memoryFile.close();
    return true;
}

void Memory::Process() {
    
}

#endif //MEMORY_H
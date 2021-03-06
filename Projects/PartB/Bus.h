#ifndef BUS_H
#define BUS_H

#include <fstream>
#include <string>
#include <vector>

#define BUS_WIDTH 32
#define LINE_COUNT 3

using namespace std;

class Bus {
    private:
        Bus(const Bus&);
        bool lines[LINE_COUNT][BUS_WIDTH];
        void operator = (const Bus&);
    public:
        Bus();
        bool& operator [] (int);
};

Bus::Bus() {
    for (int i = 0; i < LINE_COUNT; i++) {
        for (int j = 0; j < BUS_WIDTH; j++) {
            lines[i][j] = false;
        }
    }
}

bool& Bus::operator [] (int index) {
    if (index < 0 || index > LINE_COUNT * BUS_WIDTH) {
        throw "Out of bounds.";
    }
    int line_type = index / BUS_WIDTH;
    int bit = index % BUS_WIDTH;
    return lines[line_type][bit];
}

#endif //BUS_H
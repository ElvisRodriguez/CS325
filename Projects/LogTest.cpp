#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Log.h"

int main() {
    Log logger("test_logs.txt");
    string testStrings[5] = {
        "0111001011010", "FF00FABCD", "Bad String", "0", "1"
    };
    vector<bool> testBinaryArray_A = {true, false, true, false};
    vector<bool> testBinaryArray_B = {true, true, true, true};
    vector<bool> testBinaryArray_C = {false, false, false, false};
    for (string testString: testStrings) {
        logger.write(testString);
    }
    logger.write(testBinaryArray_A);
    logger.write(testBinaryArray_B);
    logger.write(testBinaryArray_C);
    return 0;
}

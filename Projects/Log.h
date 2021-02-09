#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>
#include <vector>

#define DEFAULT_FILENAME "logs.txt"

using namespace std;

class Log {
    private:
        string filename;
        ofstream output;
        ifstream input;
        bool checkBinaryString(string);
        string determineLogIdentifier();
    public:
        Log();
        Log(string);
        void write(string);
        void write(vector<bool>&);

};

Log::Log() {
    /*
        If filename is not provided, DEFAULT_FILENAME will be used instead.
    */
    this->filename = DEFAULT_FILENAME;
}

Log::Log(string filename) {
    /*
        filename must be a .txt file, will fallback to DEFAULT_FILENAME
        if it is not.
    */
    if (filename.find(".txt") != string::npos) {
        this->filename = filename;
    }
    else {
        this->filename = DEFAULT_FILENAME;
    }
}

bool Log::checkBinaryString(string binaryString) {
    /*
        Verifies that binaryString is a string consisting of only 0s and 1s.
    */
    if (binaryString == "") {
        return false;
    }
    for (char c: binaryString) {
        if (c != '1' && c != '0') {
            return false;
        }
    }
    return true;
}

string Log::determineLogIdentifier() {
    /*
        Creates an identifier for a log entry using the current number of
        lines in the Log object's log file.
        All identifiers will start with "0x"
        If the total line number of the file is less then 10, then identifier
        is padded with an extra 0. 
    */
    int totalFileLines = 0;
    string currentLine;
    string identifier = "0x";
    this->input.open(this->filename);
    while (getline(this->input, currentLine)) {
        if (!currentLine.empty()) {
            totalFileLines++;
        }
    }
    this->input.close();
    if (totalFileLines < 10) {
        identifier += "0";
    }
    identifier += to_string(totalFileLines);
    return identifier;
}

void Log::write(string binaryString) {
    /*
        Writes binaryString with identifier logIdentifier to this->filename if
        and only if binaryString is a proper binary string.
    */
    if (checkBinaryString(binaryString)) {
        string logIdentifier = determineLogIdentifier();
        this->output.open(this->filename, ofstream::app);
        this->output << logIdentifier << " " << binaryString << endl;
        this->output.close();
    }
}

void Log::write(vector<bool>& binaryArray) {
    /*
        Converts binaryArray to a binary string then passes binaryString to
        Log::write(string).
    */
    string binaryString = "";
    for (bool binaryDigit: binaryArray) {
        if (binaryDigit) {
            binaryString += "1";
        } else {
            binaryString += "0";
        }
    }
    write(binaryString);
}

#endif //LOG_H
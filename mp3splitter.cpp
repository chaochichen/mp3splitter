// mp3splitter.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <string>

using namespace std;

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

std::vector<std::string> split(const std::string& s, const std::string& delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
 
    size_t index1 = 0;
    size_t index2 = s.find(delimiter);
    while(index2 != std::string::npos) 
    {
        token = s.substr(index1, index2-index1);
        trim(token);
        if (token.size() > 0)
            tokens.push_back(token);
        index1 = index2+delimiter.size();
        index2 = s.find(delimiter, index1);
    }
    token = s.substr(index1);
    tokens.push_back(token);
    return tokens;
}

int toSeconds(string ts)
{
    vector<string> s = split(ts, ":");
    int index = s.size() - 1;
    int sec = stoi(s[index--]);
    int min = stoi(s[index--]);
    int hour = 0;
    if (index >= 0)
    {
        hour = stoi(s[index]);
    }
    return sec + min * 60 + hour * 3600;
}

int main(int argc, char**argv)
{
    if (argc < 4)
    {
        cerr << "Usage: " << argv[0] << " inputfile.txt input.mp3 \"delimiter\"\n";
        exit(-1);
    }
    std::string delimiter = argv[3];
    std::string mp3file = argv[2];
    std::ifstream infile(argv[1]);
    std::string line;
    string artist, title, ts = "";
    while (std::getline(infile, line))
    {
        vector<string> s = split(line, delimiter);
        if (ts.size() > 0)
        {
            string nextTs = s[3];
            cout << "ffmpeg -i " << mp3file << " -acodec copy -ss " << ts
                << " -t " << toSeconds(nextTs) - toSeconds(ts)
                << " -metadata Title=\"" << title << "\" -metadata Artist=\"" << artist << "\" \"" << title << ".mp3\"" << endl;
        }
        title = s[1];
        artist = s[2];
        ts = s[3];
    }
    cout << "ffmpeg -i " << mp3file << " -acodec copy -ss " << ts
        << " -metadata Title=\"" << title << "\" -metadata Artist=\"" << artist << "\" \"" << title << ".mp3\"" << endl;
    return 0;
}


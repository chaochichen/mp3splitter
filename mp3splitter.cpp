// mp3splitter.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
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

static std::string& buildcmd(std::string& retVal,
                const std::string& mp3file,
                const std::string& title,
                const std::string& artist, 
                const std::string& ts, 
                const std::string& nextTs, 
                const std::string& albumTitle, 
                const std::string& albumArt)
{
    retVal = "ffmpeg -ss " + ts;
    if (nextTs.size() > 0)
    {
        char buffer[10];
        sprintf(buffer, "%d", toSeconds(nextTs) - toSeconds(ts));
        retVal += " -t ";
        retVal += buffer;
    }
    retVal += (" -i " + mp3file);
    if (albumArt.size() > 0)
    {
        retVal += (" -i " + albumArt + " -map 0:0 -map 1:0 -c copy -id3v2_version 3 -metadata:s:v title=\"Album cover\" -metadata:s:v comment=\"Cover (Front)\" ");
    }
    else
    {
        retVal += " -acodec copy";
    }
    retVal += (" -metadata Title=\"" + title + "\" -metadata Artist=\"" + artist +"\"");
    if (albumTitle.size() > 0)
    {
        retVal += (" -metadata Album=\"" + albumTitle + "\"");
    }
    retVal += (" \"" + title + ".mp3\"\n");
    return retVal;
}

int main(int argc, char**argv)
{
    if (argc < 4)
    {
        cerr << "Usage: " << argv[0] << " inputfile.txt input.mp3 \"delimiter\" albumTitle albumArtFile\n";
        exit(-1);
    }
    std::string album = "";
    if (argc > 4)
    {
        album = argv[4];
    }
    std::string albumArt = "";
    if (argc > 5)
    {
        albumArt = argv[5];
    }
    std::string delimiter = argv[3];
    std::string mp3file = argv[2];
    std::ifstream infile(argv[1]);
    std::string line;
    string artist, title, ts = "";
    std::string cmd;
    while (std::getline(infile, line))
    {
        vector<string> s = split(line, delimiter);
        size_t size = s.size();
        if (ts.size() > 0)
        {
            string nextTs = s[size-1];
            cout << buildcmd(cmd, mp3file, title, artist, ts, nextTs, album, albumArt);
        }
        title = s[size-3];
        artist = s[size-2];
        ts = s[size-1];
    }
    cout << buildcmd(cmd, mp3file, title, artist, ts, "", album, albumArt);
    return 0;
}

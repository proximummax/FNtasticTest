

#include <algorithm>
#include <map>
#include <string>


std::string EncodeString(const std::string& Word)
{
    std::string LowerCaseWord = Word;
    std::transform(LowerCaseWord.begin(), LowerCaseWord.end(), LowerCaseWord.begin(), ::tolower);

    std::map<char, int> CountingTable;
    
    for (const char WordSymbol : LowerCaseWord)
    {
        CountingTable[WordSymbol] += 1;
    }
    
    std::string EncodingResult;
    
    for(const char WordSymbol : LowerCaseWord)
    {
        EncodingResult += CountingTable[WordSymbol] == 1 ? "(" : ")";
    }
    
    return  EncodingResult;
}


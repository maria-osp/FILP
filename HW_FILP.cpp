#include <iostream>
#include <fstream>

#include <windows.h>
#include <map>
#include <String>
#include <set>
#include <cctype>
#include <ctime>


int main()
{
    HANDLE f = CreateFile(L"book.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    DWORD size = GetFileSize(f, NULL);

    std::cout << "Size: " << size << "\n";

    char* Text = new char[size + 1];
    DWORD r;
    ReadFile(f, Text, size, &r, NULL);
    CloseHandle(f);
    
    unsigned int start = clock();

    std::string word = "";
    std::map <std::string, int> dict;

    for (int i = 0; i < size; i++) {
        if (isalpha(Text[i])) {
            word += tolower(Text[i]);
            continue;
        }
        if (word == "")
            continue;
        if (dict.find(word) == dict.cend()) 
                dict[word] = 1;
        else
            dict[word]++;
        word = "";
    }

    unsigned int end = clock();
    std::cout << "Time: " << end - start << "\n";


    delete[] Text;
    return 0;
}

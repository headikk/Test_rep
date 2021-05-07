#pragma once

#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
 
inline void WriteFile(const std::string& filename, const std::vector<uint8_t>& data) {
    std::ofstream fout{filename, std::ios::binary};
    for (const auto& d : data)
        fout << d;
}

inline decltype(auto) ReadFile(const std::string& filename) {
    std::ifstream fin{filename, std::ios::binary};
    std::vector<uint8_t> data;
    uint8_t b;
    while(fin >> b) data.push_back(b);
    return data;
}

/*int main()
{
    
    std::cout << static_cast<bool>(data == getfile);
    return 0;
}*/
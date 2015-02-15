#ifndef VS_UTF16_H
#define VS_UTF16_H

#include <string>
#include <vector>

#include <windows.h>


static std::string utf16_to_bytes(const std::wstring &wstr) {
    int required_size = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
    std::vector<char> buffer;
    buffer.resize(required_size);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, buffer.data(), required_size, NULL, NULL);
    return std::string(buffer.data());
}

static std::wstring utf16_from_bytes(const std::string &str) {
    int required_size = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
    std::vector<wchar_t> wbuffer;
    wbuffer.resize(required_size);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wbuffer.data(), required_size);
    return std::wstring(wbuffer.data());
}

#endif

#pragma once

#include <Windows.h>
#include <string>

extern std::wstring s2ws(const std::string &s);
extern std::string CWD();
extern bool file_exists(std::string path);
extern bool start_process(const char* application_name);

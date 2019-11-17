#include "Utils.h"

std::wstring s2ws(const std::string &s) {
	// https://stackoverflow.com/a/27296

	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

std::string CWD() {
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type position = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, position + 1);
}

bool file_exists(std::string path) {
	std::string target = CWD() + path;

	if (FILE *f = fopen(target.c_str(), "r")) {
		fclose(f);
		return true;
	}
	else {
		return false;
	}
}

bool start_process(const char* application_name) {
	STARTUPINFO startup_info;
	PROCESS_INFORMATION process_info;

	std::string application_full_path = CWD() + std::string(application_name);

	ZeroMemory(&startup_info, sizeof(startup_info));
	startup_info.cb = sizeof(startup_info);
	ZeroMemory(&process_info, sizeof(process_info));

	TCHAR cmd[1024] = { 0 };
	mbstowcs(cmd, application_full_path.c_str(), 1024);

	bool success = CreateProcess(NULL, cmd, 0, 0, 0, 0, 0, 0, &startup_info, &process_info);

	if (!success) {
		System::Windows::Forms::MessageBox::Show(
			"Failed to open executable.",
			"Catastrophic failure",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error
		);

		return false;
	}

	// WaitForSingleObject(process_info.hProcess, 1000);

	CloseHandle(process_info.hProcess);
	CloseHandle(process_info.hThread);

	return true;
}

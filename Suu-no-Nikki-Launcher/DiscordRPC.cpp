#include "DiscordRPC.h"
#include "MapNames.h"
#include "Utils.h"

DiscordEventHandlers handlers;
DiscordRichPresence presence;

void init_discord() {
	memset(&handlers, 0, sizeof(handlers));
	Discord_Initialize(RPC_APP_ID, &handlers, 1, NULL);
}

void update_presence() {
	Discord_UpdatePresence(&presence);
}

void init_presence() {
	memset(&presence, 0, sizeof(presence));
	presence.state = "Initializing...";
	presence.details = "Initializing...";
	update_presence();
}

void reset() {
	Discord_ClearPresence();
	Discord_Shutdown();
}

int get_pid_by_name(const char *name) {
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	std::wstring wname = s2ws(name);

	if (Process32First(snapshot, &entry)) {
		while (Process32Next(snapshot, &entry)) {
			if (std::wstring(entry.szExeFile) == wname) {
				return entry.th32ProcessID;
			}
		}
	}

	return 0;
}

void initialize_rpc_service() {
	init_discord();
	init_presence();

	DWORD p_id = get_pid_by_name(EXEC_NAME);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, false, p_id);

	while (get_pid_by_name(EXEC_NAME)) {
		// Run this loop until game is closed

		DWORD current_map;
		DWORD max_hp;
		DWORD current_hp;

		DWORD new_current_map;
		DWORD new_max_hp;
		DWORD new_current_hp;

		bool should_update = false;

		ReadProcessMemory(handle, (LPCVOID)CURRENT_MAP_OFFSET, &new_current_map, sizeof(new_current_map), NULL);
		ReadProcessMemory(handle, (LPCVOID)MAX_HP_OFFSET, &new_max_hp, sizeof(new_max_hp), NULL);
		ReadProcessMemory(handle, (LPCVOID)CURRENT_HP_OFFSET, &new_current_hp, sizeof(new_current_hp), NULL);

		if (new_current_map != current_map) {
			current_map = new_current_map;
			should_update = true;
		}

		if (new_max_hp != max_hp) {
			max_hp = new_max_hp;
			should_update = true;
		}

		if (new_current_hp != current_hp && (int)new_current_hp <= (int)new_max_hp) {
			current_hp = new_current_hp;
			should_update = true;
		}

		if (should_update) {
			std::string details = "Currently in: " + maps[(int)current_map];
			std::string state = "HP: " + std::to_string(current_hp) + "/" + std::to_string(max_hp);
			presence.details = details.c_str();

			if ((int)current_map == TITLE_SCREEN_MAP_ID) {
				state = "Waiting...";
			}

			presence.state = state.c_str();
			update_presence();
			should_update = false;
		}

		Sleep(1000);
	}

	CloseHandle(handle);
	reset();
	exit(0);
}

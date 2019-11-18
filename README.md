# Suu no Nikki Launcher

## Project Description

This is a CLI/CLR (Common Language Interface/Runtime) desktop application that serves as the launcher for the game Sue's Diary. It is written in C++.

## Requirements
  * Visual Studio (2017 or earlier recommended, older versions are not guaranteed to work) with C++ CLI/CLR support
  * A copy of Sue's Diary - TBD

## Getting Started

### Clone the repository

```sh
git clone git@github.com:jozsefsallai/Suu-no-Nikki-Launcher.git
cd Suu-no-Nikki-Launcher
```

### Open `Suu-no-Nikki-Launcher.sln` in Visual Studio

At this point you should be ready to go. In the following section, I'll explain what each file is there for.

## Project Source Files

### Launcher.cpp

Contains the main entry point of the program (`MainWin()`).

### Launcher.h

This file contains the form itself, with all the methods associated to it and its elements. You can open a Form Designer instance of this file in Visual Studio.

### Definitions.h

This header holds some constant definitions that are used across the project.

### DiscordRPC.cpp and DiscordRPC.h

This file wraps the function to start the Discord RPC connection for Rich Presence. It's used after pressing the "Play" button in the launcher.

### MapNames.cpp and MapNames.h

This file contains an `std::map<int, std::string>` that defines names for each map ID. It's used to display the map name in the Discord Rich Presence.

### Utils.cpp and Utils.h

Contains utility functions used across the project, such as a function that converts an `std::string` to an `std::wstring`.

## Dependencies

The `sdk` folder contains two header files that are the headers necessary to invoke functions from the Discord-RPC library. These are the original files from Discord's RPC library.

To save time and make dependencies less of a hassle, a `.dll` and a `.lib` file is included in the `sdk` folder. These were built using CMake, as described in [discordapp/discord-rpc](https://github.com/discordapp/discord-rpc). If you want you can build it on your own and use your own DLL and LIB file.

## License

The program is [licensed](https://github.com/jozsefsallai/Suu-no-Nikki-Launcher/blob/master/LICENSE) under the MIT license. Discord-RPC is [licensed](https://github.com/discordapp/discord-rpc/blob/master/LICENSE) under the MIT license. The names "Sue's Diary" and "Suu no Nikki", as well as some of the assets in this repository (such as the image assets) are copyright of József Sallai and other people involved.

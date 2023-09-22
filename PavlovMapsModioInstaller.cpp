/* Goals

   Installer
 []Check if dotnet is installed 
 []install main program from releases page to desired location
 []install updater/installer to the same directory/folder
 []self delete

   Updater
 []Check either on startup of main program or startup of computer
 []Check exe version and compare to github release version, tbd how, thinking download latest exe and check if the version is greater
 []get directory of self

  Overall
 []comment on everything to document decently
 []Learn how to properly use/make headers

#include <iostream> //Basic input/output
#include <sys/stat.h> //file stuff iirc
#include <stdlib.h>
#include <string> //Strings
#include <Windows.h> //System commands
#include <direct.h>
#include <chrono> //delay stuff
#include <thread> 
#pragma comment(lib, "urlmon.lib") //Need to remember what this does */
#include "Installer.hpp"
using namespace std; // for ticking off veteran c++ people who think using namespace std is weird or something 

int main();
{
bool installed false;
installed.exists() 
}
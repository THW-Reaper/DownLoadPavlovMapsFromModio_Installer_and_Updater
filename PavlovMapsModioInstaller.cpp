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

#include <stdlib.h>
#include <string> //Strings
#include <Windows.h> //System commands
#include <direct.h>
#include <chrono> //delay stuff
#include <thread> 
#pragma comment(lib, "urlmon.lib") //Need to remember what this does */

#include <sys/stat.h> //file stuff, used in our case for checking if dotnet is installed
#include <iostream> //Basic input/output
#include <filesystem>
#include "Installer&updater.hpp"
using namespace std; 
int StartInstall(bool begininstall);

int main()
{
  system("title PavlovModioDownloaderInstaller");
  bool installed = std::filesystem::exists("DownloadPavlovMapsFromModIo.exe");
  if (installed = false)
  {
    StartInstall (true);
  } 
  else
  {
      cout << "ModioDownloader found on your system, attempting to update" << endl;
      bool status;
      status = Update(true);
      cout << "Update Successful:" << status;
    
  }
}


int StartInstall (bool begininstall)
{
  
    // Path to Dotnet directory
    const char* dotnetdir = "C:/Program Files/dotnet";
    // Structure which would store the metadata
    struct stat sb;
 
    // Calls the function with path as argument
    // If the file/directory exists at the path returns 0
    // If block executes if path exists
    if (stat(dotnetdir, &sb) == 0)
    {
        string installdir;
        cout <<"Welcome to the Pavlov Map Auto Downloader"<<endl<<"Please set your desired install path for Pavlov Map/Mod Downloader"<<endl;
        cin >> installdir; //sets target install dir
        cout <<"Attempting to install at "<<installdir<<endl;
        Install(installdir); //Calls Install function in the Installer Header File
        exit(0);
    }
    else
      {
        dotnet(false); //Installs dotnet runtime
      }
        
 
    return 0;
}

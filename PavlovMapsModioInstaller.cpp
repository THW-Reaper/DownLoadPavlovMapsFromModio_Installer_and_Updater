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
#include <filesystem>
#include "Installer.hpp"
using namespace std; 
int main()
{
  bool installed false;
  installed.exists() 
}


int StartInstall();
{
  system("title PavlovModioDownloaderInstaller");
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
        Install(installdir)
        exit(0);
    }
    else
    dotnet(false)
        {
            
            for (bool valid = false; valid = false;)
            {
                char installQuery;
                cout << "Dotnet 6 Framwork not found, would you like to install it?[Y/N]";
                cin >> installQuery;
                if (installQuery == y)
                {
                    system("winget install Microsoft.DotNet.DesktopRuntime.6");
                    valid = true;
                }
                else if (installQuery == Y)
                {
                    system("winget install Microsoft.DotNet.DesktopRuntime.6");
                    valid = true;
                }
                else if (installQuery == n)
                {
                    cout << "Terminating program... I'll be back!";
                    sleep_for(5s);
                    exit(0);
                }
                else if (installQuery == N)
                {
                    cout << "Terminating program... I'll be back!";
                    sleep_for(5s);
                    exit(0);
                }
                else
                {
                    cout << "Invalid Command!";
                }
            }
        }
        
 
    return 0;
}

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
#include <stdlib.h>
#include <string>//strings 
#include <Windows.h>//system commands
#include <direct.h>
#include <chrono> //Time
#include <thread> //Threads
#pragma comment(lib, "urlmon.lib")
using namespace std;
void StartInstall();

int main()
{
  system("title PavlovModioDownloaderInstaller");
  bool installed = std::filesystem::exists("DownloadPavlovMapsFromModIo.exe");
  if (installed = false)
  {
    StartInstall ();
  } 
  else
  {
      cout << "ModioDownloader found on your system, attempting to update" << endl;
      Update();
  }
}


void StartInstall ()
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
        dotnet(); //Installs dotnet runtime
      }
        
 
    return;
}

int Install(string installdir)
{
        //sets command line strings, Way more vars than necessary
        installdir.assign(installdir + "\\PavlovModioDownloader");
        string createinstalldircmd = "md " + installdir;//Creates a folder at the specified directory 
        string rawurl = " https://github.com/RainOrigami/DownloadPavlovMapsFromModIo/releases/latest/download/DownloadPavlovMapsFromModIo.exe";
        string updaterrawurl = " https://github.com/THW-Reaper/DownLoadPavlovMapsFromModio_Installer_and_Updater/releases/latest/download/Installer.exe";
        string installdir_and_url = installdir + rawurl;
        string Updaterinstalldir_and_url = installdir + updaterrawurl;
        string installdircmd = "curl -O --output-dir " + installdir_and_url;
        string installupdatercmd = "curl -o --output-dir Updater.exe " + Updaterinstalldir_and_url;
        //commands
        system(createinstalldircmd.c_str());
        cout << "File Path Created, downloading file";
        system(installdircmd.c_str());
        system(installupdatercmd.c_str());
        std::this_thread::sleep_for(5s);
        system("start DownloadPavlovMapsFromModIo.exe"); //Boots the installed exe
        cout << "Download Successful!"<<endl;
        std::this_thread::sleep_for(10s);
        exit(0); //exits program after delay
}

void dotnet()
{     
        for (bool valid = false; valid = false;)
            {
                char installQuery;
                cout << "Dotnet 6 Framwork not found, would you like to install it?[Y/N]";
                cin >> installQuery;
                if (installQuery == 'y')
                {
                    system("winget install Microsoft.DotNet.DesktopRuntime.6");
                    valid = true;
                }
                else if (installQuery == 'Y')
                {
                    system("winget install Microsoft.DotNet.DesktopRuntime.6");
                    valid = true;
                }
                else if (installQuery == 'n')
                {
                    cout << "Terminating program... I'll be back!";
                    sleep_for(5s);
                    exit(0);
                }
                else if (installQuery == 'N')
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

void Update()
{   //Since the program and updater are at the same directory, the program should already be cd'd to the same folder as the program
    system("curl -o https://github.com/RainOrigami/DownloadPavlovMapsFromModIo/releases/latest/download/DownloadPavlovMapsFromModIo.exe");
    std::this_thread::sleep_for(5s);
}
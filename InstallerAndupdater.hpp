/*We Could Just put these all as functions of the main file, but I wanted to learn how headers worked*/
#include <iostream>
#include <sys/stat.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include <direct.h>
#include <chrono> //Time
#include <thread> //Threads
#pragma comment(lib, "urlmon.lib")
#pragma once
using namespace std;

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
        for (bool valid = false/*valid answer var*/; valid = false;)
            {
            string installQuery; //Need to switch this to char var at some point
            cout << "DotNet 6 Framwork not found, would you like to install it?[Y/N]";
            cin >> installQuery;
            if (installQuery == "y")
            {
                system("winget install Microsoft.DotNet.DesktopRuntime.6");
                valid = true;
            }
            else if (installQuery == "Y")
            {
                system("winget install Microsoft.DotNet.DesktopRuntime.6");
                valid = true;
            }
            else if (installQuery == "n")
            {
                cout << "Terminating program... I'll be back!";
                std::this_thread::sleep_for(5s);
                exit(0);
            }
            else if (installQuery == "N")
            {
                cout << "Terminating program... I'll be back!";
                std::this_thread::sleep_for(5s);
                exit(0);
            }
            else
            {
                cout << "Invalid Command!";
            }
            }
}

void Update()
{
    system("curl https://github.com/RainOrigami/DownloadPavlovMapsFromModIo/releases/latest/download/DownloadPavlovMapsFromModIo.exe");
}
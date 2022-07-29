#include <iostream>
#include <fstream>
#include "player.h"
using namespace std;

int main() {

    Player myPlayer;
    srand(time(nullptr));
    int command;

    cout << "---Player---" << endl;

    while(true)
    {
        showMenu();
        cout<<"Enter the command:";
        command = whatDo();

        if (command == LOAD)
        {
            string sFile;
            cout << "Enter file playlist directory:";
            cin >> sFile;
        //    sFile = "Untouchables.txt";
            ifstream file(sFile);
            if(file.is_open())
            {
                myPlayer.loadPlayList(sFile);
                file.close();
            }

            else
                cout<<"Error! Pls, check file '" << sFile << "'" << endl;
        }
        else if (command == EXIT)
            break;
        else if (command == unknownCommand)
            cout << "Error! Wrong command!" << endl;
        else if (myPlayer.getStatus() == EMPTY)
            cout << "PlayList - empty!" << endl;
        else
        {
            if (command == PLAY)
            {
                if (myPlayer.getStatus() == STOP)
                {
                    cout << "Enter track name:";
                    string trackName;
                    cin >> trackName;
                    myPlayer.play(trackName);
                }
                else if (myPlayer.getStatus() == PAUSE)
                    myPlayer.play(myPlayer.getCurrentTrack());
            }
            else if (command == STOP)
            {
                if (myPlayer.getStatus() == PLAY || myPlayer.getStatus() == PAUSE)
                {
                    cout << "Stop play, last track:" << myPlayer.getCurrentTrack() << endl;
                    myPlayer.stop();
                }
                else
                    cout << "There are are no track on play or pause" << endl;
            }
            else if (command == PAUSE)
            {
                if (myPlayer.getStatus() == PLAY)
                {
                    cout << "Pause track:" << myPlayer.getCurrentTrack() << endl;
                    myPlayer.pause();
                }
                else if (myPlayer.getStatus() == STOP)
                    cout << "There are not track for pause" << endl;
                else if (myPlayer.getStatus() == PAUSE)
                    cout << "Track:" << myPlayer.getCurrentTrack() << " - already pause!" << endl;
            }
            else if (command == NEXT)
                myPlayer.next();
        }
    }
    cout << "---Bye, bye!---" << endl;
    return 0;
}

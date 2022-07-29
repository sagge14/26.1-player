//
// Created by Sg on 24.07.2022.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include "player.h"
using namespace std;

void operator >> (ifstream& iff, Track &t) {
iff>>t.N>>t.Name>>t.time>>t.creatDAte;
}
void operator << (ostream& out, Track &t) {
out<<"Track N:"<<t.N<<" Name:"<<t.Name<<" Time:"<<t.time<<" Created date:"<<t.creatDAte<<endl;
}
string Track::getName() const {
    return Name;
}
int Player::getStatus() const {
    return status;
}
string Player::getCurrentTrack() const {
    return currentTrack;
}
int Player::getTrackCount() const {
    return (int)mPlayList.size();
}
void Player::play (const string& trackName) {
    if(mPlayList.count(trackName) == 0)
    {
        cout << "Error! this track is not exist!" << endl;
        return;
    }

    cout<<"Now play this track:";
    cout<<mPlayList[trackName];
    currentTrack = trackName;
    status = PLAY;
}
void Player::stop() {
    status = STOP;
}
void Player::next()
{
    auto it = mPlayList.begin();
    for (int i = 0; i < rand() % getTrackCount(); i++)
        it++;
    if (it->second.getName() == getCurrentTrack())
    {
        if(it == mPlayList.end())
            it = mPlayList.begin();
        else
            it++;
    }
    if(getStatus() == PAUSE)
    {
        play(it->second.getName());
        cout << "Pause track:" << getCurrentTrack() << endl;
        pause();
    }
    else
        play(it->second.getName());
}
void Player::pause() {
    status = PAUSE;
}

void Player::loadPlayList(const string &file) {
    cout << "---Tracks loading...---" << endl;
    ifstream filePlayList(file);
    while (true)
    {
        Track tTrack;
        filePlayList >> tTrack;
        if(!filePlayList.eof())
        {
            mPlayList.insert(pair<string, Track>(tTrack.getName(),tTrack));
            cout << tTrack;
        }
        else
            break;
    }
    status = STOP;
    cout << "---End tracks loading---" << endl;
}


int whatDo()
{
    string command;
    cin >> command;

    if(command =="play")
        return PLAY;
    else if(command == "pause")
        return PAUSE;
    else if (command == "stop")
        return STOP;
    else if (command == "next")
        return NEXT;
    else if (command == "load")
        return LOAD;
    else if (command == "exit")
        return EXIT;
    else
        return unknownCommand;
}
void showMenu()
{
    cout<<"Valid command format: 'load' for load playlist;" << endl;
    cout<<"                      'play' for play (thx cap);" << endl;
    cout<<"                      'stop' for stop play;" << endl;
    cout<<"                      'pause' for pause current track;" << endl;
    cout<<"                      'next' for next track;" << endl;
    cout<<"                      'exit' for exit." << endl;
}
//git hab11
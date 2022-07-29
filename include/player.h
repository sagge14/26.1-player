//
// Created by Sg on 24.07.2022.
//
#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std;
enum player
{
    EMPTY = -1,
    STOP,
    PLAY,
    PAUSE,
    NEXT,
    LOAD,
    EXIT,
    unknownCommand
};
class Track{
    int N = 0;
    string Name;
    string time;
    string creatDAte;
public:
    friend void operator<<(ostream& out, Track& t);
    friend void operator>>(ifstream& iff, Track& t);
    string getName() const;
};
class Player{
    string currentTrack;
    int status = EMPTY;
    map <string, Track> mPlayList;
    int getTrackCount() const;
public:
    Player() = default;
    void loadPlayList(const string& file);
    string getCurrentTrack() const;
    int getStatus() const;
    void play(const string& trackName); // не получилось сделать этот метод константным почему-то(
    void stop();
    void pause();
    void next();
};
void operator >> (ifstream& iff, Track &t);
void operator << (ostream &out, Track &t);
int whatDo ();
void showMenu();
//github3
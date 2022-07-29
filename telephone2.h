//
// Created by Sg on 09.07.2022.
//
#include <iostream>
#include <string>
#include <map>
#pragma once
using namespace std;

enum  command {
    commandExit = -1,
    addRecord,
    smscallThrowNumber,
    smscallThrowName,
    unknownCommand,
};
class Record
{
    string name,telephone;
public:
    Record() = default;
    string getName() const;
    string getTelephone () const;
    void setName(string& s);
    void setTelephone(string& s);
};
class Telephone{
    map<string, Record> keyName{};
public:
    bool existName(const string& name) const;
    void addRecord(const Record& r);
    string getNumber(string& name); //c конст не работает
};
bool trueName(string& name);
bool trueTelephone(string& telephone);
int whatDo(Record& myRecord, string& word);
void showMenu();

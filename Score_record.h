#ifndef SCORE_RECORD_H
#define SCORE_RECORD_H

#include <QDebug>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Menu;

class Score_record {
public:
    Score_record();
    Score_record(int score);
    void saveScore(int score);
    void saveNickname(const string& nickname);
    vector<int> getLastTenScores() const;
    vector<int> getTopTenScores() const;
    string nickToSave;
    Menu *menu;


private:
    void loadScores();
    vector<int> scores;//all scores
    const string filename = "/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/cat_game/scores.txt";//txt file for scores
};

#endif

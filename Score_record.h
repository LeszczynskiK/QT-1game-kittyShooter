#ifndef SCORE_RECORD_H
#define SCORE_RECORD_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Score_record {
public:
    Score_record();
    Score_record(int score);
    void saveScore(int score);
    std::vector<int> getLastTenScores() const;
    std::vector<int> getTopTenScores() const;

private:
    void loadScores();
    std::vector<int> scores;//all scores
    const string filename = "/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/cat_game/scores.txt";//txt file for scores
};

#endif

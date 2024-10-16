#ifndef SCORE_RECORD_H
#define SCORE_RECORD_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Score_record {
public:
    Score_record(int score);
    void saveScore(int score);
    vector<int> getLastTenScores() const;
    vector<int> getTopTenScores() const;

private:
    void loadScores();
    void saveScores();

    vector<int> scores; // all scores
    const string filename = "scores.txt"; // txt file for scores
};

#endif // SCORE_RECORD_H

#include "Score_record.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Score_record::Score_record(int score) {
    loadScores(); // load scores in object loading time
    saveScore(score);
}

void Score_record::loadScores() {
    std::ifstream file(filename);
    if (!file.is_open()) { // if not opened
        std::cerr << "Failed to open scores file for loading!" << std::endl;
        return;
    }
    int score;
    while (file >> score) { // while reading scores
        scores.push_back(score); // add each score to vector
    }
    file.close();
}

void Score_record::saveScore(int score) {
    scores.push_back(score); // add new score to vector
    saveScores(); // save all to file
}

void Score_record::saveScores() {
    std::ofstream file(filename, std::ios::out | std::ios::trunc); // use trunc to overwrite
    if (!file.is_open()) { // if not opened
        std::cerr << "Failed to open scores file for saving!" << std::endl;
        return;
    }
    for (int score : scores) {
        file << score << std::endl; // each score in new line
    }
    file.close();
}

std::vector<int> Score_record::getLastTenScores() const {
    std::vector<int> lastTen;
    int start = std::max(0, static_cast<int>(scores.size()) - 10); // start point
    for (int i = start; i < scores.size(); ++i) {
        lastTen.push_back(scores[i]); // add to vector last 10 scores
    }
    return lastTen;
}

std::vector<int> Score_record::getTopTenScores() const {
    std::vector<int> topTen = scores; // vector copy
    std::sort(topTen.begin(), topTen.end(), std::greater<int>()); // sort from biggest to smallest
    topTen.resize(std::min(static_cast<size_t>(10), topTen.size())); // limit to top 10 scores
    return topTen;
}

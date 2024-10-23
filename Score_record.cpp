#include "Score_record.h"
#include <fstream>
#include <algorithm>


Score_record::Score_record() {
    loadScores();//Load scores when object is created
    string nickToSave;//predefinition
}

Score_record::Score_record(int score) : Score_record() {
    saveScore(score);//Save the score after loading
}

void Score_record::loadScores() {
    std::ifstream file(filename);
    if (!file.is_open()) {//If unable to open
        cerr << "Failed to open scores file for loading!" <<endl;
        return;
    }
    int score;
    while (file >> score) {//Read scores
        scores.push_back(score);//Add each score to the vector
    }
    file.close();
}

void Score_record::saveScore(int score) {
    ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open scores file for saving!" << endl;
        return;
    }

    cout << "Saving score: " << score << endl;
    file << score << endl;//Type new score
    if (file.good()) {
        cout << "Score saved successfully." << endl;
    } else {
        cerr << "Error while saving score!" << endl;
    }
    file.close();
}


vector<int> Score_record::getLastTenScores() const {
    vector<int> lastTen;
    int start = std::max(0, static_cast<int>(scores.size()) - 10);//Start point
    for (int i = start; i < scores.size(); ++i) {
        lastTen.push_back(scores[i]);//Add last 10 scores to vector
    }
    return lastTen;
}

vector<int> Score_record::getTopTenScores() const {
    vector<int> topTen = scores;//Copy of the vector
    sort(topTen.begin(), topTen.end(), greater<int>());//Sort from highest to lowest
    topTen.resize(std::min(static_cast<size_t>(10), topTen.size()));//Limit to top 10 scores
    return topTen;
}

void Score_record::saveNickname(const string& nickname) {
    ofstream file("/home/krzysiek89/Desktop/QT_aplikacje/Kitty_game/cat_game/nicknames.txt", ios::app);//file with nicknames
    if (!file.is_open()) {
        cerr << "Failed to open nicknames file for saving!" << endl;
        return;
    }

    qDebug() << "Nickname: " << nickname;
    string nickToSave = nickname.empty() ? "unknown" : nickname;
    qDebug() << "Nickname converted: " << nickToSave;

    if (!file.is_open()) {
        cerr << "Failed to open nicknames file for saving!" << endl;
        return;
    }
    file << nickToSave << endl;
    file.close();
    qDebug() << "Nickname saved to file:" << nickToSave;//Confirm saving
}

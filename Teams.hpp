#ifndef TEAMS_HPP
#define TEAMS_HPP

#include "player.hpp"
#include <vector>
using namespace std;

class Team {
protected:
    vector<Players*> players;
    int score;
    int wickets;
public:
    Team() : score(0), wickets(0) {}
    void addPlayer(Players* p) { players.push_back(p); }
    void updateScore(int s) { score += s; }
    void updateWickets() { wickets++; }
    int getScore() { return score; }
    int getWickets() { return wickets; }
    vector<Players*> getPlayers() { return players; }
    void displayPlayers();
    bool isAllOut();
    ~Team() {
        for (auto p : players) {
            delete p;
        }
    }
};

#endif

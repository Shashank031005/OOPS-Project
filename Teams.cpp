#include "Teams.hpp"

void Team::displayPlayers() {
    for (auto player : players) {
        player->display();
    }
}
bool Team::isAllOut() {
    return wickets == players.size();
}
string Team::getTopScorer() {
    int maxRuns = 0;
    string topScorer;
    for (auto p : players) {
        batsmen* b = dynamic_cast<batsmen*>(p);
        if (b && b->getRuns() > maxRuns) {
            maxRuns = b->getRuns();
            topScorer = b->getName();
        }
    }
    return topScorer;
}

string Team::getTopWicketTaker() {
    int maxWickets = 0;
    string topWicketTaker;
    for (auto p : players) {
        bowler* b = dynamic_cast<bowler*>(p);
        if (b && b->getWickets() > maxWickets) {
            maxWickets = b->getWickets();
            topWicketTaker = b->getName();
        }
    }
    return topWicketTaker;
}

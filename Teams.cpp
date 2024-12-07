#include "Teams.hpp"

void Team::displayPlayers() {
    for (auto player : players) {
        player->display();
    }
}
bool Team::isAllOut() {
    return wickets == players.size();
}

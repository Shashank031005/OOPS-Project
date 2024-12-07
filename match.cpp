#include "Match.hpp"

void Match::display() {
    cout << team1 << " Score: " << t1.getScore() << "/" << t1.getWickets() << endl;
    cout << "Batsmen Details:" << endl;
    t1.displayPlayers();

    cout << team2 << " Score: " << t2.getScore() << "/" << t2.getWickets() << endl;
    cout << "Bowler Details:" << endl;
    t2.displayPlayers();
}
void Match::displayOverSummary(Team* battingTeam, Team* bowlingTeam, int bowlerIndex) {
    cout << "---------- Over Summary ----------" << endl;
    cout << "Team Score: " << battingTeam->getScore() << "/" << battingTeam->getWickets() << endl;

    cout << "Batsmen Stats:" << endl;
    for (auto player : battingTeam->getPlayers()) {
        batsmen* b = dynamic_cast<batsmen*>(player);
        if (b) {
            cout << b->getName() << " - Runs: " << b->getRuns() << ", Balls: " << b->getBalls()
                 << ", 4s: " << b->getFours() << ", 6s: " << b->getSixes()
                 << (b->isOut() ? " (OUT)" : "") << endl;
        }
    }

    cout << "Bowler Stats:" << endl;
    bowler* b = dynamic_cast<bowler*>(bowlingTeam->getPlayers()[bowlerIndex]);
    if (b) {
        cout << b->getName() << " - Overs: " << b->getBalls() / 6 << "." << b->getBalls() % 6
             << ", Runs: " << b->getEconomy() << ", Wickets: " << b->getWickets() << endl;
    }
    cout << "----------------------------------" << endl;
}

void Match::playInnings(Team* battingTeam, Team* bowlingTeam, int targetScore=-1) {
    int strikerIndex, nonStrikerIndex, bowlerIndex;

    cout << "Choose a batsman on striker's end (index): ";
    cin >> strikerIndex;
    cout << "Choose a batsman on non-striker's end (index): ";
    cin >> nonStrikerIndex;

    for (int o = 0; o < overs; ++o) {
        cout << "Choose a bowler (index): ";
        cin >> bowlerIndex;

        int ballsRemaining = 6;
        while (ballsRemaining--) {
            int event;
            cout << "Enter runs/wickets (1, 2, 3, 4, 5, 6 for runs; 7 for Wicket; 8 for Extras; 9 for LegBye): ";
            cin >> event;

            switch (event) {
                case 1:
                case 3:
                case 5: { // Runs scored
                    battingTeam->updateScore(event);
                    batsmen* striker = dynamic_cast<batsmen*>(battingTeam->getPlayers()[strikerIndex]);
                    striker->setDetails(
                        striker->getRuns() + event, // Add runs
                        striker->getBalls() + 1,  // Increment balls faced
                        striker->getFours(),      // No new fours
                        striker->getSixes(),      // No new sixes
                        false);                   // Not out

                    bowler* activeBowler = dynamic_cast<bowler*>(bowlingTeam->getPlayers()[bowlerIndex]);
                    activeBowler->setDetails(
                        activeBowler->getBalls() + 1,      // Increment balls bowled
                        activeBowler->getEconomy() + event, // Add runs conceded
                        activeBowler->getMaidens(),       // No new maidens
                        activeBowler->getWickets());      // No new wickets

                    // Change the striker after odd runs
                    if (event % 2 != 0) {
                        swap(strikerIndex, nonStrikerIndex);
                    }
                    break;
                }

                case 2: { // Two runs scored
                    battingTeam->updateScore(event);
                    batsmen* striker = dynamic_cast<batsmen*>(battingTeam->getPlayers()[strikerIndex]);
                    striker->setDetails(
                        striker->getRuns() + 2, // Add runs
                        striker->getBalls() + 1,  // Increment balls faced
                        striker->getFours(),      // No new fours
                        striker->getSixes(),      // No new sixes
                        false);                   // Not out

                    bowler* activeBowler = dynamic_cast<bowler*>(bowlingTeam->getPlayers()[bowlerIndex]);
                    activeBowler->setDetails(
                        activeBowler->getBalls() + 1,      // Increment balls bowled
                        activeBowler->getEconomy() + 2, // Add runs conceded
                        activeBowler->getMaidens(),       // No new maidens
                        activeBowler->getWickets());      // No new wickets
                    break;
                }

                case 4: { // Four runs scored
                    battingTeam->updateScore(event);
                    batsmen* striker = dynamic_cast<batsmen*>(battingTeam->getPlayers()[strikerIndex]);
                    striker->setDetails(
                        striker->getRuns() + 4, // Add runs
                        striker->getBalls() + 1,  // Increment balls faced
                        striker->getFours() + 1,  // Increment fours
                        striker->getSixes(),      // No new sixes
                        false);                   // Not out

                    bowler* activeBowler = dynamic_cast<bowler*>(bowlingTeam->getPlayers()[bowlerIndex]);
                    activeBowler->setDetails(
                        activeBowler->getBalls() + 1,      // Increment balls bowled
                        activeBowler->getEconomy() + 4, // Add runs conceded
                        activeBowler->getMaidens(),       // No new maidens
                        activeBowler->getWickets());      // No new wickets
                    break;
                }

                case 6: { // Six runs scored
                    battingTeam->updateScore(event);
                    batsmen* striker = dynamic_cast<batsmen*>(battingTeam->getPlayers()[strikerIndex]);
                    striker->setDetails(
                        striker->getRuns() + 6, // Add runs
                        striker->getBalls() + 1,  // Increment balls faced
                        striker->getFours(),      // No new fours
                        striker->getSixes() + 1,  // Increment sixes
                        false);                   // Not out

                    bowler* activeBowler = dynamic_cast<bowler*>(bowlingTeam->getPlayers()[bowlerIndex]);
                    activeBowler->setDetails(
                        activeBowler->getBalls() + 1,      // Increment balls bowled
                        activeBowler->getEconomy() + 6, // Add runs conceded
                        activeBowler->getMaidens(),       // No new maidens
                        activeBowler->getWickets());      // No new wickets
                    break;
                }

                case 7: // Wicket
                    battingTeam->updateWickets();
                    if (battingTeam->isAllOut()) {
                        cout << "All-Out! End of the innings." << endl;
                        displayOverSummary(battingTeam, bowlingTeam, bowlerIndex);
                        return; // End the innings
                    }
                    cout << "Wicket! Choose a new batsman (index): ";
                    cin >> strikerIndex;
                    break;
            }
             if (targetScore != -1 && battingTeam->getScore() > targetScore) {
                cout << "Target reached! " << battingTeam->getName() << " wins by "
                     << (10 - battingTeam->getWickets()) << " wickets!" << endl;
                return; // Match ends as the second team wins
            }

            if (battingTeam->isAllOut()) {
                cout << "All-Out! End of the innings." << endl;
                displayOverSummary(battingTeam, bowlingTeam, bowlerIndex);
                return; // End the innings
            }
        }

        // Swap striker and non-striker at the end of the over
        swap(strikerIndex, nonStrikerIndex);

        // Display over summary
        displayOverSummary(battingTeam, bowlingTeam, bowlerIndex);
    }

    cout << "End of innings. Team Score: " << battingTeam->getScore() << "/" << battingTeam->getWickets() << endl;
}

void Match::startMatch() {
    int n;
    cout << "Enter number of overs: ";
    cin >> overs;

    // Adding players to Team 1
    cout << "Enter the number of batsmen in team " << team1 << ": ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        batsmen* b = new batsmen();
        cin>>(*b);
        t1.addPlayer(b);
    }

    cout << "Enter the number of bowlers in team " << team2 << ": ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        bowler* b = new bowler();
        cin>>(*b);
        t2.addPlayer(b);
    }

    // Adding players to Team 2
    cout << "Enter the number of batsmen in team " << team2 << ": ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        batsmen* b = new batsmen();
        cin>>(*b);
        t2.addPlayer(b);
    }

    cout << "Enter the number of bowlers in team " << team1 << ": ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        bowler* b = new bowler();
        cin>>(*b);
        t1.addPlayer(b);
    }

    cout << "Who is batting first? 1 -> " << team1 << ", 2 -> " << team2 << endl;
    cin >> n;

   Team* firstBattingTeam = (n == 1) ? &t1 : &t2;
    Team* firstBowlingTeam = (n == 1) ? &t2 : &t1;

    Team* secondBattingTeam = (n == 1) ? &t2 : &t1;
    Team* secondBowlingTeam = (n == 1) ? &t1 : &t2;

    // First innings
    cout << firstBattingTeam->getName() << " is batting first." << endl;
    playInnings(firstBattingTeam, firstBowlingTeam);

    // Second innings
    cout << secondBattingTeam->getName() << " is batting second." << endl;
    playInnings(secondBattingTeam, secondBowlingTeam, firstBattingTeam->getScore());

    // Determine winner
    if (secondBattingTeam->getScore() > firstBattingTeam->getScore()) {
        cout << secondBattingTeam->getName() << " wins by "
             << (10 - secondBattingTeam->getWickets()) << " wickets!" << endl;
    } else if (secondBattingTeam->getScore() == firstBattingTeam->getScore()) {
        cout << "Match is a tie!" << endl;
    } else {
        cout << firstBattingTeam->getName() << " wins by "
             << (firstBattingTeam->getScore() - secondBattingTeam->getScore()) << " runs!" << endl;
    }
}

void Match::displayMatchSummary(Team* team1, Team* team2) {
    cout << "\n===== MATCH SUMMARY =====" << endl;

    // Winner declaration
    if (team1->getScore() > team2->getScore()) {
        cout << "Winner: " << team1->getName() << endl;
    } else if (team2->getScore() > team1->getScore()) {
        cout << "Winner: " << team2->getName() << endl;
    } else {
        cout << "It's a Tie!" << endl;
    }

    // Top Scorer
    cout << "Top Scorer: " << team1->getTopScorer() << " from " << team1->getName() << " (Runs: " 
         << team1->getTopScorer() << ")" << endl;
    cout << "Top Scorer: " << team2->getTopScorer() << " from " << team2->getName() << " (Runs: " 
         << team2->getTopScorer() << ")" << endl;

    // Top Wicket Taker
    cout << "Top Wicket-Taker: " << team1->getTopWicketTaker() << " from " << team1->getName() << " (Wickets: " 
         << team1->getTopWicketTaker() << ")" << endl;
    cout << "Top Wicket-Taker: " << team2->getTopWicketTaker() << " from " << team2->getName() << " (Wickets: " 
         << team2->getTopWicketTaker() << ")" << endl;

    // Team 1 Details
    cout << team1->getName() << " Score: " << team1->getScore() << "/" << team1->getWickets() << endl;
    cout << "Batsmen Stats: " << endl;
    team1->displayPlayers();
    cout << "Bowler Stats: " << endl;
    team1->displayPlayers();

    // Team 2 Details
    cout << team2->getName() << " Score: " << team2->getScore() << "/" << team2->getWickets() << endl;
    cout << "Batsmen Stats: " << endl;
    team2->displayPlayers();
    cout << "Bowler Stats: " << endl;
    team2->displayPlayers();

    cout << "\n===== End of Match Summary =====" << endl;
}





#ifndef MATCH_HPP
#define MATCH_HPP

#include "Teams.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Match {
protected:
    string team1;
    string team2;
    int overs;
    Team t1;
    Team t2;
    double runRate;
    vector<vector<int>> flow;
    int extras;

public:
    // Default Constructor
    Match() 
        : team1("Team A"), team2("Team B"), overs(0), runRate(0.0), extras(0) {
        cout << "Match initialized with default values." << endl;
    }

    // Parameterized Constructor (Optional)
    Match(string t1, string t2, int o)
        : team1(t1), team2(t2), overs(o), runRate(0.0), extras(0) {
        cout << "Match initialized with teams: " << team1 << " vs " << team2 
             << " and overs: " << overs << endl;
    }

    // Methods
    void display();
    void startMatch();
};


#endif

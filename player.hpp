#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
using namespace std;

class Players {
protected:
    string name;
public:
    virtual void display() = 0;
    void setName(string n) { name = n; }
    string getName() { return name; }
    virtual ~Players() {}
};

class batsmen : public Players {
protected:
    int runs;
    int balls;
    double strikeRate;
    int fours;
    int sixes;
    bool wicket;
    int wickets=0;

public:
    // Setters
    void setRuns(int r) { runs = r; }
    void setBalls(int b) { balls = b; }
    void setStrikeRate(double sr) { strikeRate = sr; }
    void setFours(int f) { fours = f; }
    void setSixes(int s) { sixes = s; }
    void setWicket(bool w) { wicket = w; }

    // Getters
    int getRuns() const { return runs; }
    int getBalls() const { return balls; }
    double getStrikeRate() const { return strikeRate; }
    int getFours() const { return fours; }
    int getSixes() const { return sixes; }
    bool isWicket()const {return wicket; }
    bool allout();

    // Other functions
    void setDetails(int r, int b, int f, int s, bool w) {
        runs = r;
        balls = b;
        strikeRate = (balls != 0) ? (static_cast<double>(runs) / balls) * 100 : 0;
        fours = f;
        sixes = s;
        wicket = w;
    }

    void display() override {
        cout << "Batsman: " << name << " | Runs: " << runs << " | Balls: " << balls 
             << " | SR: " << strikeRate << " | Fours: " << fours 
             << " | Sixes: " << sixes << " | Out: " << (wicket ? "Yes" : "No") << endl;
    }
};

class bowler : public Players {
protected:
    int balls;
    int runsConceded;
    double economy;
    int maidens;
    int wickets;

public:
    // Setters
    void setBalls(int b) { balls = b; }
    void setRunsConceded(int rc) { runsConceded = rc; }
    void setEconomy(double e) { economy = e; }
    void setMaidens(int m) { maidens = m; }
    void setWickets(int w) { wickets = w; }

    // Getters
    int getBalls() const { return balls; }
    int getRunsConceded() const { return runsConceded; }
    double getEconomy() const { return economy; }
    int getMaidens() const { return maidens; }
    int getWickets() const { return wickets; }

    // Other functions
    void setDetails(int b, int rc, int m, int w) {
        balls = b;
        runsConceded = rc;
        economy = (balls != 0) ? (static_cast<double>(runsConceded) / (balls / 6)) : 0;
        maidens = m;
        wickets = w;
    }

    void display() override {
        cout << "Bowler: " << name << " | Balls: " << balls << " | Runs: " << runsConceded 
             << " | Economy: " << economy << " | Maidens: " << maidens 
             << " | Wickets: " << wickets << endl;
    }
};

#endif

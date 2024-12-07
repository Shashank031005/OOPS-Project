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

public:
    // Setters
    void setRuns(int r) { runs = r; }
    void setBalls(int b) { balls = b; }
    void setStrikeRate(double sr) { strikeRate = sr; }
    void setFours(int f) { fours = f; }
    void setSixes(int s) { sixes = s; }
    void setWicket(bool w) { wicket = w;
    friend istream& operator >> (istream&,batsmen&);
    friend ostream& operator << (ostream&,batsmen&);}

    // Getters
    int getRuns() const { return runs; }
    int getBalls() const { return balls; }
    double getStrikeRate() const { return strikeRate; }
    int getFours() const { return fours; }
    int getSixes() const { return sixes; }
    bool isWicket() const { return wicket; }
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
    int getWickets() const { return wickets; 
    friend istream& operator >> (istream&,bowler&);
    friend ostream& operator << (ostream&,bowler&);}
};

#endif

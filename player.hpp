// player.hpp
// Ivy Swenson
// Started: 2024-09-05
// Updated: 2024-09-10
//
// For CS 311 Fall 2024
// Header for class Player
// Time of day: realname, username, gamesplayed

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>

// Player class declaration
class Player {
private:
    // Private member variables
    std::string realName;
    std::string username;
    int gamesPlayed;

public:
    // Default constructor
    Player();

    // 3-parameter constructor
    Player(const std::string& realName, const std::string& username, int gamesPlayed);

    // Get functions
    std::string getRealName() const;
    std::string getUsername() const;
    int getGames() const;

    // Set functions
    void setRealName(const std::string& realName);
    void setUsername(const std::string& username);
    void setGames(int games);

    // Inactive function
    bool inactive() const;

    // toString function
    std::string toString() const;

    // Equality and inequality operators
    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;

    // Pre- and post-increment operators
    Player& operator++();    // Pre-increment
    Player operator++(int);  // Post-increment

    // Pre- and post-decrement operators
    Player& operator--();    // Pre-decrement
    Player operator--(int);  // Post-decrement

    // Stream insertion operator (friend function)
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif  // PLAYER_HPP

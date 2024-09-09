#include "player.hpp"
#include <cassert>
#include <iostream>
#include <sstream>

// Default constructor
Player::Player()
    : realName("UNKNOWN"), username("UNKNOWN"), gamesPlayed(0) {}

// 3-parameter constructor
Player::Player(const std::string& realName, const std::string& username, int gamesPlayed)
    : realName(realName), username(username), gamesPlayed(gamesPlayed) {
    assert(gamesPlayed >= 0);  // Ensure gamesPlayed is non-negative
}

// Get functions
std::string Player::getRealName() const {
    return realName;
}

std::string Player::getUsername() const {
    return username;
}

int Player::getGames() const {
    return gamesPlayed;
}

// Set functions
void Player::setRealName(const std::string& realName) {
    this->realName = realName;
}

void Player::setUsername(const std::string& username) {
    this->username = username;
}

void Player::setGames(int games) {
    assert(games >= 0);  // Ensure non-negative games played
    gamesPlayed = games;
}

// Inactive function
bool Player::inactive() const {
    return gamesPlayed == 0;
}

// toString function
std::string Player::toString() const {
    std::ostringstream oss;
    oss << realName << " (" << username << "): " << gamesPlayed;
    return oss.str();
}

// Equality operator
bool Player::operator==(const Player& other) const {
    return realName == other.realName &&
        username == other.username &&
        gamesPlayed == other.gamesPlayed;
}

// Inequality operator
bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}

// Pre-increment operator (prefix)
Player& Player::operator++() {
    ++gamesPlayed;
    return *this;
}

// Post-increment operator (suffix)
Player Player::operator++(int) {
    Player temp = *this;
    ++(*this);
    return temp;
}

// Pre-decrement operator (prefix)
Player& Player::operator--() {
    if (gamesPlayed > 0) {
        --gamesPlayed;
    }
    return *this;
}

// Post-decrement operator (suffix)
Player Player::operator--(int) {
    Player temp = *this;
    --(*this);
    return temp;
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.toString();
    return os;
}

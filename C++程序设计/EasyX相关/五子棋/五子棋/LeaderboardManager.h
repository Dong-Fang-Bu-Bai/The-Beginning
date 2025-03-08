#pragma once
#include <vector>
#include <string>

class LeaderboardManager {
private:
    std::vector<std::pair<std::string, int>> leaderboard;
    void loadLeaderboard();
    void saveLeaderboard();

public:
    LeaderboardManager();
    void addScore(const std::string& playerName, int score);
    const std::vector<std::pair<std::string, int>>& getLeaderboard() const;
};
#pragma once

#include "Character.h"
#include <vector>

class Enemy : public Character {
public:
    Enemy(const std::string& name, const std::string& description, int enemyHealth, int fixedDamage);

    void addAvailableEnemies(const Enemy& race);

    const std::string& getDescription() const;
    static const std::vector<Enemy>& getAvailableEnemies();
    static void initializeAvailableEnemies();
    static Enemy createEnemy(const std::string& enemyName);


private:
    std::string description;
    std::string name;
    static std::vector<Enemy> availableEnemies;
};


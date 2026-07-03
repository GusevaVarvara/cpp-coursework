#pragma once

#include "Character.h"
#include <vector>

class Race : public Character {
public:
    Race(const std::string& name, const std::string& description);

    void addAvailableRace(const Race& race);

    const std::string& getDescription() const;
    static const std::vector<Race>& getAvailableRaces();
    static void initializeAvailableRaces();
    static Race createRace(const std::string& raceName);

private:
    std::string description;
    static std::vector<Race> availableRaces;
};

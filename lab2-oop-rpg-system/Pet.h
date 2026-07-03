#pragma once
#include "Character.h"
#include <string>
#include <vector>

class Pet : public Character {
public:
    Pet(const std::string& name, const std::string& description, int fixedDamage);

    void addAvailablePets(const Pet& pet);

    const std::string& getDescription() const;
    static const std::vector<Pet>& getAvailablePets();
    static void initializeAvailablePets();
    static Pet createPet(const std::string& petName);

private:
    std::string description;
    static std::vector<Pet> availablePets;
};


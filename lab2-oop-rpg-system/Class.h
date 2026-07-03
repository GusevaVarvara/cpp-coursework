#pragma once

#include "Character.h"
#include <vector>

class Class : public Character {
public:
    Class(const std::string& name, const std::string& description);

    void addAvailableClasses(const Class& characterClass);

    const std::string& getDescription() const;

    static void initializeAvailableClasses();
    static const std::vector<Class>& getAvailableClasses();
    static Class createClass(const std::string& className);

private:
    static std::vector<Class> availableClasses;
    std::string description;
};

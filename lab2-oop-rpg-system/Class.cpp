#include "Class.h"

std::vector<Class> Class::availableClasses;

Class::Class(const std::string& name, const std::string& description)
    : Character(name, 100, 0), description(description) {}

void Class::addAvailableClasses(const Class& characterClass) {
    availableClasses.push_back(characterClass);
}

void Class::initializeAvailableClasses() {

    Class warrior("Warrior", "Воины - мастера в ближнем бою, обладающие силой и навыками,"
        "необходимыми для ведения сражений. Они обладают высокими "
        "хитами, навыками в обращении с оружием и броней, а также выбором "
        "боевых стилей и военных подклассов.");

    Class wizard("Wizard", "Маги - обладатели знаний и мастерства в колдовстве. Их сила происходит "
        "из глубокого понимания магии и способности использовать заклинания для "
        "манипуляции реальностью. Открывая тайны арканы, маги могут вызывать могущественные "
        "эффекты, от взрывов огня до временных измерений.");

    Class rogue("Rogue", "Воры - ловкие и хитрые персонажи, специализирующиеся на скрытности, уклонении и выполнении "
        "заданий незаметно. Они могут быть ловкими воришками или мастерами убийств. Воры обладают навыками "
        "в обмане, восприятии и обращении с ловким оружием.");

    Class cleric("Cleric", "Жрецы - служители божеств, обладающие священной магией. Они могут быть лекарями, защитниками веры "
        "или наносителями священного урона. Жрецы могут лечить союзников, вызывать благословения или проклятия, "
        "и даже бороться с нежитью. У них есть доступ к божественным заклинаниям и специфическим предметам.");

    Class druid("Druid", "Друиды - защитники природы, обладающие магией, которая связана с растениями, животными и стихиями.Они "
        "могут менять облик, вызывать силы природы и лечить союзников. Друиды обладают способностью общения с "
        "животными, формами дикой природы и могут использовать заклинания, связанные с природой.Они также могут "
        "быть защитниками окружающей среды.");

    availableClasses.push_back(warrior);
    availableClasses.push_back(wizard);
    availableClasses.push_back(rogue);
    availableClasses.push_back(cleric);
    availableClasses.push_back(druid);
}
const std::vector<Class>& Class::getAvailableClasses() {
    if (availableClasses.empty()) {
        initializeAvailableClasses();
    }
    return availableClasses;
}

const std::string& Class::getDescription() const {
    return description;
}


Class Class::createClass(const std::string& className) {
    for (const Class& characterClass : availableClasses) {
        if (characterClass.getName() == className) {
            return characterClass;
        }
    }
    return Class("Недоступный класс", "Описание отсутствует");
}




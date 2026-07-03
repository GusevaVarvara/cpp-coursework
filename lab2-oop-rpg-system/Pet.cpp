#include "Pet.h"
#include <iostream>

std::vector<Pet> Pet::availablePets;

Pet::Pet(const std::string& name, const std::string& description, int fixedDamage)
    : Character(name, 100, fixedDamage), description(description) {}

void Pet::addAvailablePets(const Pet& pet) {
    availablePets.push_back(pet);
}

void Pet::initializeAvailablePets() {

    Pet pseudodragon("Pseudodragon", " Псевдодраконы - это небольшие существа, похожие на драконов, с переливающейся чешуей, летучими мышцеподобными крыльями "
                               "и длинным хвостом. Их отличает игривость и высокий уровень интеллекта.Несмотря на свою драконью внешность, "
                               "они относительно небольшие и часто служат магическими спутниками заклинателей.", 4);


    Pet BlinkDog("Blink-Dog", " Мерцающие собаки - это среднеразмерные, интеллектуальные собаки с гладкой сине-серой шерстью. У них есть способность "
                           "телепортироваться на короткие расстояния, что делает их отличными охотниками и стражами. Известны своей преданностью, их часто "
                           "выбирают компаньонами для приключений.", 5);


    Pet FeyPanther("Fey-Panther", "Фейские пантеры - это мистические, магические большие кошки с яркой, этерической шерстью. Эти существа не являются "
                                   "настоящими пантерами, а фейскими существами, принимающими облик больших, величественных кошек. Ловкие и незаметные, их "
                                   "часто выбирают компаньонами для тех, кто путешествует по волшебным или иным мирам.", 6);

    availablePets.push_back(pseudodragon);
    availablePets.push_back(BlinkDog);
    availablePets.push_back(FeyPanther);
}

const std::vector<Pet>& Pet::getAvailablePets() {
    if (availablePets.empty()) {
        initializeAvailablePets();
    }
    return availablePets;
}

const std::string& Pet::getDescription() const {
    return description;
}


Pet Pet::createPet(const std::string& petName) {
    const auto& pets = Pet::getAvailablePets();

    for (const auto& pet : pets) {
        if (pet.getName() == petName) {
            return pet;
        }
    }
    return Pet("?", "Недоступный питомец", 0);
}


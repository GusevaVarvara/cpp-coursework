#include "Enemy.h"

std::vector<Enemy> Enemy::availableEnemies;

Enemy::Enemy(const std::string& name, const std::string& description, int enemyHealth, int fixedDamage)
    : Character(name, enemyHealth, fixedDamage), description(description) {}

void Enemy::addAvailableEnemies(const Enemy& enemy) {
    availableEnemies.push_back(enemy);
}

void Enemy::initializeAvailableEnemies() {

    Enemy arcadios("Arcadios", "Могущественный демон с черной душой и армией мрака. Аркадиус питается страхом и отчаянием, "
                                      "оставляя за собой след разрушений и исчезающих душ.", 80, 25);


    Enemy serafina("Serafina", "Обманчивая эльфийка, союзница темных сил. Использует свою мастерство иллюзий и контроля над разумом, "
                                      "чтобы манипулировать природой и созданиями, превращая их против группы персонажей.", 120, 20);


    Enemy malgrim("Malgrim", "Древний вампир с мрачными силами, возглавляющий легион нежити. Его жажда крови и желание "
                                    "господства над живыми делают его страшным противником.", 150, 20);

    availableEnemies.push_back(arcadios);
    availableEnemies.push_back(serafina);
    availableEnemies.push_back(malgrim);
}

const std::vector<Enemy>& Enemy::getAvailableEnemies() {
    if (availableEnemies.empty()) {
        initializeAvailableEnemies();
    }
    return availableEnemies;
}


const std::string& Enemy::getDescription() const {
    return description;
}


Enemy Enemy::createEnemy(const std::string& enemyName) {
    const auto& enemies = Enemy::getAvailableEnemies();

    for (const auto& enemy : enemies) {
        if (enemy.getName() == enemyName) {
            return enemy;
        }
    }
    return Enemy("?", "Описание отсутствует", 0, 0);
}

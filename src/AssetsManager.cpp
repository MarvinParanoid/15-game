#include "AssetsManager.h"

void AssetsManager::loadFont(const std::string &name, const std::string &filename) {
    sf::Font font;
    if (font.loadFromFile(filename)) {
        _fonts.emplace(name, font);
    } else {
        throw;
    }
}

sf::Font &AssetsManager::getFont(const std::string &name) { return _fonts.at(name); }

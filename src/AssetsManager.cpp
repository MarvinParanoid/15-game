#include "AssetsManager.h"

void AssetsManager::LoadFont(const std::string &name, const std::string &filename) {
    sf::Font font;
    if (font.loadFromFile(filename)) {
        _fonts.emplace(name, font);
    } else {
        throw;
    }
}

sf::Font &AssetsManager::GetFont(const std::string &name) { return _fonts.at(name); }

#include "pokemon.hpp"

void PokemonCollection::Add(const std::string &name, size_t id) {
pokemons_.emplace_back(name, id);
}


bool PokemonCollection::Remove(const std::string &name, size_t id) {
for (auto it = pokemons_.begin(); it != pokemons_.end(); ++it) {
if (it->first == name && it->second == id) {
pokemons_.erase(it);
return true;
}
}
return false;
}

void PokemonCollection::Print() const {
for (const auto &pokemon : pokemons_) {
std::cout << "id: " << pokemon.second << ", name: " << pokemon.first << std::endl;
}
}

void PokemonCollection::SortByName() {
pokemons_.sort([](const auto &a, const auto &b) {
return (a.first < b.first) || (a.first == b.first && a.second < b.second);
});
}

void PokemonCollection::SortById() {
pokemons_.sort([](const auto &a, const auto &b) {
return (a.second < b.second) || (a.second == b.second && a.first < b.first);
});
}

PokemonCollection::PokemonCollection(PokemonCollection collection1, PokemonCollection collection2) {
pokemons_ = collection1.pokemons_;
pokemons_.insert(pokemons_.end(), collection2.pokemons_.begin(), collection2.pokemons_.end());

SortByName();

pokemons_.unique([](const auto &a, const auto &b) {
return a.first == b.first && a.second == b.second;
});
}
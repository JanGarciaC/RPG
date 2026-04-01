#pragma once

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

#include "../items/items.h"


enum TileEvent {
    NOTHING,
    VILLAGE,
    NPC,
	MONEY,
    RANDOMLOOT,
    RANDOMBUILDING,
    CAT
};

enum NPCType {
    BOAR,
    RABBIT,
    THIEF,
	SOLDIER,
	KNIGHT,
	ANGEL,
    DEMON
};

enum LootType {
    JUNK,
    WEAPON,
    ARMOR,
    POTION,
    ELIXIR
};

enum BuildingType {
    ABANDONED_HUT,
    RUINS,
	TAVERN,
	GRAVEYARD,
    RITUAL,
    CHURCH
};

template <typename T>
struct WeightedItem {
    T value;
    double weight;
};

inline std::vector<WeightedItem<NPCType>> npcList = {
    {RABBIT, 32},
    {BOAR, 32},
    {THIEF, 20},
    {SOLDIER, 10},
    {KNIGHT, 5},
    {ANGEL, 0.5},
    {DEMON, 0.5}
};

inline std::vector<WeightedItem<LootType>> lootList = {
    {JUNK, 50},
	{POTION, 20},
    {ELIXIR, 10},
	{WEAPON, 7.5},
    {ARMOR, 7.5}

};

inline std::vector<WeightedItem<BuildingType>> buildingList = {
    {ABANDONED_HUT, 50},
	{RUINS, 25},
	{TAVERN, 18},
    {GRAVEYARD, 5},
    {RITUAL, 1},
    {CHURCH, 1}
};

inline std::vector<WeightedItem<int>> moneyList = {
    {2, 10},
    {3, 30},
    {5, 30},
    {10, 20},
    {20, 9.9},
    {100, 0.1}
};

class MapTile {
private:
    int x, y;
    bool firstTime;
    bool condition;

    TileEvent eventType;

    NPCType npc;
    LootType lootType;
	baseObject* loot;
    BuildingType building;
    int money;

public:
    MapTile();
    MapTile(int x, int y);

	int getX() const { return x; }
	int getY() const { return y; }

	baseObject* getLoot() { return loot; }
	LootType getLootType() { return lootType; }
	TileEvent getTileEvent() { return eventType; }
	bool getCondition() { return condition; }
	int getMoney() { return money; }

	void markVisited() { firstTime = false; }
    void markCondition() { condition = true; }
    void createOriginTile();
    std::string getTileMessage();
};

class WorldMap {
private:
    std::map<std::pair<int, int>, MapTile> tiles;
	MapTile* currentTile;

public:
    WorldMap();

	MapTile* getCurrentTile() { return currentTile; }
    MapTile& getTile(int x, int y);
    void movePlayer(int dx, int dy);

    ~WorldMap() {}
};

template <typename T>
T getRandomWeighted(const std::vector<WeightedItem<T>>& list);

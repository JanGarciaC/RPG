#pragma once

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>


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
	DRAGON,
    DEMON
};

enum BuildingType {
    ABANDONED_HUT,
    RUINS,
	TAVERN,
    CORPSES,
    CHURCH
};

template <typename T>
struct WeightedItem {
    T value;
    double weight;
};

inline std::vector<WeightedItem<NPCType>> npcList = {
    {RABBIT, 25},
    {BOAR, 25},
    {THIEF, 20},
    {SOLDIER, 10},
    {KNIGHT, 10},
    {DRAGON, 5},
    {DEMON, 5}
};

inline std::vector<WeightedItem<std::string>> lootList = {
    {"Sword", 25},
    {"Shield", 25},
    {"Potion", 40},
    {"Armor", 10}
};

inline std::vector<WeightedItem<BuildingType>> buildingList = {
    {ABANDONED_HUT, 35},
	{RUINS, 25},
	{TAVERN, 20},
    {CORPSES, 10},
    {CHURCH, 10}
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
    bool doneCombat;

    TileEvent eventType;

    NPCType npc;
    std::string loot;
    BuildingType building;
    int money;

public:
    MapTile();
    MapTile(int x, int y);

	int getX() const { return x; }
	int getY() const { return y; }

	void markVisited() { firstTime = false; }
    void createOriginTile();
    std::string getTileMessage();
};

class WorldMap {
private:
    std::map<std::pair<int, int>, MapTile> tiles;
	MapTile* currentTile;

public:
    WorldMap();

    std::string getCurrentTileMessage() {
        return currentTile->getTileMessage();
    }

    MapTile& getTile(int x, int y);
    void movePlayer(int dx, int dy);

    ~WorldMap() {}
};

template <typename T>
T getRandomWeighted(const std::vector<WeightedItem<T>>& list);

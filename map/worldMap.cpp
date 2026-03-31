#include "worldMap.h"

using namespace std;

template <typename T>
T getRandomWeighted(const vector<WeightedItem<T>>& list)
{
    double totalWeight = 0.0;

    for (const auto& item : list) {
        totalWeight += item.weight;
    }

    double r = ((double)rand() / RAND_MAX) * totalWeight;

    for (const auto& item : list) {
        if (r < item.weight) {
            return item.value;
        }
        r -= item.weight;
    }

    return list.back().value;
}

MapTile::MapTile(int X, int Y) : x(X), y(Y), firstTime(true), doneCombat(false), eventType(NOTHING), npc(BOAR), loot(""), building(ABANDONED_HUT), money(0)
{
	int r = rand() % 1000;

    if (r < 600) {
        eventType = NOTHING;
    }
    else if (r < 750) {
        eventType = NPC;
        npc = getRandomWeighted(npcList);
    }
    else if (r < 800) {
        eventType = MONEY;
        money = getRandomWeighted(moneyList);
    }
    else if (r < 900) {
        eventType = RANDOMLOOT;
        loot = getRandomWeighted(lootList);
    }
    else if (r < 999) {
        eventType = RANDOMBUILDING;
        building = getRandomWeighted(buildingList);
    }
    else {
        eventType = CAT;
    }
}

void MapTile::createOriginTile() 
{
    x = 0;
    y = 0;
    firstTime = false;
    eventType = VILLAGE;
}

MapTile::MapTile() : x(0), y(0), firstTime(true), doneCombat(false), eventType(NOTHING), npc(BOAR), loot(""), building(ABANDONED_HUT), money(0)
{
    do
    {
        x = 10 - rand() % 20;
        y = 10 - rand() % 20;
	} while (x == 0 && y == 0);

}

string MapTile::getTileMessage()
{
	string message;

    if (firstTime)
    {
        int r = rand() % 1000;

        if (r < 250)
            message = "You don't recognize this place.\n";
        else if (r < 500)
            message = "This place is new to you.\n";
        else if (r < 750)
            message = "It's your first time here.\n";
        else
            message = "You've never been here before.\n";


        switch (eventType)
        {
        case NOTHING:
            message += "There's nothing here. \n";
            break;
        case VILLAGE:
            message += "You find yourself on a desolate village.\n There are only 2 intact buildings. Where do you go? \n";
            break;
        case NPC:
            switch (npc)
            {
            case BOAR:
				message += "You encounter a wild boar. It looks aggressive! \n";
                break;
            case RABBIT:
				message += "You see a rabbit hopping around. It seems harmless, but edible. \n";
                break;
            case THIEF:
				message += "A shady figure approaches you. It's a thief! He wants to steal some of your gold. \n";
                break;
            case SOLDIER:
				message += "You see a soldier patrolling the area. He looks angry and hungry. \n";
                break;
            case KNIGHT:
				message += "A knight in shining armor stands before you. He looks possesed by something from another world. \n";
                break;
            case DRAGON:
				message += "A fearsome dragon appears in front of you. It doesn't look to happy to see you. \n";
                break;
            case DEMON:
				message += "A terrifying demon emerges from the shadows. Running is always a option. \n";
                break;
            default:
                break;
            }
            break;
        case MONEY:
            message += "You see something shiny on the ground. You find " + to_string(money) + " gold! \n";
            break;
        case RANDOMLOOT:
            message += "There is something lying on the ground. There is a " + loot + " here \n";
            break;
        case RANDOMBUILDING:
            switch (building)
            {
            case ABANDONED_HUT:
                message += "You find an old hut here. Do you want to go inside? \n";
                break;
            case RUINS:
                message += "There are some ruins in this place. Do you want to explore them? \n";
                break;
            case TAVERN:
                message += "You stubmle into a tavern. Do you want to enter? \n";
                break;
            case CORPSES:
                message += "You find a pile of corpses and human remains lying on the ground. \n";
                break;
            case CHURCH:
                message += "A small church appears in front of you. Do you want to go inside? \n";
                break;
            default:
                break;
            }
            break;
        case CAT:
            message += "You see the cutest creature on earth. It's a cat! All your basic Stats increase by 1.\n";
            break;
        default:
            break;
        }
    }
    else
    {
        message = "You have already been here.\n";

        switch (eventType)
        {
        case NPC:
            if (!doneCombat)
                switch (npc)
                {
                case BOAR:
                    message += "You encounter a wild boar. It looks aggressive! \n";
                    break;
                case RABBIT:
                    message += "You see a rabbit hopping around. It seems harmless, but edible. \n";
                    break;
                case THIEF:
                    message += "A shady figure approaches you. It's a thief! He wants to steal some of your gold. \n";
                    break;
                case SOLDIER:
                    message += "You see a soldier patrolling the area. He looks angry and hungry. \n";
                    break;
                case KNIGHT:
                    message += "A knight in shining armor stands before you. He looks possesed by something from another world. \n";
                    break;
                case DRAGON:
                    message += "A giant dragon appears in front of you. It doesn't look to happy to see you. \n";
                    break;
                case DEMON:
                    message += "A terrifying demon emerges from the shadows. Running is always a option. \n";
                    break;
                default:
                    break;
                }
            else
			    message += "The remains of your victim are still lying on the groud. \n";
			break;
        case VILLAGE:
            message += "You find yourself on a desolate village.\n There are only 2 intact buildings. Where do you go? \n";
            break;
        case RANDOMBUILDING:
            switch (building)
            {
            case ABANDONED_HUT:
                message += "You find an old hut here. Do you want to go inside? \n";
                break;
            case RUINS:
                message += "There are some ruins in this place. Do you want to explore them? \n";
                break;
            case TAVERN:
                message += "You stubmle into a tavern. Do you want to enter? \n";
                break;
            case CORPSES:
                message += "You find a pile of corpses and human remains lying on the ground. \n";
                break;
            case CHURCH:
                message += "A small church appears in front of you. Do you want to go inside? \n";
                break;
            default:
                break;
            }
            break;
        default:   
            message += "There's nothing here. \n";
            break;
        }
    }

    return message;
}

WorldMap::WorldMap() 
{
    MapTile origin;
    origin.createOriginTile();
    tiles.emplace(std::make_pair(0, 0), origin);

    MapTile start;
    tiles.emplace(std::make_pair(start.getX(), start.getY()), start);
    currentTile = &tiles[std::make_pair(start.getX(), start.getY())];
}

MapTile& WorldMap::getTile(int x, int y)
{
    auto key = std::make_pair(x, y);

    auto [it, inserted] = tiles.try_emplace(key, x, y);

    return it->second;
}
void WorldMap::movePlayer(int dx, int dy) 
{
    currentTile->markVisited();
    int newX = currentTile->getX() + dx;
    int newY = currentTile->getY() + dy;
    currentTile = &getTile(newX, newY);
}

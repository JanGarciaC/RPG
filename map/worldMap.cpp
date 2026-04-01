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

MapTile::MapTile(int X, int Y) : x(X), y(Y), firstTime(true), condition(false), eventType(NOTHING), npc(BOAR), lootType(JUNK), building(ABANDONED_HUT), money(0)
{
	int r = rand() % 10000;

    if (r < 4500) {
        eventType = NOTHING;
    }
    else if (r < 5500) {
        eventType = NPC;
        npc = getRandomWeighted(npcList);
    }
    else if (r < 6500) {
        eventType = MONEY;
        money = getRandomWeighted(moneyList);
    }
    else if (r < 8000) {
        eventType = RANDOMLOOT;
        lootType = getRandomWeighted(lootList);
        switch (lootType)
        {
        case JUNK:
			loot = new baseObject(getRandomBaseObjectTemplate());
            break;
        case WEAPON:
			loot = new weapon(getRandomWeaponTemplate());
            break;
        case ARMOR:
			loot = new armor(getRandomArmorTemplate());
            break;
        case POTION:
			loot = new Potion(getRandomPotionTemplate());
            break;
        case ELIXIR:
			loot = new Elixir(getRandomElixirTemplate());
            break;
        default:
            break;
        }
    }
    else if (r < 9990) {
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

MapTile::MapTile() : x(0), y(0), firstTime(true), condition(false), eventType(NOTHING), npc(BOAR), lootType(JUNK), building(ABANDONED_HUT), money(0)
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

    if (eventType == VILLAGE)
    {
        message = "You find yourself on a desolate village.\nThere are only 2 intact buildings. What do you do? \n";
        return message;
    }

    if (firstTime)
    {
        switch (eventType)
        {
        case NOTHING:
            message += "There's nothing here. \n";
            break;
        case NPC:
            switch (npc)
            {
            case BOAR:
				message += "You encounter a Wild Boar. It looks aggressive! \n";
                break;
            case RABBIT:
				message += "You see a Rabbit hopping around. It seems harmless, but edible. \n";
                break;
            case THIEF:
				message += "A shady figure approaches you. It's a Thief! He wants to steal some of your gold. \n";
                break;
            case SOLDIER:
				message += "You see a Soldier patrolling the area. He looks angry and hungry. \n";
                break;
            case KNIGHT:
				message += "A Knight in shining armor stands before you. He looks possesed by something from another world. \n";
                break;
            case ANGEL:
				message += "A beautyfull Angel appears in front of you. It's radiant light shines on you. \n";
                break;
            case DEMON:
				message += "A terrifying Demon emerges from the shadows. You feel something terrible is about to happen. \n";
                break;
            default:
                break;
            }
            break;
        case MONEY:
            message += "You see something shiny on the ground. You find " + to_string(money) + " gold! \n";
            break;
        case RANDOMLOOT:
            switch (lootType)
            {   
            case JUNK:
				message += "You see something on the ground. It's a " + loot->getName() + "\n";
				message += "It has been added to your inventory. \n";
                break;
            case WEAPON:
				message += "You find a weapon on the ground. It's a " + loot->getName() + "\n";
                message += "It has been added to your inventory. \n";
                break;
            case ARMOR:
				message += "You find a piece of armor on the ground. It's a " + loot->getName() + "\n";
                message += "It has been added to your inventory. \n";
                break;
            case POTION:
				message += "You find a potion on the ground. It's a " + loot->getName() + "\n";
                message += "It has been added to your inventory. \n";
                break;
            case ELIXIR:
				message += "You find an elixir on the ground. It's a " + loot->getName() + "\n";
                message += "It has been added to your inventory. \n";
                break;
            default:
                break;
            }
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
            case GRAVEYARD:
                message += "This field is filled with tombs, it's a graveyard. What do you do? \n";
				break;
            case RITUAL:
                message += "You find some sort of ritual circles drawn in the floor with blood. What do you do?\n";
                break;
            case CHURCH:
                message += "A big, wooden cross appears in front of you. What do you do?\n";
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
        switch (eventType)
        {
        case NPC:
            if (!condition)
                switch (npc)
                {
                case BOAR:
                    message += "You encounter a Wild Boar. It looks aggressive! \n";
                    break;
                case RABBIT:
                    message += "You see a Rabbit hopping around. It seems harmless, but edible. \n";
                    break;
                case THIEF:
                    message += "A shady figure approaches you. It's a Thief! He wants to steal some of your gold. \n";
                    break;
                case SOLDIER:
                    message += "You see a Soldier patrolling the area. He looks angry and hungry. \n";
                    break;
                case KNIGHT:
                    message += "A Knight in shining armor stands before you. He looks possesed by something from another world. \n";
                    break;
                case ANGEL:
                    message += "A beautyfull Angel appears in front of you. It's radiant light shines on you. \n";
                    break;
                case DEMON:
                    message += "A terrifying Demon emerges from the shadows. You feel something terrible is about to happen. \n";
                    break;
                default:
                    break;
                }
            else
			    message += "The remains of your victim are still lying on the groud. \n";
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
            case RITUAL:
				if (!condition)
                    message += "You find some sort of ritual circles drawn in the floor with blood. What do you do?\n";
                else
                    message += "There's nothing here. \n";
                break;
            case CHURCH:
				if (!condition)
                    message += "A big, wooden cross appears in front of you. What do you do?\n";
                else
                    message += "There's nothing here. \n";
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
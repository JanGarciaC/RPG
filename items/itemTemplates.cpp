#include "items.h"

std::vector<baseObjectTemplate> baseObjectTemplates = {
	{"Piece of Trash", "Useless and smells bad", 1},
	{"Old Coin", "An old coin, it might be worth something.", 5},
	{"Ring", "Metalic ring with a small stone incrustated.", 10},
	{"Mysterious Gem", "A gem that glows with an inner light. It feels warm to the touch.", 20},
	{"Gold Nugget", "Small gold nugget, can be sold for a good price", 50}
};

std::vector<weaponTemplate> weaponTemplates = {
	{"Rusty Sword", "Old rusty sword, full of cracks.", 10, 1.6f, 50, 1.1f, 1, 0},
	{"Rusty Dagger", "Old and Dull rusty dagger.", 10, 1.6f, 50, 1.2f, 2, 0},
	{"Old Staff", "old wooden staff, full of splinters and cracks.", 00, 1.3f, 50, 1.0f, 3, 0},
	{"Iron Sword", "A sturdy iron sword, still in good condition.", 100, 2.2f, 100, 1.3f, 1, 5},
	{"Steel Dagger", "A sharp steel dagger, perfect for quick attacks.", 100, 1.9f, 100, 1.6f, 2, 5},
	{"Enchanted Staff", "A staff imbued with magical energy.", 100, 1.5f, 100, 1.1f, 3, 5},
	{"HardSteel Sword", "Big and strong sword, capable of striking down the strongest foes.", 1000, 3.5f, 250, 1.6f, 1, 10},
	{ "Shadow Dagger", "A dagger that seems to absorb light around it, perfect for assassinations.", 1000, 2.8f, 250, 1.9f, 2, 10},
	{"Archmage Staff", "A staff that radiates immense magical power.", 1000, 2.0f, 250, 1.3f, 3, 10}
};

std::vector<armorTemplate> armorTemplates = {
	{"Rusty Chainmail", "Old chainmail, gives you a false sensation of security.", 10, 20, 50, 1.0f, 1, 0},
	{"Old Leather Armor", "Old and wore down leather armor.", 10, 10, 50, 1.3f, 2, 0},
	{"Old Robe", "Old, long robe. It has more holes than intact parts.", 10, 5, 50, 1.1f, 3, 0},
	{"Iron Armor", "A sturdy iron armor that can protect you from most attacks.", 100, 40, 100, 1.1f, 1, 5},
	{"Leather Armor", "A well-crafted leather armor that offers decent protection.", 100, 20, 100, 1.6f, 2, 5},
	{"Enchanted Robe", "A robe imbued with magical properties.", 100, 10, 100, 1.4f, 3, 5},
	{"Dragon Scale Armor", "Armor made from the scales of a dragon.", 1000, 80, 250, 1.2f, 1, 10},
	{"Shadow Cloak", "A cloak that seems to blend with the shadows.", 1000, 40, 250, 1.9f, 2, 10},
	{"Archmage Robe", "A robe that radiates immense magical power.", 1000, 20, 250, 1.6f, 3, 10}
};

std::vector<potionTemplate> potionTemplates = {
	{"Minor Health Potion", "A small vial filled with a red liquid. It restores a small amount of health.", 20, 20, 0.1f, 0},
	{"Health Potion", "A vial filled with a red liquid. It restores a moderate amount of health.", 50, 50, 0.25f, 0},
	{"Major Health Potion", "A large vial filled with a red liquid. It restores a large amount of health.", 100, 100, 0.5f, 0},
	{"Minor Mana Potion", "A small vial filled with a blue liquid. It restores a small amount of mana.", 20, 20, 0.1f, 0},
	{"Mana Potion", "A vial filled with a blue liquid. It restores a moderate amount of mana.", 50, 50, 0.25f, 0},
	{"Major Mana Potion", "A large vial filled with a blue liquid. It restores a large amount of mana.", 100, 100, 0.5f, 0}
};

std::vector<elixirTemplate> elixirTemplates = {
	{"Small Vigor Elixir", "A small elixir vial filled with a green liquid. Increases your stamina 1 point for a short amount", 35, Stamina, 1, false},
	{"Small Might Elixir", "A small elixir vial filled with a red liquid. Increases your strength 1 point for a short amount", 35, Strength, 1, false},
	{"Small Agility Elixir", "A small elixir vial filled with a yellow liquid. Increases your agility 1 point for a short amount", 35, Agility, 1, false},
	{"Small Intellect Elixir", "A small elixir vial filled with a blue liquid. Increases your intellect 1 point for a short amount", 35, Intellect, 1, false},
	{"Vigor Elixir", "An elixir vial filled with a green liquid. Increases your stamina 2 points for a short amount", 75, Stamina, 2, false},
	{"Might Elixir", "An elixir vial filled with a red liquid. Increases your strength 2 points for a short amount", 75, Strength, 2, false},
	{"Agility Elixir", "An elixir vial filled with a yellow liquid. Increases your agility 2 points for a short amount", 75, Agility, 2, false},
	{"Intellect Elixir", "An elixir vial filled with a blue liquid. Increases your intellect 2 points for a short amount", 75, Intellect, 2, false},
	{"Greater Vigor Elixir", "A large elixir vial filled with a green liquid. Increases your stamina 3 points for a short amount", 150, Stamina, 3, false},
	{"Greater Might Elixir", "A large elixir vial filled with a red liquid. Increases your strength 3 points for a short amount", 150, Strength, 3, false},
	{"Greater Agility Elixir", "A large elixir vial filled with a yellow liquid. Increases your agility 3 points for a short amount", 150, Agility, 3, false},
	{"Greater Intellect Elixir", "A large elixir vial filled with a blue liquid. Increases your intellect 3 points for a short amount", 150, Intellect, 3, false},
	{"Perfect Vigor Elixir", "An elixir vial, filled with a refined green liquid. Increases Permanently your stamina 1 point.", 300, Stamina, 0, true},
	{"Perfect Might Elixir", "An elixir vial, filled with a refined red liquid. Increases Permanently your strength 1 point.", 300, Strength, 0, true},
	{"Perfect Agility Elixir", "An elixir vial, filled with a refined yellow liquid. Increases Permanently your agility 1 point.", 300, Agility, 0, true},
	{"Perfect Intellect Elixir", "An elixir vial, filled with a refined blue liquid. Increases Permanently your intellect 1 point.", 300, Intellect, 0, true}
};

baseObjectTemplate getRandomBaseObjectTemplate() 
{
	std::vector<float> probabilities = { 50, 30, 15, 4, 1 };

	float total = 0.0f;
	for (float p : probabilities) {
		total += p;
	}

	float r = ((float)rand() / RAND_MAX) * total;

	float cumulative = 0.0f;
	for (size_t i = 0; i < baseObjectTemplates.size(); ++i) {
		cumulative += probabilities[i];
		if (r <= cumulative) {
			return baseObjectTemplates[i];
		}
	}

	return baseObjectTemplates.back();
}

weaponTemplate getRandomWeaponTemplate() 
{
	std::vector<float> probabilities = { 30, 30, 30, 3, 3, 3, 0.33333, 0.33333, 0.33333};

	float total = 0.0f;
	for (float p : probabilities) {
		total += p;
	}

	float r = ((float)rand() / RAND_MAX) * total;

	float cumulative = 0.0f;
	for (size_t i = 0; i < weaponTemplates.size(); ++i) {
		cumulative += probabilities[i];
		if (r <= cumulative) {
			return weaponTemplates[i];
		}
	}
	return weaponTemplates.back();
}

armorTemplate getRandomArmorTemplate() 
{
	std::vector<float> probabilities = { 30, 30, 30, 3, 3, 3, 0.33333, 0.33333, 0.33333 };
	float total = 0.0f;
	for (float p : probabilities) {
		total += p;
	}
	float r = ((float)rand() / RAND_MAX) * total;
	float cumulative = 0.0f;
	for (size_t i = 0; i < armorTemplates.size(); ++i) {
		cumulative += probabilities[i];
		if (r <= cumulative) {
			return armorTemplates[i];
		}
	}
	return armorTemplates.back();
}

potionTemplate getRandomPotionTemplate() 
{
	std::vector<float> probabilities = { 60, 6, 0.66666, 30, 3, 0.33333 };
	float total = 0.0f;
	for (float p : probabilities) {
		total += p;
	}
	float r = ((float)rand() / RAND_MAX) * total;
	float cumulative = 0.0f;
	for (size_t i = 0; i < potionTemplates.size(); ++i) {
		cumulative += probabilities[i];
		if (r <= cumulative) {
			return potionTemplates[i];
		}
	}
	return potionTemplates.back();
}

elixirTemplate getRandomElixirTemplate() 
{
	std::vector<float> probabilities = { 20, 20, 20, 20, 5, 5, 5, 5, 0.33333, 0.33333, 0.33333, 0.33333, 0.1, 0.1, 0.1, 0.1 };
	float total = 0.0f;
	for (float p : probabilities) {
		total += p;
	}
	float r = ((float)rand() / RAND_MAX) * total;
	float cumulative = 0.0f;
	for (size_t i = 0; i < elixirTemplates.size(); ++i) {
		cumulative += probabilities[i];
		if (r <= cumulative) {
			return elixirTemplates[i];
		}
	}
	return elixirTemplates.back();
}
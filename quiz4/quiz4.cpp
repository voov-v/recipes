#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PotionRecipe {
public:
	PotionRecipe(const  string& potionName, const string& coreIngerdient) {
		potionName_ = potionName;
		coreIngredient_ = coreIngerdient;
	}

	const string& GetPotionName() const {
		return potionName_;
	}

	const string& GetCoreIngredient() const {
		return coreIngredient_;
	}

private:
	string potionName_;
	string coreIngredient_;
};

class AlchemyWorkshop {
public:
	void AddRecipe(const string& potionName, const string& coreIngerdient) {
		recipes_.push_back(PotionRecipe(potionName, coreIngerdient));
	}

	void DisplayAllRecipes() const {
		for (const PotionRecipe& recipe : recipes_) {
			cout << recipe.GetPotionName() << ": " << recipe.GetCoreIngredient() << endl;
		}
	}

	PotionRecipe SearchRecipeByName(const string& name) const {
		for (const PotionRecipe& recipe : recipes_) {
			if (recipe.GetPotionName() == name) {
				return recipe;
			}
		}
		return PotionRecipe("NONE", "NONE");
	}

	vector<PotionRecipe> SearchRecipeByIngredient(const string& ingredient) const {
		vector<PotionRecipe> ret;
		for (const PotionRecipe& recipe : recipes_) {
			if (recipe.GetCoreIngredient() == ingredient) {
				ret.push_back(recipe);
			}
			
		}
		return ret;
	}

private:
	vector<PotionRecipe> recipes_;

};

int main() {
	AlchemyWorkshop workshop;
	workshop.AddRecipe("Healing Potion", "Herb");
	workshop.AddRecipe("Mana Potion", "Magic Water");
	workshop.AddRecipe("Stamina Potion", "Herb");
	workshop.AddRecipe("Fire Resistance Potion", "Fire Flower");

	workshop.DisplayAllRecipes();

	PotionRecipe recipe = workshop.SearchRecipeByName("Mana Potion");
	cout << "검색된 레시피: " << recipe.GetPotionName() << endl;

	vector<PotionRecipe> herbRecipes = workshop.SearchRecipeByIngredient("Herb");

	cout << "Herb를 사용하는 레시피 수: " << herbRecipes.size() << endl;

	return 0;
}
/**
 * Defines the type of a menuItem, which contains a numerical id, which
 * would equal the number seen on the physical menu, the item name, and 
 * the cost of the item. A helper method to populate the reference menu
 * vector is also initialized.
 *
 * @author Mohit Kewalramani
 * @version 2.0
 * @published 2017-05-15
 */

#include "header.h"


struct menuItem
{
    string menuItemNumber;
    string itemName;
    double itemCost;
};

// Declares all the following menuItems for easy use in creating
// the menu reference vector.
menuItem bottledWater, 
        soda, 
        smoothie, 
        coffee, 
        fries, 
        caesarSalad,
        chickenSalad,
        chickenStrips, 
        cheeseSandwich, 
        vegetarianSandwich, 
        cheesePizza, 
        vegetarianPizza,
        vegetarianTaco, 
        turkeySandwich, 
        tunaSandwich, 
        chickenBurger,
        chickenPizza, 
        chickenTaco, 
        chocolateMuffin, 
        iceCream;

/**
 * Populates an instance of a vector that is used as a reference vector
 * to refer back to the instance of the Menu.
 * @return vector<menuItem> The vector containing all menu items
 */
vector<menuItem> populateMenu()
{
    vector<menuItem> items;
    
    bottledWater.menuItemNumber = "1";
    bottledWater.itemName = "bottled_water";
    bottledWater.itemCost = 0.99;
    items.push_back(bottledWater);
    
    soda.menuItemNumber = "2";
    soda.itemName = "soda";
    soda.itemCost = 1.99;
    items.push_back(soda);
    
    smoothie.menuItemNumber = "3";
    smoothie.itemName = "smoothie";
    smoothie.itemCost = 2.15;
    items.push_back(smoothie);
    
    coffee.menuItemNumber = "4";
    coffee.itemName = "coffee";
    coffee.itemCost = 1.99;
    items.push_back(coffee);
    
    fries.menuItemNumber = "5";
    fries.itemName = "fries";
    fries.itemCost = 2.99;
    items.push_back(fries);
    
    caesarSalad.menuItemNumber = "6";
    caesarSalad.itemName = "caesar_salad";
    caesarSalad.itemCost = 4.15;
    items.push_back(caesarSalad);
    
    chickenSalad.menuItemNumber = "7";
    chickenSalad.itemName = "chicken_salad";
    chickenSalad.itemCost = 4.25;
    items.push_back(chickenSalad);
    
    chickenStrips.menuItemNumber = "8";
    chickenStrips.itemName = "chicken_strips";
    chickenStrips.itemCost = 2.99;
    items.push_back(chickenStrips);
    
    cheeseSandwich.menuItemNumber = "9";
    cheeseSandwich.itemName = "cheese_sandwich";
    cheeseSandwich.itemCost = 3.99;
    items.push_back(cheeseSandwich);
    
    vegetarianSandwich.menuItemNumber = "10";
    vegetarianSandwich.itemName = "vegetarian_sandwich";
    vegetarianSandwich.itemCost = 4.15;
    items.push_back(vegetarianSandwich);
    
    cheesePizza.menuItemNumber = "11";
    cheesePizza.itemName = "cheese_pizza";
    cheesePizza.itemCost = 5.99;
    items.push_back(cheesePizza);
    
    vegetarianPizza.menuItemNumber = "12";
    vegetarianPizza.itemName = "vegetarian_pizza";
    vegetarianPizza.itemCost = 6.25;
    items.push_back(vegetarianPizza);
    
    vegetarianTaco.menuItemNumber = "13";
    vegetarianTaco.itemName = "vegetarian_taco";
    vegetarianTaco.itemCost = 3.99;
    items.push_back(vegetarianTaco);
    
    turkeySandwich.menuItemNumber = "14";
    turkeySandwich.itemName = "turkey_sandwich";
    turkeySandwich.itemCost = 4.25;
    items.push_back(turkeySandwich);
    
    tunaSandwich.menuItemNumber = "15";
    tunaSandwich.itemName = "tuna_sandwich";
    tunaSandwich.itemCost = 4.25;
    items.push_back(tunaSandwich);
    
    chickenBurger.menuItemNumber = "16";
    chickenBurger.itemName = "chicken_burger";
    chickenBurger.itemCost = 4.99;
    items.push_back(chickenBurger);
    
    chickenPizza.menuItemNumber = "17";
    chickenPizza.itemName = "chicken_pizza";
    chickenPizza.itemCost = 6.25;
    items.push_back(chickenPizza);
    
    chickenTaco.menuItemNumber = "18";
    chickenTaco.itemName = "chicken_taco";
    chickenTaco.itemCost = 4.49;
    items.push_back(chickenTaco);
    
    chocolateMuffin.menuItemNumber = "19";
    chocolateMuffin.itemName = "chocolate_muffin";
    chocolateMuffin.itemCost = 0.85;
    items.push_back(chocolateMuffin);
    
    iceCream.menuItemNumber = "20";
    iceCream.itemName = "ice_cream";
    iceCream.itemCost = 0.99;
    items.push_back(iceCream);
    
    return items;
}
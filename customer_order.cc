/**
 * Defines a type that allows the user to place an item
 * for an order, which consists of a menuItem ordered, followed
 * by the number of that item (quantity) that was ordered.
 * 
 * @author Mohit Kewalramani
 * @version 2.0
 * @published 2017-05-15
 */

#include "header.h"

struct customerOrder{
    menuItem item;
    int quantity;
};
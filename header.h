/**
 * Header file that contains the prototype declarations for methods and 
 * structs used throughout the programme. 
 * 
 * @author Mohit Kewalramani
 * @version 2.0
 * @published 2017-05-15
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;


struct menuItem;
struct customerOrder;

vector<menuItem> populateMenu();

string getEmployeeName();
string getItemName();
bool isItemNameValid(string itemName);
int getItemCount();
void deleteLastElement(vector<customerOrder>* order);
void generateInvoiceCopy(string employeeName, 
                        vector<customerOrder>* order, 
                        bool servingStaff);
int returnCurrentYear();
int returnCurrentMonth();
int returnCurrentDay();
double calculateTotalBill(vector<customerOrder>* order, bool servingStaff);
double calculateGST(double billTotalBeforeTax);
double calculatePST(double billTotalBeforeTax);

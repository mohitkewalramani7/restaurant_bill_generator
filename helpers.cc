/**
 * This file contains all the helper methods that are used during throughout
 * this programme.
 * 
 * @author Mohit Kewalramani
 * @version 2.0
 * @published 2017-05-15
 */

#include "header.h"
#include "menu_item.cc"
#include "customer_order.cc"


/**
 * A method thats asks for the employee's (person helping the customer) for
 * their name to be printed on the receipt.
 * @return string The name of the user
 */
string getEmployeeName(){
    string employeeName;
    cout << "Please Enter Your Employee Name: ";
    cin >> employeeName;
    cout << "\n\n";
    return employeeName;
}

/**
 * Method that asks for the item that is being ordered by the customer. This
 * is called in a while loop in the main method until the customer's order
 * is complete.
 * @return string The name/menu_item_number of the item ordered
 */
string getItemName()
{
    string enteredName;
    cout << "Enter Item Name: ";
    cin >> enteredName;
    
    while (!isItemNameValid(enteredName))
    {
        cout << "Enter Item Name: ";
        cin >> enteredName;
    }
    
    cout << "\n";
    return enteredName;
}

/**
 * Checks if the item entered into the command line is a valid one. It checks
 * if the name exists in our menu vector. It also allows the input of a number
 * which would correspond to the menuItemNumber in order to identify the item
 * being ordered.
 * @param itemName The string value of the item entered at the command line
 * @return boolean True if the item exists (name/menu_number)
 */
bool isItemNameValid(string itemName)
{
    vector<menuItem> menu = populateMenu();
    for (int i = 0; i < menu.size(); i++)
    {
        if (itemName == menu.at(i).itemName ||
            itemName == menu.at(i).menuItemNumber ||
            itemName == "end" || 
            itemName == "end_staff" || 
            itemName == "delete")
        {
            return true;
        }
    }
    return false;
}

/**
 * Relays a message to the command line asking for the quantity of the 
 * menuItem ordered. Repeats the message if the entered value is invalid.
 * @return int The quantity of the item ordered
 */
int getItemCount()
{
    int enteredCount;
    bool valid = false;

    while (!valid)
    {
        valid = true;
        cout << "Enter Item Count: ";
        cin >> enteredCount;
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            valid = false;
        }
    }
    
    try
    {
        if (enteredCount <= 0)
        {
            throw 'x';
        }
    }
    catch(char c)
    {
        cout << "Cannot Use a Negative or 0 Number for Count\n";
        enteredCount = getItemCount();
    }
    
    cout << "\n";
    return enteredCount;
}

/**
 * Deletes the last item that was ordered. Items ordered are stored sequentially
 * in a vector. This method deletes the last element of the vector.
 * @param The pointer address of the vector containing the customer's order
 */
void deleteLastElement(vector<customerOrder>* order)
{
    order -> pop_back();
}

/**
 * Generates the bill using the file I/O library. 
 * @param employeeName The name of the attendant to print on the receipt
 * @param order The pointer to the vector's address containing the customer's 
 *              order
 * @param servingStaff Whether or not the customer is a staff member, would 
 *                      receive a discount if so
 */
void generateInvoiceCopy(string employeeName, vector<customerOrder>* order, 
                        bool servingStaff)
{
    ofstream fout;
    fout.open("generated_invoice.txt");
    fout << "\n\n\t\t\t\t\t The Mohit Kewalramani Restaurant \n";
    fout << "--------------------------------------------------------------------------------\n";
    fout << "\t\t\t\t\t\t\t *** Meal Receipt *** \n";
    fout << "--------------------------------------------------------------------------------\n\n\n";
    fout << "Employee Name: " << employeeName;
    fout << "\t\t\t\t\t\t\t\t\t\t\t";
    fout << "Date: " << returnCurrentYear() << "-" << returnCurrentMonth() << "-" << returnCurrentDay() << "\n\n\n";
    fout << "\t\tItem\t\t\t\t" << "Item Price\t\t" << "Quantity Ordered\t\t" << "Item Total\n";
    fout << "\t\t____\t\t\t\t" << "__________\t\t" << "________________\t\t" << "__________\n\n";
    
    int entry_no = 1;
    for (int i = 0; i < order -> size(); i++)
    {
        fout << entry_no << "]";
        fout << "  " << order -> at(i).item.itemName;
        
        int space_count;
        if (entry_no <= 9)
        {
            space_count = 25 - order -> at(i).item.itemName.length();
        }
        else
        {
            space_count = 24 - order -> at(i).item.itemName.length();
        }
        
        for (int j = 0; j < space_count; j++)
        {
            fout << " ";
        }
        fout << "$";
        
        fout << order -> at(i).item.itemCost;
        fout << "\t\t\t\t\t";
        fout << order -> at(i).quantity;
        fout << "\t\t\t\t";
        fout << "$";
        fout << setprecision(2) << fixed << 
                    order -> at(i).item.itemCost * order -> at(i).quantity;
        fout << "\n\n";
        entry_no += 1;
    }
    
    double billTotal = calculateTotalBill(order, false);
    fout << "\n\t\t\t\t\t\t\t\t\t\t\t\t" << " Total Before Tax:  $" << setprecision(2) << fixed << billTotal;
    if (servingStaff){
        billTotal = calculateTotalBill(order, servingStaff);
        fout << "\n\t\t\t\t  " << "Total Before Tax After Staff Discount (20% off):  $" << setprecision(2) << fixed << billTotal;
    }
    fout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << "GST Value:  $" << setprecision(2) << fixed << calculateGST(billTotal);
    fout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << "PST Value:  $" << setprecision(2) << fixed << calculatePST(billTotal);
    
    double totalAfterTax = billTotal + calculateGST(billTotal) + calculatePST(billTotal);
    fout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t      " << "Grand Total:  $" << setprecision(2) << fixed << totalAfterTax;
    fout << "\n\t\t\t\t\t\t\t\t\t\t\t\t" << "      ____________________";
    
    fout << "\n\n  Thanks for stopping by at the MK Restauraunt. We hope to see you soon again !";
    fout.close();
}

/**
 * Returns the current year for constructing the date string for the receipt
 * @return int The current year
 */
int returnCurrentYear()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1900 + ltm -> tm_year;
}

/**
 * Returns the current month for constructing the date string for the receipt
 * @return int The current month
 */
int returnCurrentMonth()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1 + ltm -> tm_mon;
}

/**
 * Returns the current day to construct the date string for the receipt
 * @return int The current day
 */
int returnCurrentDay()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return ltm -> tm_mday;
}

/**
 * Calculates the total amount due for payment for the customer's order. 
 * Takes into account whether or not the customer is a staff member to 
 * factor in the applicable discount.
 * @param order The pointer to the vector's address containing the customer's
 *              order
 * @param servingStaff Whether or not the customer is a staff member
 * @return double The total amount due for the order
 */
double calculateTotalBill(vector<customerOrder>* order, bool servingStaff)
{
    double totalAmount = 0;
    for (int i = 0; i < order -> size(); i++){
        totalAmount = totalAmount + 
                order -> at(i).item.itemCost * order -> at(i).quantity;
    }
    if (servingStaff){
        return totalAmount * 0.8;
    }
    return totalAmount;
}

/**
 * Calculates the amount of GST Tax due based on the bill's total amount
 * @param billTotalBeforeTax The total before tax
 * @return double The GST value to be added as tax
 */
double calculateGST(double billTotalBeforeTax)
{
    double gst_value = 0.05;
    double total_after_gst = gst_value * billTotalBeforeTax;
    return total_after_gst;
}

/**
 * Calculates the amount of PST Tax due based on the bill's total amount
 * @param billTotalBeforeTax The total before tax
 * @return double The PST value to be added as tax
 */
double calculatePST(double billTotalBeforeTax)
{
    double pst_value = 0.07;
    double total_after_pst = pst_value * billTotalBeforeTax;
    return total_after_pst;
}

/**
 * The entry point of the programme from the command line.
 * 
 * @author Mohit Kewalramani
 * @version 2.0
 * @published 2017-05-15
 */

#include "header.h"
#include "helpers.cc"


/**
 * Starting point of the programme from the command line.
 * 
 * @return int The success of the main function (0 is successful)
 */
int main()
{
    vector<customerOrder> placedOrder;
    vector<customerOrder>* pointerToOrder = &placedOrder;

    string employeeName = getEmployeeName();

    string enteredItemName;
    while (true)
    {
        enteredItemName = getItemName();
        if (enteredItemName == "end")
        {
            generateInvoiceCopy(employeeName, pointerToOrder, false);
            break;
        }
        else if (enteredItemName == "end_staff")
        {
            generateInvoiceCopy(employeeName, pointerToOrder, true);
            break;
        }
        else if (enteredItemName == "delete")
        {
            deleteLastElement(pointerToOrder);
        }
        else
        {
            vector<menuItem> allMenuItems = populateMenu();
            for (int i = 0; i < allMenuItems.size(); i++){
                if(allMenuItems.at(i).itemName == enteredItemName || 
                    allMenuItems.at(i).menuItemNumber == enteredItemName){
                    customerOrder order;
                    order.item = allMenuItems.at(i);
                    order.quantity = getItemCount();
                    pointerToOrder -> push_back(order);
                }
            }
        }
    }
    cout << "\n\n" << "Invoice Generated in Current_Invoice.txt !\n\n";
    return 0;
}

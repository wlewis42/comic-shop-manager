/*
Program: prog2.exe
Date: 02/28/2020
Author: William Lewis
Major: Computer Science (Data Science)
Purpose: Comic Book Store Management
*/


#include <iostream>
#include <iomanip>
#include <ctime>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    bool mainMenu= true;
    bool salesMenu= true;
    unsigned int menuChoice;
    time_t rawtime;
    unsigned int salesMenuChoice;
    char reallyQuit = 'n';
    string horizontalLine(50, '-');
    string data;
    double TAX = 0.06;
    double itemPrice;
    double saleQuantity;
    float totalPrice;
    char salesContinue;
    char killFile('n');

    //Use do while for the main menu bc we want it to run at least once
    do 
    {
        cout << horizontalLine << endl;
        cout << "Super Powered Comics Management Program\n\n";
        cout << "Please select from the following menu items:\n";
        cout << "1. Enter sales.\n";
        cout << "2. Total sales for the day.\n";
        cout << "3. Delete sales for the day.\n";
        cout << "4. End program.\n";
        cin >> menuChoice;

        //Check for choice validity
        while (menuChoice > 4 || menuChoice < 1)
        {
            cout << "Choice is not available. Please choose between 1-4... ";
            cout << endl;
            cin>>menuChoice;
        }
        //Main menu cases
        switch (menuChoice) 
        {
            case 1:
            {
            
                salesMenu = true;
                //Loop sales menu until user is finished
                while (salesMenu)
                {
                    cout << "You chose 'Enter sales'\n\n";
                    cout << "\nChoose the department from the following menu:\n";
                    cout << "1. Comics\n";
                    cout << "2. Collectibles\n";
                    cout << "3. Games\n";
                    cout << "4. Main Menu\n";
                    cout << "Choose 1, 2, or 3: ";
                    cin >> salesMenuChoice;

                    //Open file in write mode
                    ofstream filename;
                    filename.open("sales.txt", ios::app);

                    //Sales menu cases
                    switch (salesMenuChoice)
                    {
                        case 1:
                            cout << horizontalLine << endl;
                            cout << "'Comics'\n";
                            cout << horizontalLine << endl;
                        
                            //User inputs sale information
                            cout << "What is the price of the item? ";
                            cin >> itemPrice;
                            cout << "How many did they buy? ";
                            cin >> saleQuantity;

                            //Calculates total sale including TAX
                            totalPrice = (itemPrice * saleQuantity)+((itemPrice * saleQuantity) * TAX);

                            //write inputted data
                            cout << fixed << setprecision(2) << "$" << totalPrice << endl;
                            filename << "Comics\r\n" << fixed << setprecision(2) << totalPrice << "\r\n";

                            //close the opened file
                            filename.close();

                            cout << "Do you want to enter more sales? (y or n): ";
                            cin >> salesContinue;
                            if (salesContinue == 'y') 
                            {
                                salesMenu = true;
                            } 
                            else 
                            {
                                salesMenu = false;
                                cout << "\nReturning to main menu...\n\n";
                            }
                        break; 
                        case 2:
                            cout << horizontalLine << endl;
                            cout << "'Collectibles'\n";
                            cout << horizontalLine << endl;
                            
                            cout << "What is the price of the item? ";
                            cin >> itemPrice;
                            cout << "How many did they buy? ";
                            cin >> saleQuantity;
                            totalPrice =(itemPrice*saleQuantity) + ((itemPrice * saleQuantity) * TAX);

                            //write inputted data
                            cout << fixed << setprecision(2) << "$" << totalPrice << endl;
                            filename << "Collectibles\r\n" << fixed << setprecision(2) << totalPrice <<"\r\n";

                            //close the opened file
                            filename.close();

                            cout << "Do you want to enter more sales? (y or n): ";
                            cin >> salesContinue;
                            if (salesContinue == 'y') 
                            {
                                salesMenu = true;
                            } 
                            else 
                            {
                                salesMenu = false;
                                cout << "\nReturning to main menu...\n\n";
                            }
                            break;
                        case 3:
                            cout << horizontalLine << endl;
                            cout << "'Games'\n";
                            cout << horizontalLine << endl;
                            
                            //User inputs sale info
                            cout << "What is the price of the item? ";
                            cin >> itemPrice;
                            cout << "How many did they buy? ";
                            cin >> saleQuantity;

                            //Calculate total sale including TAX
                            totalPrice = (itemPrice * saleQuantity)+((itemPrice * saleQuantity) * TAX);

                            //write inputted data
                            cout << fixed << setprecision(2) << "$" << totalPrice << endl;
                            filename << "Games\r\n" << fixed << setprecision(2) << totalPrice << "\r\n";

                            //close the opened file
                            filename.close();

                            //Asks if another sale should be entered
                            cout << "Do you want to enter more sales? (y or n): ";
                            cin >> salesContinue;
                            if (salesContinue == 'y') 
                            {
                                salesMenu = true;
                            } 
                            else 
                            {
                                salesMenu = false;
                                cout << "\nReturning to main menu...\n\n";
                            }
                            break;
                        case 4:
                            cout << horizontalLine << endl;
                            cout << "Returning to Main Menu...\n\n";
                            cout << horizontalLine << endl;
                            salesMenu = false;
                            filename.close();
                            break;
                        default:
                            cout << "Invalid choice, please choose 1-4:\n";
                    }
                }
            }break;
            case 2:
            {
                cout << "You chose 'Total sales for the day'\n";
                time(&rawtime);
                cout << horizontalLine << endl;
                cout << "TOTAL SALES ON " << ctime(&rawtime);
                cout << horizontalLine << endl;
                
                //Sets infile stream
                ifstream infile("sales.txt");

                //Check for failure in opening
                if(infile.fail()) 
                {
                    cout << "Error opening input file.\n\n";
                }
                //If fail returns false, run totaling
                else 
                {
                    double comicsTotal = 0.00;
                    double collectiblesTotal = 0.00;
                    double gamesTotal = 0.00;

                    //Read infile until the end of file
                    while(!infile.eof())
                    {
                        double money;
                    
                        //Loop infile line by line and set first line to data
                        while(infile>>data)
                        {
                        
                            /*Check if data is one of the 3 departments
                            If so, returns next nonempty line as the double 'money'
                            and adds amount to running total per department*/
                            if (data.compare("Comics") == 0) 
                            {
                                infile >> money;
                                comicsTotal += money;
                            } 
                            else if (data.compare("Collectibles") == 0) 
                            {
                                infile >> money;
                                collectiblesTotal += money;
                            } 
                            else if (data.compare("Games") == 0)
                            {
                                infile >> money;
                                gamesTotal += money;
                            }
                        }
                    }
                    //Close file
                    infile.close();
                    
                    //Prints totals of all departments
                    cout<<right<<setw(15)<<"Comics: "<<right<<setw(15)<<comicsTotal<<endl;
                    cout<<right<<setw(15)<<"Collectibles: "<<right<<setw(15)<<collectiblesTotal<<endl;
                    cout<<right<<setw(15)<<"Games: "<<right<<setw(15)<<gamesTotal<<endl;
                }
            }break;
            case 3:
            {
                //Asks user if they really want to delete the sales file for the day
                cout << "You chose 'Delete sales for the day'\n\n";
                cout << "Do you really want to delete today's sales? (y or n)";
                cin >> killFile;
                //If user input is 'y', check for delete file error
                if (killFile == 'y')
                {
                    if(remove("sales.txt") !=0)
                        cout << "Error deleting file!\n\n";
                    
                    //No error prints delete confirmation
                    else
                        cout << "File deleted.\n\n";
                }
                //Anything other than 'y' doesn't delete 'sales.txt' and returns to main menu
                else 
                {
                    cout << "You have chosen not to delete the file.\n\n";
                }
            }break;
            case 4:
                //Asks if user wants to quit and if not, returns to main menu
                cout << "Did you really want to quit? y to quit, anything else to continue:";
                cin >> reallyQuit;
                switch (reallyQuit) 
                {
                    case 'y':
                        cout << "Have a 'SUPER' day!"<<endl;
                        mainMenu = false;
                    break;
                    default:
                        cout << "Returning to main menu...\n";
                }
                break;
            default:    
                break; 
        } 
    }while(mainMenu);
    return 0;
}

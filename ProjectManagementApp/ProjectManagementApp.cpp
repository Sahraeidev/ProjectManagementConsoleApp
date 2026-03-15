#include <iostream>
#include <fstream>

using namespace std;

//CLASSES AND PROTOTYPES RELTED TO ACCOUNT MANAGEMENT
class Account{
    public:
    Account(string name,string password)
    {
        Name = name;
        Password = password;
    }


    void SetName(string name)
    {
        Name = name;
    }
    void SetPassword(string password)
    {
        Password = password;
    }

    string GetName()
    {
        return Name;
    }
    string GetPassword()
    {
        return Password;
    }

    private:

    string Name;
    string Password;

};
Account* CreateAccount();
Account* LoginMenu();
Account* AccountMenu();

int main() {

    //DISPLAY THE ACCOUNT MENU
    Account* CurrentAccount = AccountMenu();
    system("cls");
    
    if(CurrentAccount == nullptr)
    {
        cout << ">>Error creating or logging into account" << endl;
        exit(0);
    }

    cout<<"====WELCOME "<<CurrentAccount->GetName() << "====" << endl;
    cout << ">>This is the main menu of the project management app" << endl;
    cout << ">>You can manage the tasks of your projects here" << endl;

}

//FUNCTIONS RELATED TO ACCOUNT MANAGEMENT

//THIS FUNCTION FINDS THE USER AND PASS IN FILES
Account* LoginMenu()
{

        string tempName,tempPassword;
        cout << "====LOGIN====" << endl;
        cout<<"Enter your name: ";
        cin>>tempName;
        cout<<"Enter your password: ";
        cin>>tempPassword;
        cout << ">>Logging in..." << endl;
        //Find the account with the name and password in the file;
        ifstream AccountFile("accounts.txt",ios::in);
        string n,p;
        while(AccountFile >> n >> p)
        {
    
            if(n == tempName && p == tempPassword)
            {
                cout << ">>Login successful" << endl;
                Account* tempAccount = new Account(tempName,tempPassword);
                system("cls");
                return tempAccount;
            }
        }
        cout << ">>Account not found" << endl;
        cout << "1. Try Again" << endl;
        cout << "2. Exit" << endl;
        int choice;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            return LoginMenu();
            break;
        case 2:
            exit(0);
            break;
        }

    
}
//THIS FUNCTION DISPLAYS THE ACCOUNT MENU
Account* AccountMenu()
{
    while(1)
    {
        cout << "====ACCOUNT MENU====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            return CreateAccount();
            break;
        case 2:
            return LoginMenu();
            break;
        case 3:
            exit(0);
            break;
        }
    }
    

}
//THIS FUNCTION CREATES AN ACCOUNT AND SAVES IT IN THE ACCOUNTS FILE
Account* CreateAccount()
{
    cout << "====CREATE ACCOUNT====" << endl;
    string name,password;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter your password: ";
    cin>>password;

    ofstream AccountFile("accounts.txt",ios::app);
    AccountFile << name << " " << password << "\n" << endl;

    Account* account = new Account(name,password);
    return account;
}


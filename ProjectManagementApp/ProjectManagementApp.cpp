#include <iostream>
#include <fstream>

using namespace std;

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
    Account* CurrentAccount = AccountMenu();
    cout<<"WELCOME "<<CurrentAccount->GetName()<<endl;

}


Account* LoginMenu()
{
    while(1)
    {
        string tempName,tempPassword;
        cout<<"Enter your name: ";
        cin>>tempName;
        cout<<"Enter your password: ";
        cin>>tempPassword;

        //Find the account with the name and password in the file;
        ifstream AccountFile("accounts.txt",ios::in);
        string n,p;
        while(AccountFile >> n >> p)
        {
    
            if(n == tempName && p == tempPassword)
            {
               Account* tempAccount = new Account(tempAccount,tempAccount);
               return tempAccount;
            }
        }
        cout << "Account not found" << endl;
        cout << "1. Try Again" << endl;
        cout << "2. Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            break;
        case 2:
            return nullptr;
            break;
        }
    }
    
}
Account* AccountMenu()
{
    while(1)
    {
        cout << "1. Create Account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;
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
Account* CreateMenu()
{
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


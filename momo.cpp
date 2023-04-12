#include <iostream>
#include <iostream>
#include <string>

using namespace std;

class MobileMoneyService {
private:
    string pin;
    float balance;
    int num_wrong_attempts;
    

public:
    MobileMoneyService() {
        pin = "0000";
        balance = 1000;
        num_wrong_attempts = 0;
        
    }

    bool authenticate(string entered_pin) {
        if (entered_pin == pin) {
            num_wrong_attempts = 0;
            return true;
        }
        else {
            num_wrong_attempts++;
            if (num_wrong_attempts >= 3) {
                cout << "Too many wrong attempts. Exiting program." << endl;
                return false;
            }
            else {
                cout << "Wrong pin. Please try again." << endl;
                return false;
            }
        }
    }

    void reset_pin() {
        string current_pin;    
		{
		cout << "Enter your current pin: "<< endl;;
        cin >> current_pin;

        if (authenticate(current_pin)) {
            string new_pin;
            cout << "Enter your new pin: ";
            cin >> new_pin;
            pin = new_pin;
            cout << "Pin has been changed:" << new_pin << endl;
		}
		
         
        }
    }

    void check_balance() 
	{
      cout << "Fee is GHS 0.00 .Enter MM PIN:" << endl;
      cin >> pin;
        cout << "Your balance is: " << balance << endl;
		cout << "Available balance:" << balance << endl;
    
    }

    void send_money() {
        string recipient_number ;
        double amount;
        string reference;
        cout << "Enter recipient number: ";
        cin >> recipient_number;
        cout << "Enter amount to send: ";
        cin >> amount;
        cout << "Enter reference: ";
        cin >> reference;
        cout << "Please enter your MM PIN:" << endl;
        cin >> pin;
         

        if (amount > balance) {
            cout << "Insufficient funds." << endl;
        }
        else {
            balance -= amount;
            cout << "You have sent " << amount << " to " << recipient_number << "." << endl;
            cout << "Your new balance is: " << balance << endl;
            cout << "Available balance is:" << balance << endl;
            cout << " Thanks for using Mobile Money" << endl;
        }
      }      
    	
};

int main() {
    MobileMoneyService mms;

    bool exit_program = false;
    while (!exit_program) {
        cout << "Welcome to the Mobile Money Service." << endl;
        cout << "Main Menu" << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Reset/Change Pin" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Send Money" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
            	
                string entered_pin;
                cout << "Enter your pin: ";
                cin >> entered_pin;

                if (mms.authenticate(entered_pin)) {
                    cout << "Access granted." << endl;
                }
                break;
            }
            case 2:
                mms.reset_pin();
                break;
            case 3:
                mms.check_balance();
                break;
            case 4:
                mms.send_money();
                break;
            case 5:
                exit_program = true;
                cout << "Exiting program." << endl;
               
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;

}

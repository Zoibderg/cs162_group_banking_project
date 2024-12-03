
#include <iostream>
using namespace std; 

class BankAccount   
{
public: 
	void deposit() // allows user to make a deposit into the account 
	{
		cout << " Enter amount to deposit: " << endl; 
		cin >> depositamount; 

		balance += depositamount; 

		cout << " Successfully deposited " << depositamount << endl; 
		cout << " === Current account balance ==== " << endl; 
		get_current_balance(); 

	}

	void withdraw() // allows the user to withdrawl money from their accounts 
	{
		cout << " Enter amount to withdrawl: " << endl; 
		cin >> withdrawlamount; 

		balance -= withdrawlamount; 

		cout << " Successfully withdrawled amount " << withdrawlamount << endl; 
		cout << " === Current account balance === " << endl; 
		get_current_balance(); 

	}

	double get_current_balance()  // displays the balance of the users accounts to the screen
	{
		cout << " Current Balance: " << balance << endl;
	}

	string get_account_holder()
	{
		cout << " The account holder is: " << account_holder <<  endl;  
	}

	void generate_statement()
	{
             cout << " Here is your account statement. " << endl; 
		cout << " ACCOUNT OWNER: " << get_account_holder() << endl; 
		cout << " CURRENT BALANCE: " << get_curent_balance() << endl;
		cout << " CURRENT INTEREST RATE: " <<  calcuate_interest() << endl; 
		cout << " OVERDRAFT CHARGES: " << check_overdraft() << endl;	
	}
private:
	int account_number;
	double balance;
	double depositamount;
	double withdrawlamount; 
	string account_type;
	string account_status; 
	string account_holder; 
};
class SavingsAccount : public BankAccount 
{
public:
	double interest_rate = 1.05;
	double withdrawlamount; 
	void calcuate_interest() // calculates the interest based on the amount in the users account 
	{
         
	}
	 
	void apply_interest() // applys the interest to the account
	{

	}
	void Withdrawl()
	{
		if (withdrawlamount < 1000.00) // applys the penalty is the user withdrawls more than $1000 
		{
			cout << " Withdrawl penalty of $50.00 will be added" << endl; 
			withdrawl_penalty += withdrawlamount; // adds penalty to withdrawl amount
			cout << " Total amount: $" << withdrawlamount << endl; 
			cout << " === Current balance === " << endl; 
			get_current_balance(); // displays current balance after the withdrawl
		}
	}

private: 
	double withdrawl_penalty = 50.00; 
};

class CreditAccount : public BankAccount
{
public: 
	double APR;

	void calculate_min_payment() // calculates the minimum payment user must make on the credit cardd
	{

	}

private: 
	double credit_limit;
	double current_balance; 

};

class CheckingAccount : public BankAccount 
{
public:
	double accountbalance; 
	void check_overdraft() // checks to see if the user is negative in the account 
	{
		if (accountbalance < 0)
		{
			cout << " Account balance went negative. Overdraft fee of $25.00 being applied" << endl; 
		}
		else if (accountbalance > 0)
		{
			cout << " No overdraft fee applied" << endl; 
		}
	}
	void apply_overdraft_fee() // apples the over draft fee to the users account 
	{
		accountbalance -= overdraftfee; 
		cout << " === Current Account Balance === " << endl;
		get_current_balance(); 
	}

private:
	double overdraft_limit; 
	double interest = 0.02; 
	double overdraftfee = 25.00; 
};

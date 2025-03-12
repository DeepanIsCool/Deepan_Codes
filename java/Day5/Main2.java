package Day5;

import java.util.ArrayList;
import java.util.List;

// Define the Account interface with required methods
interface Account {
    void deposit(double amount);

    void withdraw(double amount);

    double calculateInterest();

    double viewBalance();
}

// Implement the SavingsAccount class that implements the Account interface
class SavingsAccount implements Account {
    private double balance;
    private double interestRate;

    // Constructor to initialize balance and interest rate
    public SavingsAccount(double balance, double interestRate) {
        this.balance = balance;
        this.interestRate = interestRate;
    }

    @Override
    public void deposit(double amount) {
        balance += amount;
    }

    @Override
    public void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            System.out.println("Insufficient balance.");
        }
    }

    @Override
    public double calculateInterest() {
        return balance * interestRate / 100;
    }

    @Override
    public double viewBalance() {
        return balance;
    }
}

// Implement the CurrentAccount class that implements the Account interface
class CurrentAccount implements Account {
    private double balance;
    private double overdraftLimit;

    // Constructor to initialize balance and overdraft limit
    public CurrentAccount(double balance, double overdraftLimit) {
        this.balance = balance;
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    public void deposit(double amount) {
        balance += amount;
    }

    @Override
    public void withdraw(double amount) {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
        } else {
            System.out.println("Overdraft limit exceeded.");
        }
    }

    @Override
    public double calculateInterest() {
        return 0; // Current accounts typically do not earn interest
    }

    @Override
    public double viewBalance() {
        return balance;
    }
}

// Implement the Bank class that manages a list of accounts
class Bank {
    private List<Account> accounts;

    // Constructor to initialize the list of accounts
    public Bank() {
        accounts = new ArrayList<>();
    }

    // Method to add an account to the bank
    public void addAccount(Account account) {
        accounts.add(account);
    }

    // Method to display all account balances
    public void displayAllBalances() {
        for (Account account : accounts) {
            System.out.println("Account Balance: " + account.viewBalance());
        }
    }
}

public class Main2 {
    public static void main(String[] args) {
        // Create a Bank object
        Bank bank = new Bank();

        // Create SavingsAccount and CurrentAccount objects
        SavingsAccount savingsAccount = new SavingsAccount(1000, 5);
        CurrentAccount currentAccount = new CurrentAccount(500, 1000);

        // Add accounts to the bank
        bank.addAccount(savingsAccount);
        bank.addAccount(currentAccount);

        // Perform some operations
        savingsAccount.deposit(200);
        savingsAccount.withdraw(100);
        System.out.println("Savings Account Interest: " + savingsAccount.calculateInterest());

        currentAccount.deposit(300);
        currentAccount.withdraw(700);
        System.out.println("Current Account Balance: " + currentAccount.viewBalance());

        // Display all account balances
        bank.displayAllBalances();
    }
}
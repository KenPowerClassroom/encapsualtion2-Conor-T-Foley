#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
        std::cout << "Withdrawal successful. New balance: $" << balance << std::endl;
    }

    void manageBankAccount() {
        if (getBalance() > 500) {
            withdraw(500);

        }
        else {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
    }
};
class HeatingSystem {
public:
    void turnOn() {
        std::cout << "Heating system turned on." << std::endl;
    }

    void turnOff() {
        std::cout << "Heating system turned off." << std::endl;
    }
};

class Thermostat {
private:
    double currentTemperature;
    HeatingSystem heating; 
    const int minimumTemperature = 20;
public:
    Thermostat(double temperature) : currentTemperature(temperature) {}

    double getCurrentTemperature() const {
        return currentTemperature;
    }

    void switchOn() {
        heating.turnOn();
    }
    void switchOff() {
        heating.turnOn();
    }

    void regulateTemp() {
        if (getCurrentTemperature() < minimumTemperature) {
            switchOn();
        }
        else {
            switchOff();
        }
    }
};
#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    bool isAvailable;

public:
    Book(const std::string& title) : title(title), isAvailable(true) {}

    bool checkAvailability() const {
        return isAvailable;
    }

    void borrowBook() {
        isAvailable = false;
    }

    void returnBook() {
        isAvailable = true;
    }

    void queryBookBorrow() {
        if (checkAvailability()) {
            borrowBook();
            std::cout << "Book borrowed successfully." << std::endl;
        }
        else {
            std::cout << "Book is not available for borrowing!" << std::endl;
        }
    }
};

class Library {
public:


    //void processBookBorrowing(Book& book) {
    //    // Violates Tell, Don't Ask
    //    if (book.checkAvailability()) {
    //        book.borrowBook();
    //        std::cout << "Book borrowed successfully." << std::endl;
    //    }
    //    else {
    //        std::cout << "Book is not available for borrowing." << std::endl;
    //    }
    //}

    void processBookBorrowing(Book& book) {
        book.queryBookBorrow();
    }
};

class Player {
private:
    int health;
    int ammo;

public:
    Player() : health(100), ammo(10) {}

    int getHealth() const {
        return health;
    }

    int getAmmo() const {
        return ammo;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    void useAmmo() {
        ammo--;
    }

    void processAttack() {
        if (getHealth() > 0 && getAmmo() > 0) {
            takeDamage(10);
            useAmmo();
            std::cout << "Player attacked and used ammo." << std::endl;
        }
        else {
            std::cout << "Player can't respond to attack." << std::endl;
        }
    }
};

class Game {
public:
    /*void enemyAttack(Player& player) {
        if (player.getHealth() > 0 && player.getAmmo() > 0) {
            player.takeDamage(10);
            player.useAmmo();
            std::cout << "Player attacked and used ammo." << std::endl;
        }
        else {
            std::cout << "Player can't respond to attack." << std::endl;
        }
    }*/

    void enemyAttack(Player& player) {
        player.processAttack();
    }
};


int main() {
    //////////////////////////////////////////////////////////////////
    // Exercise 1
    //////////////////////////////////////////////////////////////////
 
    BankAccount account(1000.0);
    account.manageBankAccount();
   
    
    //////////////////////////////////////////////////////////////////
    // Exercise 2
    //////////////////////////////////////////////////////////////////

    Thermostat thermostat(18.5);
    
    thermostat.regulateTemp();
    
    
    //////////////////////////////////////////////////////////////////
    // Exercise 3
    //////////////////////////////////////////////////////////////////

    Book myBook("1984");
    Library library;

    library.processBookBorrowing(myBook);  // First borrow should succeed
    library.processBookBorrowing(myBook);  // Second attempt should show not available

    //////////////////////////////////////////////////////////////////
    // Exercise 4
    //////////////////////////////////////////////////////////////////
    Player player;
    Game game;

    game.enemyAttack(player); // Player can respond to attack

    return 0;
}

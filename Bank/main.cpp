#include<iostream>

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNum, double initBalance) : accountNumber(accNum), balance(initBalance), interestRate(0.0) { //конструктор
    }

    void deposit(double amount) { // функция для внесения средств на счет
        if (amount > 0) {
            balance += amount;
            std::cout << "Депозит успешный. Новый баланс: " << balance << std::endl;
        } else {
            std::cout << "Недействимая сумма для депозита." << std::endl;
        }
    }

    bool withdraw(double amount) { // снятие со счета
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Вывод средств удался.Новый баланс: " << balance << std::endl;
            return true;
        } else {
            std::cout << "Недостаточно средств для вывода или недействительная сумма." << std::endl;
            return false;
        }
    }

    double getBalance() { // текущий баланс
        return balance;
    }

    double getInterest() { // для расчета полученных процентов
        return balance * interestRate * (1 / 12);
    }

    void setInterestRate(double newRate) { // обновление процентной ставки
        interestRate = newRate;
    }

    int getAccountNumber() { // получения номера банковского счета
        return accountNumber;
    }

    friend bool transfer(BankAccount& sender, BankAccount& receiver, double amount); // дружествення функция для перевода средств между счетами

};

bool transfer(BankAccount& sender, BankAccount& receiver, double amount) { // перевод средств
    if (amount > 0 && sender.balance >= amount) {
        sender.balance -= amount;
        receiver.balance += amount;
        std::cout << "Перевод прошел успешно. Новый баланс отправителя: " << sender.balance << ", новый баланс приемника: " << receiver.balance << std::endl;
        return true;
    } else {
        std::cout << "Перевод не выполнен. Недостаточно средств или неверная сумма." << std::endl;
        return false;
    }
}

int main() {
    BankAccount account1(13567, 2000.0);
    BankAccount account2(35412, 600.0);

    account1.deposit(300.0);
    account1.withdraw(100.0);
    account2.deposit(200.0);

    account1.setInterestRate(0.05);
    std::cout << "Заработанные проценты: " << account1.getInterest() << std::endl; // Вывовд полученных процентов
    transfer(account1, account2, 400.0);

    return 0;
}


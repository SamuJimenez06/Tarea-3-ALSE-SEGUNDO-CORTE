#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <vector>

class BankAccount {
private:
    int balance;
    bool is_open;
    mutable std::mutex mtx;

public:
    BankAccount() : balance(0), is_open(false) {}

    void open() {
        std::lock_guard<std::mutex> lock(mtx);
        if (is_open) {
            throw std::runtime_error("La cuenta ya esta abierta.");
        }
        balance = 0;
        is_open = true;
    }

    void close() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!is_open) {
            throw std::runtime_error("La cuenta ya esta cerrada.");
        }
        is_open = false;
    }

    int get_balance() const {
        std::lock_guard<std::mutex> lock(mtx);
        if (!is_open) {
            throw std::runtime_error("La cuenta esta cerrada.");
        }
        return balance;
    }

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!is_open) {
            throw std::runtime_error("No se puede depositar en una cuenta cerrada.");
        }
        if (amount <= 0) {
            throw std::runtime_error("El monto a depositar debe ser mayor a cero.");
        }
        balance += amount;
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!is_open) {
            throw std::runtime_error("No se puede retirar de una cuenta cerrada.");
        }
        if (amount <= 0) {
            throw std::runtime_error("El monto a retirar debe ser mayor a cero.");
        }
        if (amount > balance) {
            throw std::runtime_error("Saldo insuficiente.");
        }
        balance -= amount;
    }
};

int main() {
    std::cout << "==========================================" << std::endl;
    std::cout << "          EJERCICIO 02: BANK ACCOUNT      " << std::endl;
    std::cout << "==========================================" << std::endl;

    BankAccount account;
    account.open();
    std::cout << "Cuenta abierta correctamente. Saldo inicial: $" << account.get_balance() << std::endl;

    // Prueba Concurrente con múltiples hilos en paralelo
    std::cout << "\nEjecutando 100 depositos y 50 retiros concurrentes..." << std::endl;
    std::vector<std::thread> threads;

    for (int i = 0; i < 100; ++i) {
        threads.emplace_back([&account]() {
            account.deposit(10);
        });
    }

    for (int i = 0; i < 50; ++i) {
        threads.emplace_back([&account]() {
            account.withdraw(5);
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Saldo final tras concurrencia: $" << account.get_balance() << " (Esperado: $750)" << std::endl;

    account.close();
    std::cout << "Cuenta cerrada." << std::endl;
    std::cout << "==========================================" << std::endl;

    return 0;
}
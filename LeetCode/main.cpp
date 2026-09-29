#include <iostream>
#include "AuthenticatorManager.cpp"
#include "ExamTracker.cpp"

int main() {
    std::cout << "=== PRUEBA 1: Authentication Manager ===" << std::endl;
    AuthenticationManager* authManager = new AuthenticationManager(5);
    authManager->renew("aaa", 1);
    authManager->generate("aaa", 2);
    std::cout << "Tokens activos en t=6: " << authManager->countUnexpiredTokens(6) << " (Esperado: 1)" << std::endl;
    delete authManager;

    std::cout << "\n=== PRUEBA 2: Exam Score Tracker ===" << std::endl;
    ExamTracker* tracker = new ExamTracker();
    tracker->record(1, 98);
    std::cout << "totalScore(1, 1): " << tracker->totalScore(1, 1) << " (Esperado: 98)" << std::endl;
    tracker->record(5, 99);
    std::cout << "totalScore(1, 5): " << tracker->totalScore(1, 5) << " (Esperado: 197)" << std::endl;
    delete tracker;

    return 0;
}

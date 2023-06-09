#include <iostream>
#include <cstdlib>
#include <ctime>

enum class Choice { BATU, GUNTING, KERTAS };

Choice getUserChoice() {
    int choice;
    std::cout << "Pilihan Anda (0: Batu, 1: Gunting, 2: Kertas): ";
    std::cin >> choice;

    if (choice < 0 || choice > 2) {
        std::cout << "Pilihan tidak valid. Silakan pilih lagi." << std::endl;
        return getUserChoice();
    }

    return static_cast<Choice>(choice);
}

Choice getComputerChoice() {
    int choice = rand() % 3;
    return static_cast<Choice>(choice);
}

void playGame() {
    std::cout << "Selamat datang di Permainan Batu Gunting Kertas!" << std::endl;

    Choice userChoice = getUserChoice();
    Choice computerChoice = getComputerChoice();

    std::cout << "Anda memilih ";
    switch (userChoice) {
        case Choice::BATU:
            std::cout << "Batu";
            break;
        case Choice::GUNTING:
            std::cout << "Gunting";
            break;
        case Choice::KERTAS:
            std::cout << "Kertas";
            break;
    }
    std::cout << std::endl;

    std::cout << "Komputer memilih ";
    switch (computerChoice) {
        case Choice::BATU:
            std::cout << "Batu";
            break;
        case Choice::GUNTING:
            std::cout << "Gunting";
            break;
        case Choice::KERTAS:
            std::cout << "Kertas";
            break;
    }
    std::cout << std::endl;

    if (userChoice == computerChoice) {
        std::cout << "Hasil: Seri!" << std::endl;
    } else if (
            (userChoice == Choice::BATU && computerChoice == Choice::GUNTING) ||
            (userChoice == Choice::GUNTING && computerChoice == Choice::KERTAS) ||
            (userChoice == Choice::KERTAS && computerChoice == Choice::BATU)
            ) {
        std::cout << "Hasil: Anda Menang!" << std::endl;
    } else {
        std::cout << "Hasil: Komputer Menang!" << std::endl;
    }
}

int main() {
    srand(time(0)); // Inisialisasi seed untuk fungsi random

    char playAgain;
    do {
        playGame();
        std::cout << "Apakah Anda ingin bermain lagi? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

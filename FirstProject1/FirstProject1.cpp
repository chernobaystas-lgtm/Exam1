#include "HeaderForFP1.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    InitBaseCategories();
    LoadProductsFromFile();

    int choice;
    while (true) {
        FirstMainMenu();
        choice = safeInputInt("Ваш вибір: ");

        switch (choice) {
        case 1: { 
            int catChoice;
            while (true) {
                CategoryMenu();
                catChoice = safeInputInt("Ваш вибір: ");
                if (catChoice == 1) 
                    Add_Category();
                else if (catChoice == 2) 
                    Delete_Category();
                else if (catChoice == 3) 
                    Show_all_Categories();
                else if (catChoice == 0) 
                    break;
                else cout << "Невірний вибір.\n";
            }
            break;
        }
        case 2: { 
            int prodChoice;
            while (true) {
                ProductMenu();
                prodChoice = safeInputInt("Ваш вибір: ");
                if (prodChoice == 1) Add_Product();
                else if (prodChoice == 2) 
                    Delete_Product();
                else if (prodChoice == 3) 
                    Show_all_Products();
                else if (prodChoice == 4) 
                    Change_Product();
                else if (prodChoice == 0) 
                    break;
                else cout << "Невірний вибір.\n";
            }
            break;
        }
        case 3: { // Пошук
            int searchChoice;
            while (true) {
                SearchMenu();
                searchChoice = safeInputInt("Ваш вибір: ");
                if (searchChoice == 1) 
                    Find_by_name();
                else if (searchChoice == 2) 
                    Find_by_manufacturer();
                else if (searchChoice == 3) 
                    find_by_price();
                else if (searchChoice == 4) 
                    find_by_category();
                else if (searchChoice == 5) 
                    find_by_expiry_date();
                else if (searchChoice == 6) 
                    find_by_date_since_in_store();
                else if (searchChoice == 0) 
                    break;
                else cout << "Невірний вибір.\n";
            }
            break;
        }
        case 4: { // Сортування
            int sortChoice;
            while (true) {
                SortMenu();
                sortChoice = safeInputInt("Ваш вибір: ");
                if (sortChoice == 1) 
                    sort_by_price();
                else if (sortChoice == 2) 
                    sort_by_category();
                else if (sortChoice == 0) 
                    break;
                else cout << "Невірний вибір.\n";
            }
            break;
        }
        case 0: // Вихід
            SaveProductsToFile();
            cout << "Дані збережено. До побачення!\n";
            return 0;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }
    
    return 0;
}


#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

struct Category {
	char name_of_category[40];
	int id;
};

enum CategoryId
{
    MILK = 1,
    TOOLS,
    PRODUCTS,
    COSMETICS,
    HYGIENE,
    ELECTRONICS,
    HOUSEHOLD,
    STATIONERY,
    SPORT,
    CLOTHES
};

struct Product {
	char name[30];
	char manufacturer[30];
	int  categoryId;
	double price;
	int date_since_in_store;
	int expiry_date;
};

extern Category categories[30];
extern int categoryCount;
extern int nextCategoryId;

extern Product products[50];
extern int productCount;


void FirstMainMenu();
void CategoryMenu();
void ProductMenu();
void SearchMenu();
void SortMenu();

void PrintProduct(const Product& product);
void clearInput();
int safeInputInt(const char* prompt);
void safeInputStr(const char* prompt, char* buffer, int maxLen);
int safeInputDate(const char* prompt);
double safeInputDouble(const char* prompt);

void InitBaseCategories();
int Add_Category();
int Show_all_Categories();
int Delete_Category();
int FindCategoryIndex(int id);
const char* GetCategoryName(int id);

int Add_Product();
int Show_all_Products();
int Delete_Product();
int Change_Product();

bool containsIgnoreCase(const char* text, const char* query);
int Find_by_name();
int Find_by_manufacturer();
int find_by_price();
int find_by_category();
int find_by_expiry_date();
int find_by_date_since_in_store();

int myStrCompare(const char* a, const char* b);
int sort_by_price();
int sort_by_category();

void LoadProductsFromFile();
void SaveProductsToFile();

// === –≈√≤—“– ===
void toLower(char* str);
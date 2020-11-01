#pragma once
#include "iostream"

namespace std_a{
class string_a{
    public:
        string_a(const char* str);
        ~string_a();
        // Общии функции
        bool copy(const char* str,char* dest); // Копирование с проверкой
        bool copy(int start_s,int start_d,int end_s,const char* str,char* dest); // Копирование с проверкой и с промежутками
        
    const char* get_c() const{
            return (const char*) string;
    }
    // Операторы
    friend std::ostream& operator<< (std::ostream &out, const string_a& str);
    string_a& operator=(const string_a& str); 
    string_a& operator=(const char* str);
    string_a& operator+(const char* str);
    string_a& operator+(const int digit);
    string_a& operator+(const string_a& str);
    private:
        char* string;
        int len = 0;
        bool copy_exc(int start_s,int start_d,int end_s,const char* str,char* dest); // Копирование с промежутками без проверки
        void copy_exc(const char* str,char* dest); // Копирование без проведения проверки
        int strlen(const char* str);


        
};

}
#include "string_a.h"
#include "iostream"
using namespace std_a;
int string_a::strlen(const char* str){ // Длина строки без учёта конца строки
        int len_b = 0;
    try{
        char buff = 'a';
        int i = 0;
        while(buff!='\0'){
            len_b = i;
            buff=*(str+i);
            i++;
        }
    }catch(int err){
        return -1;
    }
    return len_b;
}
string_a::string_a(const char* str){
    std::cout << "creating" << "\n";
    int len_b = strlen(str);
    string = new char[len_b+1];
    string[len_b] = '\0';
    copy_exc(str,string);
    len = len_b;
}
string_a::~string_a(){
    std::cout << "destruct-" << "\n";
    delete[]string;
}
void string_a::copy_exc(const char* str,char* dest){
    int len = strlen(str);
    for(int i = 0;i<len;i++){
         dest[i]=str[i];
    }
}

bool string_a::copy(const char* str,char* dest){
    int len = strlen(str);
    if(len<=strlen(dest))
    {
        for(int i = 0;i<len;i++){
            dest[i]=str[i];
        }
        return true;
    }
    return false;
}

bool string_a::copy(int start_s,int start_d,int end_s,const char* str,char* dest){
    int len = strlen(str);
    if(start_d = -1){
        start_d = len;
    }
    if(start_d+len<=strlen(dest)-end_s)
    {
        for(int i = 0;i<start_d-start_s;i++){
            dest[i+start_s]=str[end_s+i];
        }
        return true;
    }
    return false;
}
bool string_a::copy_exc(int start_s,int start_d,int end_s,const char* str,char* dest){
    int len = strlen(str);
    if(start_d = -1){
        start_d = len;
    }
        for(int i = 0;i<start_d-start_s;i++){
            dest[end_s+i]=str[i+start_s];
        }
        return true;
    return false;
}
// Operators
 string_a& string_a::operator=(const string_a& str){
            if(&str!=this){
            string = new char[strlen(str.string)];
            copy_exc(str.string,string);
            }
            return *this;
 }
  string_a& string_a::operator=(const char* str){
            string = new char[strlen(str)];
            copy_exc(str,string);
            return *this;
 }
 string_a& string_a::operator+(const string_a& str){
            int len_b = strlen(str.string);
            if(len_b!=-1){
                char buffer[len+len_b+1];
                buffer[len+len_b] = '\0';
                copy_exc(string,buffer);
                copy_exc(0,-1,len,str.string,buffer);
                delete[]string;
                string = new char[len+len_b+1];
                len = len+len_b;
                copy_exc(buffer,string);
                string[len+len_b]='\0';
                return *this;
            }else{
                throw("Incorrect string");
            }
 }
string_a& string_a::operator+(const char* str){
            int len_b = strlen(str);
            if(len_b!=-1){
                char buffer[len+len_b+1];
                buffer[len+len_b] = '\0';
                copy_exc(string,buffer);
                copy_exc(0,-1,len,str,buffer);
                delete[]string;
                string = new char[len+len_b+1];
                len = len+len_b;
                copy_exc(buffer,string);
                string[len+len_b]='\0';
                return *this;
            }else{
                throw("Incorrect string");
            }
        }
string_a& string_a::operator+(const int digit){
        char buffer[len+1];
        copy_exc(string,buffer);
        delete[]string;
        string = new char[len+1];
        len = len+1;
        copy_exc(buffer,string);
        string[len-1] = digit;
        string[len] = '\0';
        return *this; 
}
std::ostream& std_a::operator<< (std::ostream &out, const string_a& str){
    out << str.get_c();
    return out;
}

/**
 * @file calc.cpp
 * @author ITMOstudent (you@domain.com)
 * @brief Считает выражение, содержащее сложение и вычитание
 * @version 0.1
 * @date 2021-09-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
 #include <iostream>
#include <string>
#include <cmath> 

using namespace std;
 /**
  * @brief Проверяет, является ли символ цифрой
  * 
  * @param c 
  * @return true если символ c является цифрой
  * @return false если символ с не является цифрой
  */
bool isNumber(int c){
    if (c != ' ' && c != '+' && c != '-' && c != EOF && c!= '\r' && c!= '\n')
        return true;
    else
        return false;
}
    /// открывает файл fin.txt для прочтения мат выражением
    FILE* fin = fopen("fin.txt", "r");
    int c = 0;
    char operation = '+';
    string value;
    int result = 0; ///< результат после очередной операции
    int current = 0; ///< текущее введенное число
    bool inNum = false; ///< является ли последний считанный символ цифрой числа
    bool hasOperation = true; ///< прочли ли мы очередную операцию, defaul-true, так как первой операцией будет прибавление первого числа 
    
    /**
     * @brief читает выражение, до окончания символов
     * 
     */
    while((c = fgetc(fin)) != EOF){
        /**
         * собирает из прочитанных цифр строку
         */
        if (isNumber(c) == true){
            do{
                value.push_back(c);
                c = fgetc(fin);
            }while (isNumber(c) == true);
            inNum = true; /// маркер того, собрана ли строка из цифр
        }
        /**
         * преобразует строку из цифр в число current
         */
        if  (inNum == true) {
            for (int i = value.size() - 1; i >= 0; i--) {
                current = current + (value[value.size() - 1 - i] - '0') * pow(10, i);
            }
            value = "";
            inNum = false;
        }
        /**
         * обновляет result, при наличии операции и ненулевом current
         */
        if (hasOperation == true && current != 0){
            if (operation == '+'){
                result = result + current;
            }
            else if (operation == '-'){
                result = result - current;
            }
            current = 0;
            hasOperation = false;
        }
        /**
         * считывает операцию
         */
        if ((c == '+') || c == '-') {
            operation = c;
            hasOperation = true;
        }
    }
    cout << result;
    return 0;
}
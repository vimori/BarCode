#include <iostream>
#include <string>

using namespace std;

bool Check(string barcode) {
    int sum = 0;
    int length = barcode.length();

    for (int i = 0; i < length-1; ++i) {
        if (isdigit(barcode[i])){
        int digit = barcode[i] - '0';
        if ((i+1) % 2 == 0) {
            sum += digit *3; // Четные позиции
        } else {
            sum += digit; // нечетные позиции
        }
        } else{
            return false;
            }
    }

    int t = sum % 10;

    int controlDigit = barcode[length-1] - '0';

    return (sum + controlDigit) % 10 == 0;
}

void recover(string barcode) {
    int length = barcode.length();
    for (int i = 0; i < 10; ++i) { 
        string barcodeCopy = barcode;
        barcodeCopy.replace(barcodeCopy.find('?'), 1, to_string(i));

        if (Check(barcodeCopy)) {
            wcout << L"Восстановленный штрих-код: " ;
            cout << barcodeCopy << endl;
            return;
        } 
    }
    wcout << L"Невозможно востановить штрих-код " ;
}

int main() {
    setlocale(LC_ALL,"ru");
    string barcode;
    wcout << L"Введите штрих-код для проверки (например, 8590721001209): ";
    cin >> barcode;

    if (Check(barcode)) {
        wcout << L"Штрих-код верный." << endl;
    } else {
        wcout << L"Штрих-код неверный." << endl;
    }
    
    wcout << L"Введите штрих-код с пропущенной цифрой (например, 8590721?01209): ";
    cin >> barcode;
    recover(barcode);
    return 0;
}

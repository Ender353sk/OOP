#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Інтерфейс для роботи з цифрами
class IDigitProcessor {
public:
    virtual double getDigitPercentage() const = 0;
    virtual size_t getTotalCharacterCount() const = 0;
    virtual ~IDigitProcessor() = default;
};

// Клас-рядок
class StringElement {
private:
    string data;
public:
    StringElement(const string& str) : data(str) {}

    string getString() const {
        return data;
    }

    size_t length() const {
        return data.size();
    }

    bool hasDigits() const {
        return any_of(data.begin(), data.end(), ::isdigit);
    }

    size_t countDigits() const {
        return count_if(data.begin(), data.end(), ::isdigit);
    }
};

// Клас-контейнер
class TextContainer : public IDigitProcessor {
private:
    vector<StringElement> textElements;
public:
    void addString(const string& str) {
        textElements.emplace_back(str);
    }

    void removeString(const string& str) {
        textElements.erase(
            remove_if(textElements.begin(), textElements.end(),
                      [&str](const StringElement& elem) { return elem.getString() == str; }),
            textElements.end());
    }

    void clearText() {
        textElements.clear();
    }

    string getLargestString() const {
        if (textElements.empty()) return "";
        return max_element(textElements.begin(), textElements.end(),
                           [](const StringElement& a, const StringElement& b) {
                               return a.length() < b.length();
                           })->getString();
    }

    double getDigitPercentage() const override {
        size_t totalChars = getTotalCharacterCount();
        if (totalChars == 0) return 0.0;

        size_t digitCount = 0;
        for (const auto& elem : textElements) {
            digitCount += elem.countDigits();
        }

        return (static_cast<double>(digitCount) / totalChars) * 100.0;
    }

    size_t getTotalCharacterCount() const override {
        size_t totalChars = 0;
        for (const auto& elem : textElements) {
            totalChars += elem.length();
        }
        return totalChars;
    }

    void printText() const {
        for (const auto& elem : textElements) {
            cout << elem.getString() << endl;
        }
    }
};

// Тестування
int main() {
    TextContainer text;
    text.addString("Hello123");
    text.addString("Programming");
    text.addString("C++ is fun!");
    text.addString("2025");

    cout << "Збережений текст:" << endl;
    text.printText();
    
    cout << "\nНайбільший рядок: " << text.getLargestString() << endl;
    cout << "Відсоток цифр у тексті: " << text.getDigitPercentage() << "%" << endl;
    cout << "Загальна кількість символів: " << text.getTotalCharacterCount() << endl;

    text.removeString("2025");
    cout << "\nПісля видалення '2025':" << endl;
    text.printText();

    text.clearText();
    cout << "\nПісля очищення тексту:" << endl;
    text.printText();

    return 0;
}

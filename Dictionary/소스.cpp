#include<iostream>
#include<string>
#include<algorithm> //sort
using namespace std;

class Dictionary {
    string* words;
    int sizeof_words;

public:
    Dictionary();
    void input_word(string word);
    void print_all_words();
    void print_words_to_index(char index);
    void print_index(string word);
};

Dictionary::Dictionary() {
    words = NULL;
    sizeof_words = 0;
}

void Dictionary::input_word(string word) {
    if (words == NULL) {
        sizeof_words++;
        words = new string[1];
        words[0] = word;
    }
    else {
        sizeof_words++;
        string* tmp = words;
        words = new string[sizeof_words];
        for (int i = 0; i < sizeof_words - 1; i++) {
            words[i] = tmp[i];
        }
        words[sizeof_words - 1] = word;
        sort(words, words + sizeof_words); //sort(start, end) : Descending
    }
}

void Dictionary::print_all_words() {
    for (int i = 0; i < sizeof_words; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
}

void Dictionary::print_words_to_index(char index) {
    for (int i = 0; i < sizeof_words; i++) {
        if (words[i].c_str()[0] == index) //c_str() : string to char
        {
            cout << words[i] << " ";
        }
    }
    cout << endl;
}

void Dictionary::print_index(string word) {
    int identic_num = 0;
    for (int i = 0; i < sizeof_words; i++) {
        if (words[i] == word) {
            cout << i << " ";
            identic_num++;
        }
    }
    if (identic_num == 0) {
        cout << "NO WORD";
    }
    cout << endl;
}

int main() {
    Dictionary a = Dictionary();
    int n;
    string word, find_word;
    char first_word;
    
    cout << "������ ���� �ܾ��� ����: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "�Է¹��� �ܾ�" << i + 1 << ": ";
        cin >> word;
        a.input_word(word);
    }

    cout << "���� �ܾ�: ";
    a.print_all_words();

    cout << "����� �ܾ��� �� ����: ";
    cin >> first_word;
    a.print_words_to_index(first_word);

    cout << "ã�� �ε��� ��ȣ�� �ܾ�: ";
    cin >> find_word;
    a.print_index(find_word);
}
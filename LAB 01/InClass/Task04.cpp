#include <iostream>
using namespace std;

class Document {
    public:
        string text;

        Document(string& t) : text(t) {}

        ~Document() {
            cout << "Document destroyed" << endl;
        }

        Document(const Document& other) {
            text = other.text;
        }

        Document& operator=(const Document& other) {
            if (this != &other) {
                text = other.text;
            }
            return *this;
        }

};

int main() {
    string text = "Hello, World!";
    Document doc1(text);
    Document doc2 = doc1;
    Document doc3(text);
    doc3 = doc1;

    cout << "doc1: " << doc1.text << endl;
    cout << "doc2: " << doc2.text << endl;
    cout << "doc3: " << doc3.text << endl;

    return 0;
}
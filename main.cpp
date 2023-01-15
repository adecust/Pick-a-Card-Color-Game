#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class Base {


public:
    char d;

    enum result {
        kaybetmek = 0,
        beraberlik = 1,
        kazanmak = 2
    };

    virtual result compare(Base *a) = 0;
};

class Red : public Base {
public:

    Red() {
        d = 'R';

    }

    result compare(Base *a) {
        if (a->d == d) {
            return beraberlik;
        } else if (a->d == 'G') {
            return kazanmak;
        } else if (a->d == 'B') {
            return kaybetmek;
        } else {
            return kaybetmek;
        }
    }


};

class DarkRedd : public Red {
public:

    DarkRedd() {
        d = 'D';
    }

    result compare(Base *a) {
        if (a->d == d) {
            return beraberlik;
        } else if (a->d == 'R') {
            return kazanmak;
        } else if (a->d == 'B') {
            return kazanmak;
        } else {
            return kaybetmek;
        }

    }


};

class Green : public Base {
public:

    Green() {
        d = 'G';
    }

    result compare(Base *a) {
        if (a->d == d) {
            return beraberlik;
        } else if (a->d == 'D') {
            return kazanmak;
        } else if (a->d == 'B') {
            return kazanmak;
        } else {
            return kaybetmek;
        }

    }
};

class Blue : public Base {
public:

    Blue() {
        d = 'B';
    }

    result compare(Base *a) {


        if (a->d == d) {
            return beraberlik;
        } else if (a->d == 'R') {

            return kazanmak;
        } else if (a->d == 'D') {
            return kaybetmek;
        } else {
            return kaybetmek;
        }
    }

};

void display(map<int, Base *> &test, map<int, Base *> &test2,ifstream &dosyaOku) {
    int oyuncu1[3]={0,0,0};// {kazanma,beraberlik,kaybetme}
    int oyuncu2[3]={0,0,0};
    int i=1;

    char kar;
    int a = 0;
    Base *b;
    cout << "Oyuncu 1 : ";
    while (dosyaOku.get(kar)) {

        if (kar == 'R') {
            a++;
            b = new Red();
            test.insert(pair<int, Base *>(a, b));
        } else if (kar == 'B') {
            a++;
            b = new Blue();
            test.insert(pair<int, Base *>(a, b));
        } else if (kar == 'D') {
            a++;
            b = new DarkRedd();
            test.insert(pair<int, Base *>(a, b));

        } else if (kar == 'G') {
            a++;
            b = new Green();
            test.insert(pair<int, Base *>(a, b));
        } else if (kar == '\n') {
            break;
        }


        cout << kar ;
    }
    a = 0;
    cout << "\n";
    cout << "Oyuncu 2 : ";
    while (dosyaOku.get(kar)) {
        if (kar == 'R') {
            a++;
            b = new Red();
            test2.insert(pair<int, Base *>(a, b));

        } else if (kar == 'B') {
            a++;
            b = new Blue();
            test2.insert(pair<int, Base *>(a, b));
        } else if (kar == 'D') {
            a++;
            b = new DarkRedd();
            test2.insert(pair<int, Base *>(a, b));

        } else if (kar == 'G') {
            a++;
            b = new Green();
            test2.insert(pair<int, Base *>(a, b));
        } else if (kar == '\n') {
            break;
        }
        cout << kar;
    }
    cout << "\n";
    cout << "\n";

    cout << "Puan 1: ";
    for (i = 1; i <= a; i++) {
       cout << test[i]->compare(test2[i])<<" ";
       if(test[i]->compare(test2[i])==2){
           oyuncu1[0]++;
       }
       else if(test[i]->compare(test2[i])==1){
           oyuncu1[1]++;
       }
       else{
           oyuncu1[2]++;
       }
    }
    cout << "\n";
    cout << "Puan 2: ";
    for (i = 1; i <= a; i++) {

        cout << test2[i]->compare(test[i])<<" ";
        if(test2[i]->compare(test[i])==2){
            oyuncu2[0]++;
        }
        else if(test2[i]->compare(test[i])==1){
            oyuncu2[1]++;
        }
        else{
            oyuncu2[2]++;
        }
    }
    cout << "\n";
    cout << "\n";

    int oyuncu1puan=oyuncu1[0]*2+oyuncu1[1]*1+oyuncu1[2]*0;
    int oyuncu2puan=oyuncu2[0]*2+oyuncu2[1]*1+oyuncu2[2]*0;
    cout<<"1. Oyuncunun puani : "<<oyuncu1puan<<endl;
    cout<<"2. Oyuncunun puani : "<<oyuncu2puan<<endl;
    cout << "\n";
    if(oyuncu1puan>oyuncu2puan){
        cout<<"Kazanan 1.Oyuncu"<<endl;
    }
    else if(oyuncu1puan==oyuncu2puan){
        cout<<"Berabere"<<endl;
    }
    else{
        cout<<"Kazanan 2.Oyuncu"<<endl;
    }


dosyaOku.close();
}

int main() {
    ifstream dosyaOku("../Kartlar.txt");
    map<int, Base *> test;
    map<int, Base *> test2;
    display(test, test2,dosyaOku);




    return 0;
}

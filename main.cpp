#include <iostream>
#include <string>

using namespace std;

class Klient {
private:
    string imie;
    string nazwisko;
    string email;

public:
    Klient(const string& imie, const string& nazwisko, const string& email)
        : imie(imie), nazwisko(nazwisko), email(email) {}

    string getImie() const { return imie; }
    string getNazwisko() const { return nazwisko; }
    string getEmail() const { return email; }
};

class Spektakl {
private:
    string tytul;
    string data;
    string godzina;
    float cena;

public:
    Spektakl(const string& tytul, const string& data, const string& godzina, float cena)
        : tytul(tytul), data(data), godzina(godzina), cena(cena) {}

    string getTytul() const { return tytul; }
    string getData() const { return data; }
    string getGodzina() const { return godzina; }
    float getCena() const { return cena; }
};

class Bilet {
public:
    virtual float obliczCene() = 0;
    virtual string getNumerBiletu() const = 0;
    virtual string getPrzypisaneMiejsce() const = 0;
};

class BiletNormalny : public Bilet {
private:
    string numerBiletu;
    string przypisaneMiejsce;

public:
    BiletNormalny(const string& numerBiletu, const string& przypisaneMiejsce)
        : numerBiletu(numerBiletu), przypisaneMiejsce(przypisaneMiejsce) {}

    float obliczCene() override {
        return 50.00;
    }

    string getNumerBiletu() const override { return numerBiletu; }
    string getPrzypisaneMiejsce() const override { return przypisaneMiejsce; }
};

class BiletUlgowy : public Bilet {
private:
    string numerBiletu;
    string przypisaneMiejsce;

public:
    BiletUlgowy(const string& numerBiletu, const string& przypisaneMiejsce)
        : numerBiletu(numerBiletu), przypisaneMiejsce(przypisaneMiejsce) {}

    float obliczCene() override {
        return 40.00;
    }

    string getNumerBiletu() const override { return numerBiletu; }
    string getPrzypisaneMiejsce() const override { return przypisaneMiejsce; }
};

class Rezerwacja {
private:
    string dataRezerwacji;
    Bilet** bilety;
    int przypisaneBilety;

public:
    Rezerwacja(const string& dataRezerwacji)
        : dataRezerwacji(dataRezerwacji), bilety(new Bilet*[10]), przypisaneBilety(0) {}

    ~Rezerwacja() {
        for (int i = 0; i < przypisaneBilety; i++) {
            delete bilety[i];
        }
        delete[] bilety;
    }

    void dodajBilet(Bilet* bilet) {
        bilety[przypisaneBilety++] = bilet;
    }

    void wyswietlBilety() {
        for (int i = 0; i < przypisaneBilety; i++) {
            Bilet* bilet = bilety[i];
            cout << "Bilet " << i + 1 << ": ";
            cout << "Numer: " << bilet->getNumerBiletu() << ", ";
            cout << "Miejsce: " << bilet->getPrzypisaneMiejsce() << ", ";
            cout << "Cena: " << bilet->obliczCene() << endl;
        }
    }
};

class Faktura {
private:
    int numerFaktury;
    Klient DaneKlienta;
    Rezerwacja DaneRezerwacji;

public:
    Faktura(int numerFaktury, const Klient& DaneKlienta, const Rezerwacja& DaneRezerwacji)
        : numerFaktury(numerFaktury), DaneKlienta(DaneKlienta), DaneRezerwacji(DaneRezerwacji) {}

    void wyswietlDaneFaktury() {
        cout << "Numer faktury: " << numerFaktury << endl;
        cout << "Dane Klienta: " << DaneKlienta.getImie() << " " << DaneKlienta.getNazwisko() << " (" << DaneKlienta.getEmail() << ")" << endl;
        cout << "Bilety: " << endl;
        DaneRezerwacji.wyswietlBilety();
    }
};

class SystemRezerwacji {
public:
    void wyszukajSpektakle() {
         //----------------
    }

    void rezerwujBilety() {
        //----------------
    }
};

int main() {
    Klient DaneKlienta("Jan", "Kowalski", "jan.kowalski@example.com");
    Spektakl spektakl("Przyk³adowy spektakl", "2023-07-05", "18:00", 100.0);

    Bilet* biletNormalny = new BiletNormalny("N1234", "A1");
    Bilet* biletUlgowy = new BiletUlgowy("U5678", "B2");

    Rezerwacja DaneRezerwacji("2023-07-02");
    DaneRezerwacji.dodajBilet(biletNormalny);
    DaneRezerwacji.dodajBilet(biletUlgowy);

    Faktura faktura(1, DaneKlienta, DaneRezerwacji);

    SystemRezerwacji systemRezerwacji;
    systemRezerwacji.wyszukajSpektakle();
    systemRezerwacji.rezerwujBilety();

    faktura.wyswietlDaneFaktury();

    delete biletNormalny;
    delete biletUlgowy;

    return 0;
}

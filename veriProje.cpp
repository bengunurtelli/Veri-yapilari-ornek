#include <iostream>
using namespace std;

class Dugum {
public:
    int veri;
    Dugum* pSonraki;
    Dugum(int veri) {
        this->veri = veri;
        this->pSonraki = NULL;
    }
};

class Yigin {
private:
    Dugum* tepe;
    int elemanSayisi;
public:
    Yigin() {
        tepe = NULL;
        elemanSayisi = 0;
    }
    void ekle(int veri) {
        Dugum* yeni = new Dugum(veri);
        yeni->pSonraki = tepe;
        tepe = yeni;
        elemanSayisi++;
    }
    void cikar() {
        if (tepe == NULL) {
            cout << "Yigin bos!" << endl;
            return;
        }
        Dugum* silinecek = tepe;
        tepe = tepe->pSonraki;
        delete silinecek;
        elemanSayisi--;
    }
    void temizle() {
        while (tepe != NULL) {
            cikar();
        }
    }
    void yazdir() {
        Dugum* temp = tepe;
        if (temp == NULL) {
            cout << "Yigin bos!" << endl;
            return;
        }
        else {
            cout << "Yigin elemanlari: ";
            while (temp != NULL) {
                cout << temp->veri << " ";
                temp = temp->pSonraki;
            }
        }
    }
    int sayi() {
        return elemanSayisi;
    }
};

class Kuyruk {
private:
    Dugum* on;
    Dugum* arka;
    int elemanSayisi;
public:
    Kuyruk() {
        on = arka = NULL;
        elemanSayisi = 0;
    }
    void ekle(int veri) {
        Dugum* yeni = new Dugum(veri);
        if (arka == NULL) {
            on = arka = yeni;
        }
        else {
            arka->pSonraki = yeni;
            arka = yeni;
        }
        elemanSayisi++;
    }
    void cikar() {
        if (on == NULL) {
            cout << "Kuyruk bos!" << endl;
            return;
        }
        Dugum* silinecek = on;
        on = on->pSonraki;
        if (on == NULL) arka = NULL;
        delete silinecek;
        elemanSayisi--;
    }
    void temizle() {
        while (on != NULL) {
            cikar();
        }
    }
    void yazdir() {
        Dugum* temp = on;
        if (temp == NULL) {
            cout << "Kuyruk bos!" << endl;
            return;
        }
        else {
            cout << "Kuyruk elemanlari: ";
            while (temp != NULL) {
                cout << temp->veri << " ";
                temp = temp->pSonraki;
            }
        }
        cout << endl;
    }
    int sayi() {
        return elemanSayisi;
    }
};

class BagliListe {
private:
    Dugum* bas;
    int elemanSayisi;
public:
    BagliListe() {
        bas = NULL;
        elemanSayisi = 0;
    }
    void arayaEkle(int index, int veri) {
        Dugum* yeni = new Dugum(veri);
        if (index <= 0 || bas == NULL) {
            yeni->pSonraki = bas;
            bas = yeni;
        }
        else {
            Dugum* temp = bas;
            for (int i = 0; i < index - 1 && temp->pSonraki != NULL; i++)
                temp = temp->pSonraki;
            yeni->pSonraki = temp->pSonraki;
            temp->pSonraki = yeni;
        }
        elemanSayisi++;
    }
    void sonaEkle(int veri) {
        Dugum* yeni = new Dugum(veri);
        if (bas == NULL) {
            bas = yeni;
        }
        else {
            Dugum* temp = bas;
            while (temp->pSonraki != NULL)
                temp = temp->pSonraki;
            temp->pSonraki = yeni;
        }
        elemanSayisi++;
    }
    void aradanCikar(int index) {
        if (bas == NULL || index < 0) {
            cout << "Liste bos!" << " ";
        }
        else if (index == 0) {
            Dugum* sil = bas;
            bas = bas->pSonraki;
            delete sil;
        }
        else {
            Dugum* temp = bas;
            for (int i = 0; i < index - 1 && temp->pSonraki != NULL; i++)
                temp = temp->pSonraki;
            if (temp->pSonraki != NULL) {
                Dugum* sil = temp->pSonraki;
                temp->pSonraki = sil->pSonraki;
                delete sil;
            }
        }
        elemanSayisi--;
    }
    void sondanCikar() {
        if (bas == NULL) {
            cout << "Liste bos!" << " ";
        }
        else if (bas->pSonraki == NULL) {
            delete bas;
            bas = NULL;
        }
        else {
            Dugum* temp = bas;
            Dugum* once = bas;
            while (temp->pSonraki != NULL) {
                once = temp;
                temp = temp->pSonraki;
            }
            delete temp;
            once->pSonraki = NULL;
        }
        elemanSayisi--;
    }
    void temizle() {
        while (bas != NULL) {
            Dugum* sil = bas;
            bas = bas->pSonraki;
            delete sil;
        }
        elemanSayisi = 0;
    }
    void yazdir() {
        Dugum* temp = bas;
        while (temp != NULL) {
            cout << temp->veri << " ";
            temp = temp->pSonraki;
        }
        cout << endl;
    }
    int sayi() {
        return elemanSayisi;
    }
};

class IkiliAgac {
private:
    class Dugum {
    public:
        int veri;
        Dugum* sol;
        Dugum* sag;
        Dugum(int v) {
            veri = v;
            sol = NULL;
            sag = NULL;
        }
    };

    Dugum* kok;

    Dugum* elemanEkle(Dugum* root, int veri) {
        if (root == NULL)
            return new Dugum(veri);
        else if (veri < root->veri)
            root->sol = elemanEkle(root->sol, veri);
        else if (veri > root->veri)
            root->sag = elemanEkle(root->sag, veri);
        return root;
    }

    Dugum* enKucukBul(Dugum* root) {
        while (root && root->sol != NULL)
            root = root->sol;
        return root;
    }

    Dugum* elemanSil(Dugum* root, int veri) {
        if (root == NULL) return root;
        if (veri < root->veri)
            root->sol = elemanSil(root->sol, veri);
        else if (veri > root->veri)
            root->sag = elemanSil(root->sag, veri);
        else {
            if (root->sol == NULL) {
                Dugum* temp = root->sag;
                delete root;
                return temp;
            }
            else if (root->sag == NULL) {
                Dugum* temp = root->sol;
                delete root;
                return temp;
            }
            Dugum* temp = enKucukBul(root->sag);
            root->veri = temp->veri;
            root->sag = elemanSil(root->sag, temp->veri);
        }
        return root;
    }

    void temizle(Dugum* root) {
        if (root == NULL) return;
        temizle(root->sol);
        temizle(root->sag);
        delete root;
    }

    int elemanSayisi(Dugum* root) {
        if (root == NULL) return 0;
        return 1 + elemanSayisi(root->sol) + elemanSayisi(root->sag);
    }

    void inorder(Dugum* root) {
        if (root == NULL) return;
        inorder(root->sol);
        cout << root->veri << " ";
        inorder(root->sag);
    }

    void preorder(Dugum* root) {
        if (root == NULL) return;
        cout << root->veri << " ";
        preorder(root->sol);
        preorder(root->sag);
    }

    void postorder(Dugum* root) {
        if (root == NULL) return;
        postorder(root->sol);
        postorder(root->sag);
        cout << root->veri << " ";
    }

public:
    IkiliAgac() : kok(NULL) {}

    void ekle(int veri) {
        kok = elemanEkle(kok, veri);
    }

    void sil(int veri) {
        kok = elemanSil(kok, veri);
    }

    void temizle() {
        temizle(kok);
        kok = NULL;
    }

    int sayi() {
        return elemanSayisi(kok);
    }

    void inorder() {
        inorder(kok);
        cout << endl;
    }

    void preorder() {
        preorder(kok);
        cout << endl;
    }

    void postorder() {
        postorder(kok);
        cout << endl;
    }
};


void yiginMenusu(Yigin& y) {
    int secim, veri;
    do {

        cout << "\nYigin icin islem seciniz:\n" << endl;
        cout << "1- Yigina eleman ekle\n2- Yigindan eleman cikar\n3- Yigini temizle\n4- Yigindaki elemanlari goster\n5- Yigindaki eleman sayisini goster\n6- Ana menuye geri don\nSecim: ";
        cin >> secim;
        switch (secim) {
        case 1:
            cout << "Eklenecek veri: "; cin >> veri;
            y.ekle(veri); break;
        case 2:
            y.cikar(); break;
        case 3:
            y.temizle(); break;
        case 4:
            y.yazdir(); break;
        case 5:
            cout << "Eleman sayisi: " << y.sayi() << endl; break;
        case 6:
            cout << "Ana menuye donuluyor..." << endl; break;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    } while (secim != 6);
}

void kuyrukMenusu(Kuyruk& k) {
    int secim, veri;
    do {
        cout << "\nKuyruk icin islem seciniz:" << endl;
        cout << "1- Kuyruga eleman ekle\n2- Kuyruktan eleman cikar\n3- Kuyrugu temizle\n4- Kuyruktaki elemanlari goster\n5- Kuyruktaki eleman sayisini goster\n6- Ana menuye geri don\nSecim: ";
        cin >> secim;
        switch (secim) {
        case 1:
            cout << "Eklenecek veri: "; cin >> veri;
            k.ekle(veri); break;
        case 2:
            k.cikar(); break;
        case 3:
            k.temizle(); break;
        case 4:
            k.yazdir(); break;
        case 5:
            cout << "Eleman sayisi: " << k.sayi() << endl; break;
        case 6:
            cout << "Ana menuye donuluyor..." << endl; break;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    } while (secim != 6);
}

void bagliListeMenusu(BagliListe& l) {
    int secim, altSecim, veri, index;
    do {
        cout << "\nBagli Liste icin islem seciniz:" << endl;
        cout << "1- Listeye eleman ekle\n2- Listeden eleman cikar\n3- Listeyi temizle\n4- Listedeki elemanlari goster\n5- Listedeki eleman sayisini goster\n6- Ana menuye geri don\nSecim: ";
        cin >> secim;
        switch (secim) {
        case 1:
            cout << "Ekleme turunu seciniz:\n1- Araya eleman ekle\n2- Sona eleman ekle\n3- Liste islemlerine geri don\nSecim: ";
            cin >> altSecim;
            if (altSecim == 1) {
                cout << "Index giriniz: "; cin >> index;
                cout << "Eklenecek veri: "; cin >> veri;
                l.arayaEkle(index, veri);
            }
            else if (altSecim == 2) {
                cout << "Eklenecek veri: "; cin >> veri;
                l.sonaEkle(veri);
            }
            break;
        case 2:
            cout << "Cikarma turunu seciniz:\n1- Aradan eleman cikar\n2- Sondan eleman cikar\n3- Liste islemlerine geri don\nSecim: ";
            cin >> altSecim;
            if (altSecim == 1) {
                cout << "Index giriniz: "; cin >> index;
                l.aradanCikar(index);
            }
            else if (altSecim == 2) {
                l.sondanCikar();
            }
            break;
        case 3:
            l.temizle(); break;
        case 4:
            l.yazdir(); break;
        case 5:
            cout << "Eleman sayisi: " << l.sayi() << endl; break;
        case 6:
            cout << "Ana menuye donuluyor..." << endl; break;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    } while (secim != 6);
}
void ikiliAgacMenusu(IkiliAgac& agac) {
    int secim, veri;
    do {
        cout << "\nIkili Agac icin islem seciniz:" << endl;
        cout << "1- Agaca Eleman Ekle\n2- Agactan Eleman sil\n3- Agaci Temizle\n4- Agactaki Eleman Sayisini goster\n5- Agaci InOrder dolasarak Elemanlari Goster\n6- Agaci PreOrder dolasarak Elemanlari Goster\n7- Agaci PostOrder dolasarak Elemanlari Goster\n8- Ana menuye geri don\nSecim: ";
        cin >> secim;

        switch (secim) {
        case 1:
            cout << "Eklenecek veri: "; cin >> veri;
            agac.ekle(veri);
            break;
        case 2:
            cout << "Silinecek veri: "; cin >> veri;
            agac.sil(veri);
            break;
        case 3:
            agac.temizle();
            cout << "Agac temizlendi." << endl;
            break;
        case 4:
            cout << "Eleman sayisi: " << agac.sayi() << endl;
            break;
        case 5:
            cout << "InOrder siralamasi: ";
            agac.inorder();
            break;
        case 6:
            cout << "PreOrder siralamasi: ";
            agac.preorder();
            break;
        case 7:
            cout << "PostOrder siralamasi: ";
            agac.postorder();
            break;
        case 8:
            cout << "Ana menuye donuluyor..." << endl;
            break;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    } while (secim != 8);
}



int main()
{
    Yigin y;
    Kuyruk k;
    BagliListe l;
    IkiliAgac agac;
    int secim;
    do {

        cout << "\nYapmak istediginiz uygulamayi seciniz:" << endl;
        cout << "1- Yigin Uygulamasi\n2- Kuyruk Uygulamasi\n3- Tek Yonlu Bagli Liste Uygulamasi\n4- Ikili Agac Uygulamasi\n5- Programdan Cikis\nSecim: ";
        cin >> secim;
        switch (secim) {
        case 1:
            yiginMenusu(y); break;
        case 2:
            kuyrukMenusu(k); break;
        case 3:
            bagliListeMenusu(l); break;
        case 4:
            ikiliAgacMenusu(agac); break;
        case 5:
            cout << "Programdan cikiliyor..." << endl; break;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    } while (secim != 5);

    return 0;

}
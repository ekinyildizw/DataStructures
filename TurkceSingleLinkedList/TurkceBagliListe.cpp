#include <iostream>
using namespace std;
// Baðlý listedeki bir düðüm için yapý
struct Dugum{
    int veri;
    Dugum* isaretci;
};
// Baðlý liste class'ýný tanýmlayýn
class BagliListe{
    // Listedeki ilk düðüme iþaretçi
    Dugum* kafa;
    
public:
    // Kurucu head'i NULL olarak baþlatýr
    BagliListe() : kafa(NULL) {}
    
    // Listenin baþýna yeni bir düðüm(Node) ekleme iþlevi
    void basinaEkle(int deger)
    {
        Dugum* yeniDugum = new Dugum();
        yeniDugum->veri = deger;
        yeniDugum->isaretci = kafa;
        kafa = yeniDugum;
    }
    
    // Fonksiyon Listenin sonuna yeni bir düðüm ekleyin
    void sonunaEkle(int deger)
    {
        Dugum* yeniDugum = new Dugum();
        yeniDugum->veri = deger;
        yeniDugum->isaretci = NULL;
        // Liste boþsa, baþý yeni düðüme güncelle
        if(!kafa)
        {
            kafa = yeniDugum;
            return;
        }
         // Son düðüme geçiþ yap
        Dugum* gecici = kafa;
        while(gecici->isaretci)
        {
            gecici = gecici->isaretci;
        }
        // Son düðümün yanýndaki düðümü yeni düðüme güncelle
        gecici->isaretci = yeniDugum;
    }
    
    // Fonksiyon, Listeye belirli bir pozisyonda yeni bir düðüm ekler
    void pozisyonaEkle(int deger, int pozisyon)
    {
        if (pozisyon < 1)
        {
            cout << "Pozisyon 1'den büyük olmalý!"<<endl;
            return;
        }
        if (pozisyon == 1)
        {
            basinaEkle(deger);
            return;
        }
        
        Dugum* yeniDugum = new Dugum();
        yeniDugum->veri = deger;
        // Ýstenen konumdan önceki düðüme geçiþ
        Dugum* gecici = kafa;
        for (int i = 1; i < pozisyon - 1 && gecici;++i)
        {
            gecici = gecici->isaretci;
        }
        // Konum aralýk dýþýndaysa, bir hata mesajý yazdýr
        if(!gecici)
        {
            cout << "Pozisyon listeyi boyutunu aþtý." << endl;
            delete yeniDugum;
            return;
        }
        // Yeni düðümü istenen konuma ekleyin
        yeniDugum->isaretci = gecici->isaretci;
        gecici->isaretci = yeniDugum;
    }
    
    // Fonksiyon, Listenin baþýndaki ilk düðümü siler
    void bastanSil()
    {
        if(!kafa)
        {
            cout << "Liste boþtur" << endl;
            return;
        }
        
        Dugum* gecici = kafa;
        kafa = kafa->isaretci;
        delete gecici;
    }
    
    // Fonksiyon, Listenin sonundaki düðümü siler
    void sondanSil()
    {
        if(!kafa)
        {
        cout << "Liste boþtur." << endl;
        return;    
        }
        if(!kafa->isaretci)

        {
            delete kafa;
            kafa = NULL;
            return;
        }
        // Sondan ikinci düðüme geç
        Dugum* gecici = kafa;
        while(gecici->isaretci->isaretci)
        {
            gecici = gecici->isaretci;
        }
        // Son düðümü sil
        delete gecici->isaretci;
        // Sondan ikinci düðümün sýrasýný NULL olarak ayarla
        gecici->isaretci=NULL;
    }
    
    // Fonksiyon, Belirli bir pozisyondaki düðümü siler
    void pozisyondanSil(int pozisyon)
    {
        if(pozisyon < 1)
        {
        cout<<"Pozisyon 1 den büyük olmalý."<<endl;
        return;    
        }
        if(pozisyon == 1){
            bastanSil();
            return;
        }
        
        Dugum* gecici = kafa;
        for(int i=1;i<pozisyon-1 && gecici; i++){
            gecici = gecici->isaretci;
        }
        
        if(!gecici){
            cout << "Liste boþ!"<< endl;
            return;
        }
        // Silinecek düðümü kaydedin
        Dugum* dugumSil = gecici->isaretci;
        // Sonraki iþaretçiyi güncelle
        gecici->isaretci = gecici->isaretci->isaretci;
        // Düðümü sil
        delete gecici->isaretci;
    }
        
    // Fonksiyon, Listenin tüm elemanlarýný ekrana yazdýrýr
    void display()
    {
        if(!kafa)
        {
        cout << "Liste boþtur." << endl;
        return;    
        }
        
        Dugum* gecici = kafa;
        while(gecici)
        {
            cout << gecici->veri << " -> "; 
            gecici = gecici->isaretci;
        }
        cout << "NULL" << endl;
    }
};
    
int main(){
    setlocale(LC_ALL, "Turkish"); 
    BagliListe liste1; // Yeni bir baðlý liste baþlatýn
    liste1.basinaEkle(33);
    liste1.basinaEkle(31);
    liste1.sonunaEkle(32);
    liste1.sonunaEkle(11);
    liste1.sondanSil();
    liste1.display();
    return 0;
}


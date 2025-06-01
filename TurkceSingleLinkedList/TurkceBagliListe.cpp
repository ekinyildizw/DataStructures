#include <iostream>
using namespace std;
// Ba�l� listedeki bir d���m i�in yap�
struct Dugum{
    int veri;
    Dugum* isaretci;
};
// Ba�l� liste class'�n� tan�mlay�n
class BagliListe{
    // Listedeki ilk d���me i�aret�i
    Dugum* kafa;
    
public:
    // Kurucu head'i NULL olarak ba�lat�r
    BagliListe() : kafa(NULL) {}
    
    // Listenin ba��na yeni bir d���m(Node) ekleme i�levi
    void basinaEkle(int deger)
    {
        Dugum* yeniDugum = new Dugum();
        yeniDugum->veri = deger;
        yeniDugum->isaretci = kafa;
        kafa = yeniDugum;
    }
    
    // Fonksiyon Listenin sonuna yeni bir d���m ekleyin
    void sonunaEkle(int deger)
    {
        Dugum* yeniDugum = new Dugum();
        yeniDugum->veri = deger;
        yeniDugum->isaretci = NULL;
        // Liste bo�sa, ba�� yeni d���me g�ncelle
        if(!kafa)
        {
            kafa = yeniDugum;
            return;
        }
         // Son d���me ge�i� yap
        Dugum* gecici = kafa;
        while(gecici->isaretci)
        {
            gecici = gecici->isaretci;
        }
        // Son d���m�n yan�ndaki d���m� yeni d���me g�ncelle
        gecici->isaretci = yeniDugum;
    }
    
    // Fonksiyon, Listeye belirli bir pozisyonda yeni bir d���m ekler
    void pozisyonaEkle(int deger, int pozisyon)
    {
        if (pozisyon < 1)
        {
            cout << "Pozisyon 1'den b�y�k olmal�!"<<endl;
            return;
        }
        if (pozisyon == 1)
        {
            basinaEkle(deger);
            return;
        }
        
        Dugum* yeniDugum = new Dugum();
        yeniDugum->veri = deger;
        // �stenen konumdan �nceki d���me ge�i�
        Dugum* gecici = kafa;
        for (int i = 1; i < pozisyon - 1 && gecici;++i)
        {
            gecici = gecici->isaretci;
        }
        // Konum aral�k d���ndaysa, bir hata mesaj� yazd�r
        if(!gecici)
        {
            cout << "Pozisyon listeyi boyutunu a�t�." << endl;
            delete yeniDugum;
            return;
        }
        // Yeni d���m� istenen konuma ekleyin
        yeniDugum->isaretci = gecici->isaretci;
        gecici->isaretci = yeniDugum;
    }
    
    // Fonksiyon, Listenin ba��ndaki ilk d���m� siler
    void bastanSil()
    {
        if(!kafa)
        {
            cout << "Liste bo�tur" << endl;
            return;
        }
        
        Dugum* gecici = kafa;
        kafa = kafa->isaretci;
        delete gecici;
    }
    
    // Fonksiyon, Listenin sonundaki d���m� siler
    void sondanSil()
    {
        if(!kafa)
        {
        cout << "Liste bo�tur." << endl;
        return;    
        }
        if(!kafa->isaretci)

        {
            delete kafa;
            kafa = NULL;
            return;
        }
        // Sondan ikinci d���me ge�
        Dugum* gecici = kafa;
        while(gecici->isaretci->isaretci)
        {
            gecici = gecici->isaretci;
        }
        // Son d���m� sil
        delete gecici->isaretci;
        // Sondan ikinci d���m�n s�ras�n� NULL olarak ayarla
        gecici->isaretci=NULL;
    }
    
    // Fonksiyon, Belirli bir pozisyondaki d���m� siler
    void pozisyondanSil(int pozisyon)
    {
        if(pozisyon < 1)
        {
        cout<<"Pozisyon 1 den b�y�k olmal�."<<endl;
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
            cout << "Liste bo�!"<< endl;
            return;
        }
        // Silinecek d���m� kaydedin
        Dugum* dugumSil = gecici->isaretci;
        // Sonraki i�aret�iyi g�ncelle
        gecici->isaretci = gecici->isaretci->isaretci;
        // D���m� sil
        delete gecici->isaretci;
    }
        
    // Fonksiyon, Listenin t�m elemanlar�n� ekrana yazd�r�r
    void display()
    {
        if(!kafa)
        {
        cout << "Liste bo�tur." << endl;
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
    BagliListe liste1; // Yeni bir ba�l� liste ba�lat�n
    liste1.basinaEkle(33);
    liste1.basinaEkle(31);
    liste1.sonunaEkle(32);
    liste1.sonunaEkle(11);
    liste1.sondanSil();
    liste1.display();
    return 0;
}


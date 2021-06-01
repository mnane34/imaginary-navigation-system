
#include "Nokta.h" // Class ve Fonk. kullanmak için Gerekli Kütüphane Dahil Edildi.
#include <iostream> // C++ Kütüphanesi dahil edildi. 
#include <stdlib.h> // Srand() Fonksiyonu için Gerekli Kütüphane Dahil Edildi.
#include <windows.h> // Sleep ve gotoxy Fonksiyonu için Gerekli Kütüphane Dahil Edildi.
#include <conio.h> // getch() Fonksiyonu için Gerekli Kütüphane Dahil Edildi.
#include <locale.h> // Konsol Ekranýný türkçe yapmak için Gerekli Kütüphane Dahil Edildi.
#include <math.h> // Pow() ve Sqrt() Fonksiyonlarý için Gerekli Kütüphane Dahil Edildi.

using namespace std; // Std Fonksiyonlarý Çaðrýldý

/* Konsol Ekranýnda istenilen Noktaya Kursoru Götürmek için Kullanýlan Fonksiyon*/
void gotoxy(unsigned long int x, unsigned long int y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


/* Noktadan Noktaya Giderken Alýnan Yollara "." Ýþareti Býrakan Fonksiyon*/

int NoktaLine(int ilk_X1 ,int ilk_Y1 , int son_X1 ,int son_Y1) // 4 Parametreli Ýnteger Deðer Döndüren Fonksiyon
{
		
	 if((ilk_X1 - son_X1) == 0 && (ilk_Y1 - son_Y1)>0) // Dikey Yukarý
	{ 
	   while(!(ilk_Y1 == son_Y1)) // Y Deðerleri Eþit Oluncaya Kadar Çalýþ
        {           
            gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et
			ilk_Y1--; // Y Deðerini Bir Azalt
            cout<<"."; // Ekrana Nokta Ýþareti Bas
            if(ilk_Y1 == son_Y1) // Y Deðerleri Eþit Ýse
			{
			 return 0;	// Döngüyü Bitir.
			} 
			}	  	   	
	}
	
	
	else if((ilk_X1 - son_X1) == 0 && (ilk_Y1 - son_Y1)<0) // Dikey Aþþaðý
	{      
	   while(!(ilk_Y1 == son_Y1)) // Y Deðerleri Eþit Olmayana Kadar Çalýþ
        {
            gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et
			ilk_Y1++; // Y Deðerini bir Arttýr
            cout<<"."; // Ekrana Nokta Ýþareti Bas
            if(ilk_Y1 == son_Y1) // Y Deðerleri Eþit Ýse
			{
            return 0; // Döngüyü Bitir.	
			} 
			}	  	    	
	}
	
	
	else if((ilk_X1 - son_X1)<0 && (ilk_Y1 - son_Y1) == 0) // Yatay Saða
	{   
	   while(!(ilk_X1 == son_X1)) // X Deðerleri Eþit Oluncaya Kadar Çalýþ
        {       
            gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et 
			ilk_X1++; // X Deðerini Bir Arttýr
            cout<<"."; // Ekrana Nokta Ýþareti Bas
            if(ilk_X1 == son_X1) // X Deðerleri Eþit Ýse
			{
			return 0; // Döngüyü Bitir 
			}
			}	  		
	}
	
	
	
	
    else if((ilk_X1 - son_X1)>0 && (ilk_Y1 - son_Y1) == 0) // Yatay Sola
	{   
	   while(!(ilk_X1 == son_X1)) // X Deðerleri Eþit Oluncaya Kadar Çalýþ
        {
            gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et
			ilk_X1--; // X Deðerini Bir Azalt
            cout<<"."; // Ekrana Nokta Ýþareti Bas
            if(ilk_X1 == son_X1) // X Deðerleri Eþit Ýse
			{
            return 0; // Döngüyü Bitir	
			} 
		}	  		
	} 
	
	
		
    else if((ilk_X1 - son_X1)<0 && (ilk_Y1 - son_Y1)<0) // Sað Aþþaðý Çapraz 
    {
        while(!(ilk_X1 == son_X1 && ilk_Y1 == son_Y1)) // Ýki Noktanýn Deðeri Birbirine Eþit Oluncaya Kadar Çalýþ
        {
			while(ilk_X1==son_X1) // Eðer X'ler Eþitse Çalýþ
			{ 
            gotoxy(ilk_X1,ilk_Y1); // Girilen Noktaya Haraket Et
            ilk_Y1++; // Y Deðerini bir Arttýr
            cout<<"."; // Ekrana Nokta Ýþareti Bas 
			        
			if(ilk_Y1 == son_Y1) // iki Noktanýn Y Deðerleri Eþitse
			{
				return 0; // Döngüyü Bitir.
			}			
			}
			
			while(ilk_Y1 == son_Y1) // Y'ler Eþitse Çalýþ
			{ 
            gotoxy(ilk_X1,ilk_Y1); // Girilen Noktaya Haraket Et
            ilk_X1++;	// X Deðerini bir Arttýr
            cout<<"."; // Ekrana Nokta Ýþareti Bas
			         
			if(ilk_X1 == son_X1) // X 'ler Birbirine Eþitse
			{
				return 0; // Döngüyü Bitir.
			} 
			}			
			gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et
            cout<<"."; // Ekrana Nokta Ýþareti Bas
            ilk_X1++; // X  Deðerini bir Arttýr
            ilk_Y1++; // Y Deðerini bir Arttýr
            if(ilk_X1 == son_X1 && ilk_Y1 == son_Y1) // Noktalarýn Deðerleri Birbirine Eþit ise
			{
			return 0; // Döngüyü Bitir.
			} 
        }
        
    }
      
	  
	   
    else  if((ilk_X1 - son_X1)>0 && (ilk_Y1 - son_Y1)>0) // Sol Çapraz Yukarý 
    {
        while(!(ilk_X1 == son_X1 && ilk_Y1 == son_Y1)) // Noktalarýn Deðerleri Birbirine Eþit Olmayana Kadar Çalýþ
        {             
			while(ilk_X1 == son_X1) // X Deðerleri Birbirine Eþit ise Çalýþ
			{ 			
            gotoxy(ilk_X1,ilk_Y1); // Girilen Noktaya Haraket Et	
		    ilk_Y1--; // Y deðerini bir Azalt
            cout<<"."; // Ekrana Nokta Ýþareti Bas
            
            if(ilk_Y1 == son_Y1) // Y Deðerleri Birbirine Eþit ise
			{
			return 0; // Döngüyü Bitir .	
			} 
			}
			
			while(ilk_Y1 == son_Y1) // Y Deðerleri Birbirine Eþit ise Çalýþ
			{ 				
            gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et
			ilk_X1--; // X Deðerini Bir Azalt
            cout<<"."; // Ekrana Nokta Ýþareti Bas
            if(ilk_X1 == son_X1) // X Deðerleri Birbirine Eþit Ýse
			{
			return 0; // Döngüyü Bitir.	
			}			
			}
			
			gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et.
			ilk_X1--; // X Deðerini bir Azalt
            ilk_Y1--; // Y Deðerini bir Azalt
            cout<<"."; // Ekrana Nokta Ýþareti Bas          
        }
    }
    
  
     
   else  if((ilk_X1 - son_X1)>0 && (ilk_Y1 - son_Y1)<0) // Sol Aþþaðý Çapraz
    {
        while(!(ilk_X1 == son_X1 && ilk_Y1 == son_Y1)) // Nokta Deðerleri Eþit Olmayana Kadar Çalýþ
        {
			while(ilk_X1==son_X1) // X Deðerleri Birbirine Eþitse Çalýþ
		{ 			
            gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et
			ilk_Y1++; // Y Deðerini bir Arttýr
            cout<<"."; // Ekrana Nokta Ýþareti Bas
            if(ilk_Y1 == son_Y1) // Y Deðerleri Birbirine Eþit Ýse
			{
			return 0; // Döngüyü Bitir.	
			} 
		}
			
			while(ilk_Y1 == son_Y1) // Y Deðerleri Birbirine Eþitse Çalýþ
			{ 
            gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et
			ilk_X1--; // X Deðerini Bir Azalt	
            cout<<"."; // Ekrana Nokta Ýþareti Bas
            if(ilk_X1 == son_X1) // X Deðerleri Birbirine Eþit Ýse
			{
			return 0; // Döngüyü Bitir.	
			 } 
			}			
			gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et
			ilk_X1--; // X Deðerini bir Azalt
            ilk_Y1++; // Y Deðerini Bir Arttýr
            cout<<"."; // Ekrana Nokta Ýþareti Bas
           
        }        
    }
         
   else if((ilk_X1 - son_X1)<0 && (ilk_Y1 - son_Y1)>0) // Sað Yukarý Çapraz
    {
        while(!(ilk_X1 == son_X1 && ilk_Y1 == son_Y1)) // Nokta Deðerleri birbirine Eþit Olmayana Kadar Çalýþ
        {        
			while(ilk_X1==son_X1) // X Deðerleri Birbirine Eþitse Çalýþ
			{ 
            gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et
		    ilk_Y1--; // Y Deðerini Bir Azalt	
            cout<<"."; // Ekrana Nokta Ýþareti Bas
            if(ilk_Y1 == son_Y1) // Y Deðerleri Birbirine Eþit Ýse
			{
            return 0; // Döngüyü Bitir.	
			} 
			}
			
			while(ilk_Y1 == son_Y1) // Y Deðerleri Birbirine Eþitse Çalýþ
			{ 
            gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et
			ilk_X1++; // X Deðerini Bir Arttýr
            cout<<"."; // Ekrana Nokta Ýþareti Bas
            if(ilk_X1 == son_X1) // X Deðerleri Birbirine Eþit Ýse
			{
			return 0; // Döngüyü Bitir.	
			} 
			}		
			gotoxy(ilk_X1,ilk_Y1); // Girilen Deðere Haraket Et
			ilk_X1++; // X Deðerini bir Arttýr
            ilk_Y1--; // Y Deðerini bir Azalt
            cout<<".";  // Ekrana Nokta Ýþareti Bas
         
        }
    }
    	  
}

/* En Yakýn Noktayý Bulup , Rotayý Çizen ve Hedefe Ulaþan Fonksiyon*/
 int SystemFunction(void) // Parametre Almayan Deðer Döndüren Fonksiyon
{
 
Nokta Grid[100]; // Grid Ýsimli 100 Elemanlý Dizi Nesne Tanýmlamasý Yapýldý
 	
srand(time(NULL)); // Her Seferinde Farklý Random Sayýlar Üret
int baslangic_X1,baslangic_Y1; // Kullanýcýdan Alýnan Baþlangýç Noktalarýnýn Deðiþken Tanýmalamasý
int bitis_X1,bitis_Y1; // Kullanýcýdan Alýnan Bitis Noktalarýnýn Deðiþken Tanýmlamasý
int nX,nY; // Noktadan Noktaya Ýlerlerken Kullanýlan Sürekli Deðiken Sepet Deðiþken 
 
 /* Kullanýcýdan Baþlangýç ve Bitiþ Noktasýnýn Deðerlerinin Alýnmasý*/ 	
cout<<"Baþlangýç Noktasýnýn [X] Deðerini Giriniz : ";
cin>>baslangic_X1; // Kullanýcýdan ilk X Deðerinin Ýnputunu Al.
cout<<"Baþlangýç Noktasýnýn [Y] Deðerini Giriniz : ";
cin>>baslangic_Y1; // Kullanýcýdan ilk Y Deðerinin Ýnputunu Al.
cout<<"Bitiþ Noktasýnýn [X] Deðerini Giriniz : ";
cin>>bitis_X1; // Kullanýcýdan son X Deðerinin Ýnputunu Al.
cout<<"Bitiþ Noktasýnýn [Y] Deðerini Giriniz : ";
cin>>bitis_Y1; // Kullanýcýdan son Y Deðerinin Ýnputunu Al.
	
system("cls"); // Konsol Ekranýný Temizle

/* nX ve nY Baþlangýç Deðerlerine Eþitlenir.*/	
nX=baslangic_X1; 
nY=baslangic_Y1;
      
 /* 100 Defa Çalýþan Döngü */   
for(int t=0;t<100;t++) // Grid Nesnesine Random Deðer Atanan Kýsým 
{  
Grid[t]=Nokta(); // Grid Nesnesinin Her Deðerine Random Deðer Ata. 
// cout<<t<<". index X : "<<Grid[t].get_x();
// cout<<"    Y : "<<Grid[t].get_y()<<endl;
/* Yukarýdaki Yorum Satýrlarý Kaldýrýlarak Atanan Random Deðerler Gösterilebilir.*/
}
 
/* 100 Defa Çalýþan Döngü*/  	
for(int q=0;q<100;q++) // Girilen Random Deðeri Ekrana Basan Kýsým
{	
	gotoxy(Grid[q].get_x(),Grid[q].get_y()); // Girilen Deðere Haraket Et
	cout<<"O-"<<q; // Gidilen Noktanýn Ýndis Deðerini Ekrana Bas	
	Sleep(30); // 30ms Gecikme Süresi	
}

/* Baþlangýç ve Bitiþ Noktasýnýn Ekrana Basýldýðý Kýsým*/ 
gotoxy(baslangic_X1,baslangic_Y1); // Girilen Deðere Haraket Et
cout<<"O-B"; // Baþlangýcý Belirten Yazýyý Ekrana Bas
gotoxy(bitis_X1,bitis_Y1); // Girilen Deðere Haraket Et
cout<<"O-H"; // Bitiþi Belirten Yazýyý Ekrana Bas
         
float ToplamYol=0.0; // Rota Boyunca Ýzlediðimiz Yolun Uzunluðu

float SepetMesafe=500.0; // En Yakýn Noktanýn Bulunmasý için Kullanýlan  Sepet Mesafe Deðiþkeni 	  
int Yakin_Nokta_X[4],Yakin_Nokta_Y[4]; // En Yakýn Noktanýn X & Y Deðerlerinin Saklandýðý Diziler
int Yakin_Nokta_index; // En Yakýn Noktanýn Ýndex Deðerinin Saklanmasý için kullanýlan Sepet Deðiþken
float Yakin_Nokta_Mesafe[4]; // Referans Noktamýza En Yakýn Noktalarýn Mesafelerini Tutar

int Hedef_Nokta_index[4],Hedef_Nokta_X[4],Hedef_Nokta_Y[4]; // Hedefe En Yakýn 4 Noktanýn Bilgilerini Saklar
float SepetUzaklik=1000.0; // Hedefe Olan Uzaklik için Kullanýlan Sepet Uzaklýk Deðiþkeni
float Mesafe=0.0; // Hedefe En Yakýn Noktanýn Bulunmasý için Kullanýlan Sepet Mesafe Deðiþkeni
float Deqisken_Mesafe=0.0; // Hedefe En Yakýn Nokta için Kullanýlan Sepet Mesafe Deðiþkeni
    
gotoxy(50,150); // Girilen Deðere Haraket Et
	
while(1) // Sonsuz Döngü
{
/*4 Defa Çalýþan Döngü*/		
for(int j=0; j<4; j++) // En Yakýn 4 Nokta Ýçin
{
				
SepetMesafe=1000.0; // Her 4 Defada Standart Deðerine Geri Dön

/*100 Defa Çalýþan Döngü*/
for(int p=0; p<100; p++) // Totalde 4x100=400 Defa Çalýþan Döngü . Bu Döngü Grid[100] Sorgusu Ýçin
{
Mesafe=Grid[p].noktayaUzakligiBul(baslangic_X1,baslangic_Y1);/* Kullanýcýdan Alýnan Deðerler ile Random Sayýlarýn Deðerleri 
     Arasýndaki Uzaklýk Deðerleri Bulunur .*/
	           
if(SepetMesafe>Mesafe && j==0) // En Kýsa Mesafeyi Bul. 1.Nokta için
{ 	
/* En Yakýn 1.Noktanýn Bulunmasý , Mesafe , X, Y, Ýndex Bilgilerinin Saklandýðý Kýsým*/
		Yakin_Nokta_index=p; // Ýndex Deðerini Sepet Ýndex Deðiþkenine Ata.		
		SepetMesafe=Mesafe; // Yeni En Kýsa Mesafem Bulunan Kýsa Mesafedir.
		Yakin_Nokta_X[j]=Grid[p].get_x(); // Bulunan X Deðeri Dizide Tutulur
        Yakin_Nokta_Y[j]=Grid[p].get_y(); // Bulunan Y Deðeri Dizide Tutulur
        Yakin_Nokta_Mesafe[j]=SepetMesafe; // En Yakýn Mesafe Deðeri Tutulur.
}
		
else if(SepetMesafe>Mesafe && j==1 )  // En Kýsa Mesafeyi Bul. 2.Nokta için
{
/* En Yakýn 2.Noktanýn Bulunmasý , Mesafe , X, Y, Ýndex Bilgilerinin Saklandýðý Kýsým*/ 
		Yakin_Nokta_index=p; // Ýndex Deðerini Sepet Ýndex Deðiþkenine Ata.
		SepetMesafe=Mesafe; // Yeni En Kýsa Mesafem Bulunan Kýsa Mesafedir.
		Yakin_Nokta_X[j]=Grid[p].get_x(); // Bulunan X Deðeri Dizide Tutulur                      
        Yakin_Nokta_Y[j]=Grid[p].get_y(); // Bulunan Y Deðeri Dizide Tutulur  
        Yakin_Nokta_Mesafe[j]=SepetMesafe; // En Yakýn Mesafe Deðeri Tutulur. 
}
		
else if(SepetMesafe>Mesafe && j==2) // En Kýsa Mesafeyi Bul . 3.Nokta için
{ 
/* En Yakýn 3.Noktanýn Bulunmasý , Mesafe , X, Y, Ýndex Bilgilerinin Saklandýðý Kýsým*/
		Yakin_Nokta_index=p; // Ýndex Deðerini Sepet Ýndex Deðiþkenine Ata.
		SepetMesafe=Mesafe; // Yeni En Kýsa Mesafem Bulunan Kýsa Mesafedir.
		Yakin_Nokta_X[j]=Grid[p].get_x(); // Bulunan X Deðeri Dizide Tutulur 
        Yakin_Nokta_Y[j]=Grid[p].get_y();  // Bulunan Y Deðeri Dizide Tutulur 
        Yakin_Nokta_Mesafe[j]=SepetMesafe;  // En Yakýn Mesafe Deðeri Tutulur.
}
		
else if(SepetMesafe>Mesafe && j==3) // En Kýsa Mesafeyi Bul . 4.Nokta için
{ 
/* En Yakýn 4.Noktanýn Bulunmasý , Mesafe , X, Y, Ýndex Bilgilerinin Saklandýðý Kýsým*/
		Yakin_Nokta_index=p; // Ýndex Deðerini Sepet Ýndex Deðiþkenine Ata.
		SepetMesafe=Mesafe; // Yeni En Kýsa Mesafem Bulunan Kýsa Mesafedir.
		Yakin_Nokta_X[j]=Grid[p].get_x(); // Bulunan X Deðeri Dizide Tutulur 
        Yakin_Nokta_Y[j]=Grid[p].get_y(); // Bulunan Y Deðeri Dizide Tutulur
        Yakin_Nokta_Mesafe[j]=SepetMesafe; // En Yakýn Mesafe Deðeri Tutulur.
}
}

/* Bir Önceki Noktayý Yeniden Almamasý için Uzak Konuma Atýlan Noktanýn Bilgilerinin Saklandýðý Kýsým*/
Hedef_Nokta_index[j]=Yakin_Nokta_index; // En Kýsa Mesafenin Ýndexi Tutulur
Hedef_Nokta_X[j]=Grid[Yakin_Nokta_index].get_x(); // En Kýsa Mesafenin X  Deðeri Tutulur
Hedef_Nokta_Y[j]=Grid[Yakin_Nokta_index].get_y(); // En Kýsa Mesafenin Y Deðeri Tutulur
Grid[Yakin_Nokta_index]=Nokta(150,50); // Bir Daha Bu Noktayý Sorgulamamak için konumunu deðiþtirebiliceðimiz en uzak noktaya deðiþtiririz
    	
cout<<endl; // 1 Satýr Alta Geç
		
}

/* En Yakýn 4 Noktanýn Hedefe Olan Uzaklýklarý*/
Deqisken_Mesafe=500.0; // Sepet Mesafe Sorgusu için Kullanýlan Deðiþken
/*4 Defa Çalýþacak DÖngü*/
for(int Z=0;Z<4;Z++) 
{				
Mesafe=sqrt(pow((bitis_X1-Hedef_Nokta_X[Z]),2)+pow((bitis_Y1-Hedef_Nokta_Y[Z]),2)); // Uzaklýk Hesaplamasý Yapýlýr.	   
//cout<<Z+1<<". Noktanýn Hedefe Uzaklýðý : "<<uzaklik<<endl;
/* Yukarýdaki Yorum Satýrý Kaldýrýlarak 4 Noktanýn Hedefe Olan Uzaklýklarý Saptanýr*/ 					
if(Deqisken_Mesafe>Mesafe) // Sürekli Azalan Uzaklýk Deðerinin Sorgusu
{					
		Deqisken_Mesafe=Mesafe; // En Kýsa Uzaklýðý Tazeleyip Ata
		baslangic_X1=Hedef_Nokta_X[Z]; // Eski X Deðerini Ata 
		baslangic_Y1=Hedef_Nokta_Y[Z]; // Eski Y Deðerini Ata    
}
}
/* Eski Nokta ile Yeni Nokta Arasýnda "." Çizgisi Çekilir .*/	
NoktaLine(nX,nY,baslangic_X1,baslangic_Y1);// Girilen Deðerlere Kadar Doðru Oluþturucacak Þekilde Noktalar Býrak
Sleep(500); // 500ms Gecikme Süresi

/* Uzak Konumu ()150,50) Olarak Atandýðýnda &  Hedef Nokta X:150 & Y:50 Olursa  Oluþan Problemi Aþmak için Olan Kýsým*/	
if(baslangic_X1==150 && baslangic_Y1==50) 
{  
	  	//	cout<<" # Hedefe Ulaþýldý ... ";
	  		NoktaLine(baslangic_X1,baslangic_Y1,bitis_X1,bitis_Y1); // Hedefe En Yakýn Noktaya Haraket Et
	  		Sleep(500); // 500ms Gecikme Süresi
	  		while(1)
			{
			gotoxy(0,51); // Girilen Deðere Haraket Et
		    ToplamYol += Deqisken_Mesafe; // ToplamYolu GeciciUzaklýk Deðeri Kadar Arttýr
            cout<<" ==> Yol Boyunca Alýnan Mesafe : "<<ToplamYol<<endl; // Alýnan Toplam Yolu Ekrana Bas
    		return 0; // Döngüyü Bitir
		    }		   		    
} 

/* Katsayýlar Denemeler Sonucunda Elde Edilmiþtir.*/
else if (abs(Deqisken_Mesafe-SepetUzaklik)<=10.0 && Deqisken_Mesafe < 10.0 ) // Hedeften Önceki Yakýn Noktalar Hedefe Yakýnsa , Hedefe Ýlerle
{
//	cout<<endl<<"  Hedefe Ulaþtýnýz ...  "<<endl;
NoktaLine(baslangic_X1,baslangic_Y1,bitis_X1,bitis_Y1); // Girilen Deðerlere Kadar Doðru Oluþturucacak Þekilde Noktalar Býrak
Sleep(500); // 500ms Gecikme Süresi

           while(1) // Sonsuz Döngüye Gir
		{
			gotoxy(0,51); // Girilen Deðere Haraket Et
			ToplamYol += Deqisken_Mesafe; // ToplamYolu GeciciUzaklik Kadar Arttýr
            cout<<" ==> Yol Boyunca Alýnan Mesafe : "<<ToplamYol<<endl; // Alýnan Toplam Yolu Ekrana Bas
    		return 0; // Döngüyü Bitir
		}	
}

/* Seçilen Noktanýn Hedefe Olan En Kýsa Mesafeyi Bulunan Yer*/		    	
else if(SepetUzaklik<Deqisken_Mesafe) // Eðer Hedefe Olan Uzaklýk Artmaya Baþlarsa Dur . !
{ 
//	cout<<endl<<"  Hedefe Ulaþtýnýz ...  "<<endl;
NoktaLine(baslangic_X1,baslangic_Y1,bitis_X1,bitis_Y1); // Girilen Deðerlere Kadar Doðru Oluþturucacak Þekilde Noktalar Býrak
Sleep(500); // 500ms Gecikme Süresi

           while(1) // Sonsuz Döngüye Gir
		{
			gotoxy(0,51); // Girilen Deðere Haraket Et
			ToplamYol += Deqisken_Mesafe; // ToplamYolu GeciciUzaklik Kadar Arttýr
            cout<<" ==> Yol Boyunca Alýnan Mesafe : "<<ToplamYol<<endl; // Alýnan Toplam Yolu Ekrana Bas
    		return 0; // Döngüyü Bitir
		}			
}

SepetUzaklik=Deqisken_Mesafe; // Eski Uzaklik Yeni Uzaklik Deðerine Eþittir.	 
ToplamYol += SepetMesafe; // Alýnan Toplam Yolu Saptanan Mesafe Deðeri Kadar Arttýr
			    
nX=baslangic_X1; // Eski Kordinatýn X Deðeri , Yeni Kordinatýn X Deðeri Olur.
nY=baslangic_Y1; // Eski Kordinatýn Y Deðeri , Yeni Kordinatýn Y Deðeri Olur.	  	 
}
}
	
int main(void)  // Ana Main Fonksiyonu

{ 
string AnaEkranModu = "1"; // Ekran Modu için Kullanýlan Char Dizisi

while(1) // Sonsuz Döngü
{
	setlocale(LC_ALL,"Turkish"); // Konsol Ekraný Türkçe Yapýldý
	
	if(AnaEkranModu == "1") // Eðer Ekran Modu "1" Karakterine Eþit mi
	{
	AnaEkranModu="0"; // Menu Durumu Sýfýrla
	SystemFunction(); // Çalýþma Fonksiyonunu Çaðýr
	gotoxy(0,53); // Girilen Deðere Haraket Et
	cout<<"## Tekrar Çalýþtýrmak Ýçin 1 Tuþlayýnýz ... "<<endl<<endl; // Kullanýcýya Ýkaz Bildirilmesi
	cout<<"## Tuþlanan Sayý : "; // Kullanýcýya Ýkaz Bildirildi
	cin>>AnaEkranModu; // Kullanýcýdan Ýnput Al	
	}
		
	if(AnaEkranModu =="1") // Kullanýcýdan "1" Alýrsan Ekraný Önce Bir Temizle
	{
	 system("cls"); // Ekraný Temizle	
	}
			
	else if(AnaEkranModu != "1") // Kullanýcýdan "1" Almazsan Aþþaðýdaki Satýrlarý Yürüt.
	{
		cout<<endl; // 1 Satýr Aþþaðý Geç
		cout<<"  Hatalý Seçim ! Lütfen Yeniden Denemek için ENTER'ý Tuþlayýnýz."<<endl; // Kullanýcýya Ýkaz Bildirilmesi
		getch(); // Karakter Girilene Kadar Bekle
		cout<<endl; // 1 Satýr Alta Geçir	
		for(int P=0; P<80; P++) // 50 Defa Çalýþan Bir Döngü
		{
			cout<<"*"; // Ekrana Yan Yana * Karakterini Bas
			Sleep(10); // Ekraný 10ms Beklet (Gecikme Süresi)	
		}
		cout<<endl; // Ekraný 1 Satýr Alta Geçir
		system("cls"); // Ekraný Temizle
		gotoxy(0,0); // Girilen Noktaya Haraket Et
		cout<<"## Tekrar Çalýþtýrmak Ýçin 1 Tuþlayýnýz ... "<<endl<<endl; // Kullanýcýya Ýkaz Bildirilmesi
	    cout<<"## Tuþlanan Sayý : "; // Kullanýcýya Ýkaz Bildirilmesi
	    cin>>AnaEkranModu; // Kullanýcýdan Ýnput Al
	    system("cls"); // Ekraný Temizle
	}
}
}

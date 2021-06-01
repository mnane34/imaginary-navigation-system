
#include "Nokta.h" // Class ve Fonk. kullanmak i�in Gerekli K�t�phane Dahil Edildi.
#include <iostream> // C++ K�t�phanesi dahil edildi. 
#include <stdlib.h> // Srand() Fonksiyonu i�in Gerekli K�t�phane Dahil Edildi.
#include <windows.h> // Sleep ve gotoxy Fonksiyonu i�in Gerekli K�t�phane Dahil Edildi.
#include <conio.h> // getch() Fonksiyonu i�in Gerekli K�t�phane Dahil Edildi.
#include <locale.h> // Konsol Ekran�n� t�rk�e yapmak i�in Gerekli K�t�phane Dahil Edildi.
#include <math.h> // Pow() ve Sqrt() Fonksiyonlar� i�in Gerekli K�t�phane Dahil Edildi.

using namespace std; // Std Fonksiyonlar� �a�r�ld�

/* Konsol Ekran�nda istenilen Noktaya Kursoru G�t�rmek i�in Kullan�lan Fonksiyon*/
void gotoxy(unsigned long int x, unsigned long int y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


/* Noktadan Noktaya Giderken Al�nan Yollara "." ��areti B�rakan Fonksiyon*/

int NoktaLine(int ilk_X1 ,int ilk_Y1 , int son_X1 ,int son_Y1) // 4 Parametreli �nteger De�er D�nd�ren Fonksiyon
{
		
	 if((ilk_X1 - son_X1) == 0 && (ilk_Y1 - son_Y1)>0) // Dikey Yukar�
	{ 
	   while(!(ilk_Y1 == son_Y1)) // Y De�erleri E�it Oluncaya Kadar �al��
        {           
            gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et
			ilk_Y1--; // Y De�erini Bir Azalt
            cout<<"."; // Ekrana Nokta ��areti Bas
            if(ilk_Y1 == son_Y1) // Y De�erleri E�it �se
			{
			 return 0;	// D�ng�y� Bitir.
			} 
			}	  	   	
	}
	
	
	else if((ilk_X1 - son_X1) == 0 && (ilk_Y1 - son_Y1)<0) // Dikey A��a��
	{      
	   while(!(ilk_Y1 == son_Y1)) // Y De�erleri E�it Olmayana Kadar �al��
        {
            gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et
			ilk_Y1++; // Y De�erini bir Artt�r
            cout<<"."; // Ekrana Nokta ��areti Bas
            if(ilk_Y1 == son_Y1) // Y De�erleri E�it �se
			{
            return 0; // D�ng�y� Bitir.	
			} 
			}	  	    	
	}
	
	
	else if((ilk_X1 - son_X1)<0 && (ilk_Y1 - son_Y1) == 0) // Yatay Sa�a
	{   
	   while(!(ilk_X1 == son_X1)) // X De�erleri E�it Oluncaya Kadar �al��
        {       
            gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et 
			ilk_X1++; // X De�erini Bir Artt�r
            cout<<"."; // Ekrana Nokta ��areti Bas
            if(ilk_X1 == son_X1) // X De�erleri E�it �se
			{
			return 0; // D�ng�y� Bitir 
			}
			}	  		
	}
	
	
	
	
    else if((ilk_X1 - son_X1)>0 && (ilk_Y1 - son_Y1) == 0) // Yatay Sola
	{   
	   while(!(ilk_X1 == son_X1)) // X De�erleri E�it Oluncaya Kadar �al��
        {
            gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et
			ilk_X1--; // X De�erini Bir Azalt
            cout<<"."; // Ekrana Nokta ��areti Bas
            if(ilk_X1 == son_X1) // X De�erleri E�it �se
			{
            return 0; // D�ng�y� Bitir	
			} 
		}	  		
	} 
	
	
		
    else if((ilk_X1 - son_X1)<0 && (ilk_Y1 - son_Y1)<0) // Sa� A��a�� �apraz 
    {
        while(!(ilk_X1 == son_X1 && ilk_Y1 == son_Y1)) // �ki Noktan�n De�eri Birbirine E�it Oluncaya Kadar �al��
        {
			while(ilk_X1==son_X1) // E�er X'ler E�itse �al��
			{ 
            gotoxy(ilk_X1,ilk_Y1); // Girilen Noktaya Haraket Et
            ilk_Y1++; // Y De�erini bir Artt�r
            cout<<"."; // Ekrana Nokta ��areti Bas 
			        
			if(ilk_Y1 == son_Y1) // iki Noktan�n Y De�erleri E�itse
			{
				return 0; // D�ng�y� Bitir.
			}			
			}
			
			while(ilk_Y1 == son_Y1) // Y'ler E�itse �al��
			{ 
            gotoxy(ilk_X1,ilk_Y1); // Girilen Noktaya Haraket Et
            ilk_X1++;	// X De�erini bir Artt�r
            cout<<"."; // Ekrana Nokta ��areti Bas
			         
			if(ilk_X1 == son_X1) // X 'ler Birbirine E�itse
			{
				return 0; // D�ng�y� Bitir.
			} 
			}			
			gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et
            cout<<"."; // Ekrana Nokta ��areti Bas
            ilk_X1++; // X  De�erini bir Artt�r
            ilk_Y1++; // Y De�erini bir Artt�r
            if(ilk_X1 == son_X1 && ilk_Y1 == son_Y1) // Noktalar�n De�erleri Birbirine E�it ise
			{
			return 0; // D�ng�y� Bitir.
			} 
        }
        
    }
      
	  
	   
    else  if((ilk_X1 - son_X1)>0 && (ilk_Y1 - son_Y1)>0) // Sol �apraz Yukar� 
    {
        while(!(ilk_X1 == son_X1 && ilk_Y1 == son_Y1)) // Noktalar�n De�erleri Birbirine E�it Olmayana Kadar �al��
        {             
			while(ilk_X1 == son_X1) // X De�erleri Birbirine E�it ise �al��
			{ 			
            gotoxy(ilk_X1,ilk_Y1); // Girilen Noktaya Haraket Et	
		    ilk_Y1--; // Y de�erini bir Azalt
            cout<<"."; // Ekrana Nokta ��areti Bas
            
            if(ilk_Y1 == son_Y1) // Y De�erleri Birbirine E�it ise
			{
			return 0; // D�ng�y� Bitir .	
			} 
			}
			
			while(ilk_Y1 == son_Y1) // Y De�erleri Birbirine E�it ise �al��
			{ 				
            gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et
			ilk_X1--; // X De�erini Bir Azalt
            cout<<"."; // Ekrana Nokta ��areti Bas
            if(ilk_X1 == son_X1) // X De�erleri Birbirine E�it �se
			{
			return 0; // D�ng�y� Bitir.	
			}			
			}
			
			gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et.
			ilk_X1--; // X De�erini bir Azalt
            ilk_Y1--; // Y De�erini bir Azalt
            cout<<"."; // Ekrana Nokta ��areti Bas          
        }
    }
    
  
     
   else  if((ilk_X1 - son_X1)>0 && (ilk_Y1 - son_Y1)<0) // Sol A��a�� �apraz
    {
        while(!(ilk_X1 == son_X1 && ilk_Y1 == son_Y1)) // Nokta De�erleri E�it Olmayana Kadar �al��
        {
			while(ilk_X1==son_X1) // X De�erleri Birbirine E�itse �al��
		{ 			
            gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et
			ilk_Y1++; // Y De�erini bir Artt�r
            cout<<"."; // Ekrana Nokta ��areti Bas
            if(ilk_Y1 == son_Y1) // Y De�erleri Birbirine E�it �se
			{
			return 0; // D�ng�y� Bitir.	
			} 
		}
			
			while(ilk_Y1 == son_Y1) // Y De�erleri Birbirine E�itse �al��
			{ 
            gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et
			ilk_X1--; // X De�erini Bir Azalt	
            cout<<"."; // Ekrana Nokta ��areti Bas
            if(ilk_X1 == son_X1) // X De�erleri Birbirine E�it �se
			{
			return 0; // D�ng�y� Bitir.	
			 } 
			}			
			gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et
			ilk_X1--; // X De�erini bir Azalt
            ilk_Y1++; // Y De�erini Bir Artt�r
            cout<<"."; // Ekrana Nokta ��areti Bas
           
        }        
    }
         
   else if((ilk_X1 - son_X1)<0 && (ilk_Y1 - son_Y1)>0) // Sa� Yukar� �apraz
    {
        while(!(ilk_X1 == son_X1 && ilk_Y1 == son_Y1)) // Nokta De�erleri birbirine E�it Olmayana Kadar �al��
        {        
			while(ilk_X1==son_X1) // X De�erleri Birbirine E�itse �al��
			{ 
            gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et
		    ilk_Y1--; // Y De�erini Bir Azalt	
            cout<<"."; // Ekrana Nokta ��areti Bas
            if(ilk_Y1 == son_Y1) // Y De�erleri Birbirine E�it �se
			{
            return 0; // D�ng�y� Bitir.	
			} 
			}
			
			while(ilk_Y1 == son_Y1) // Y De�erleri Birbirine E�itse �al��
			{ 
            gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et
			ilk_X1++; // X De�erini Bir Artt�r
            cout<<"."; // Ekrana Nokta ��areti Bas
            if(ilk_X1 == son_X1) // X De�erleri Birbirine E�it �se
			{
			return 0; // D�ng�y� Bitir.	
			} 
			}		
			gotoxy(ilk_X1,ilk_Y1); // Girilen De�ere Haraket Et
			ilk_X1++; // X De�erini bir Artt�r
            ilk_Y1--; // Y De�erini bir Azalt
            cout<<".";  // Ekrana Nokta ��areti Bas
         
        }
    }
    	  
}

/* En Yak�n Noktay� Bulup , Rotay� �izen ve Hedefe Ula�an Fonksiyon*/
 int SystemFunction(void) // Parametre Almayan De�er D�nd�ren Fonksiyon
{
 
Nokta Grid[100]; // Grid �simli 100 Elemanl� Dizi Nesne Tan�mlamas� Yap�ld�
 	
srand(time(NULL)); // Her Seferinde Farkl� Random Say�lar �ret
int baslangic_X1,baslangic_Y1; // Kullan�c�dan Al�nan Ba�lang�� Noktalar�n�n De�i�ken Tan�malamas�
int bitis_X1,bitis_Y1; // Kullan�c�dan Al�nan Bitis Noktalar�n�n De�i�ken Tan�mlamas�
int nX,nY; // Noktadan Noktaya �lerlerken Kullan�lan S�rekli De�iken Sepet De�i�ken 
 
 /* Kullan�c�dan Ba�lang�� ve Biti� Noktas�n�n De�erlerinin Al�nmas�*/ 	
cout<<"Ba�lang�� Noktas�n�n [X] De�erini Giriniz : ";
cin>>baslangic_X1; // Kullan�c�dan ilk X De�erinin �nputunu Al.
cout<<"Ba�lang�� Noktas�n�n [Y] De�erini Giriniz : ";
cin>>baslangic_Y1; // Kullan�c�dan ilk Y De�erinin �nputunu Al.
cout<<"Biti� Noktas�n�n [X] De�erini Giriniz : ";
cin>>bitis_X1; // Kullan�c�dan son X De�erinin �nputunu Al.
cout<<"Biti� Noktas�n�n [Y] De�erini Giriniz : ";
cin>>bitis_Y1; // Kullan�c�dan son Y De�erinin �nputunu Al.
	
system("cls"); // Konsol Ekran�n� Temizle

/* nX ve nY Ba�lang�� De�erlerine E�itlenir.*/	
nX=baslangic_X1; 
nY=baslangic_Y1;
      
 /* 100 Defa �al��an D�ng� */   
for(int t=0;t<100;t++) // Grid Nesnesine Random De�er Atanan K�s�m 
{  
Grid[t]=Nokta(); // Grid Nesnesinin Her De�erine Random De�er Ata. 
// cout<<t<<". index X : "<<Grid[t].get_x();
// cout<<"    Y : "<<Grid[t].get_y()<<endl;
/* Yukar�daki Yorum Sat�rlar� Kald�r�larak Atanan Random De�erler G�sterilebilir.*/
}
 
/* 100 Defa �al��an D�ng�*/  	
for(int q=0;q<100;q++) // Girilen Random De�eri Ekrana Basan K�s�m
{	
	gotoxy(Grid[q].get_x(),Grid[q].get_y()); // Girilen De�ere Haraket Et
	cout<<"O-"<<q; // Gidilen Noktan�n �ndis De�erini Ekrana Bas	
	Sleep(30); // 30ms Gecikme S�resi	
}

/* Ba�lang�� ve Biti� Noktas�n�n Ekrana Bas�ld��� K�s�m*/ 
gotoxy(baslangic_X1,baslangic_Y1); // Girilen De�ere Haraket Et
cout<<"O-B"; // Ba�lang�c� Belirten Yaz�y� Ekrana Bas
gotoxy(bitis_X1,bitis_Y1); // Girilen De�ere Haraket Et
cout<<"O-H"; // Biti�i Belirten Yaz�y� Ekrana Bas
         
float ToplamYol=0.0; // Rota Boyunca �zledi�imiz Yolun Uzunlu�u

float SepetMesafe=500.0; // En Yak�n Noktan�n Bulunmas� i�in Kullan�lan  Sepet Mesafe De�i�keni 	  
int Yakin_Nokta_X[4],Yakin_Nokta_Y[4]; // En Yak�n Noktan�n X & Y De�erlerinin Sakland��� Diziler
int Yakin_Nokta_index; // En Yak�n Noktan�n �ndex De�erinin Saklanmas� i�in kullan�lan Sepet De�i�ken
float Yakin_Nokta_Mesafe[4]; // Referans Noktam�za En Yak�n Noktalar�n Mesafelerini Tutar

int Hedef_Nokta_index[4],Hedef_Nokta_X[4],Hedef_Nokta_Y[4]; // Hedefe En Yak�n 4 Noktan�n Bilgilerini Saklar
float SepetUzaklik=1000.0; // Hedefe Olan Uzaklik i�in Kullan�lan Sepet Uzakl�k De�i�keni
float Mesafe=0.0; // Hedefe En Yak�n Noktan�n Bulunmas� i�in Kullan�lan Sepet Mesafe De�i�keni
float Deqisken_Mesafe=0.0; // Hedefe En Yak�n Nokta i�in Kullan�lan Sepet Mesafe De�i�keni
    
gotoxy(50,150); // Girilen De�ere Haraket Et
	
while(1) // Sonsuz D�ng�
{
/*4 Defa �al��an D�ng�*/		
for(int j=0; j<4; j++) // En Yak�n 4 Nokta ��in
{
				
SepetMesafe=1000.0; // Her 4 Defada Standart De�erine Geri D�n

/*100 Defa �al��an D�ng�*/
for(int p=0; p<100; p++) // Totalde 4x100=400 Defa �al��an D�ng� . Bu D�ng� Grid[100] Sorgusu ��in
{
Mesafe=Grid[p].noktayaUzakligiBul(baslangic_X1,baslangic_Y1);/* Kullan�c�dan Al�nan De�erler ile Random Say�lar�n De�erleri 
     Aras�ndaki Uzakl�k De�erleri Bulunur .*/
	           
if(SepetMesafe>Mesafe && j==0) // En K�sa Mesafeyi Bul. 1.Nokta i�in
{ 	
/* En Yak�n 1.Noktan�n Bulunmas� , Mesafe , X, Y, �ndex Bilgilerinin Sakland��� K�s�m*/
		Yakin_Nokta_index=p; // �ndex De�erini Sepet �ndex De�i�kenine Ata.		
		SepetMesafe=Mesafe; // Yeni En K�sa Mesafem Bulunan K�sa Mesafedir.
		Yakin_Nokta_X[j]=Grid[p].get_x(); // Bulunan X De�eri Dizide Tutulur
        Yakin_Nokta_Y[j]=Grid[p].get_y(); // Bulunan Y De�eri Dizide Tutulur
        Yakin_Nokta_Mesafe[j]=SepetMesafe; // En Yak�n Mesafe De�eri Tutulur.
}
		
else if(SepetMesafe>Mesafe && j==1 )  // En K�sa Mesafeyi Bul. 2.Nokta i�in
{
/* En Yak�n 2.Noktan�n Bulunmas� , Mesafe , X, Y, �ndex Bilgilerinin Sakland��� K�s�m*/ 
		Yakin_Nokta_index=p; // �ndex De�erini Sepet �ndex De�i�kenine Ata.
		SepetMesafe=Mesafe; // Yeni En K�sa Mesafem Bulunan K�sa Mesafedir.
		Yakin_Nokta_X[j]=Grid[p].get_x(); // Bulunan X De�eri Dizide Tutulur                      
        Yakin_Nokta_Y[j]=Grid[p].get_y(); // Bulunan Y De�eri Dizide Tutulur  
        Yakin_Nokta_Mesafe[j]=SepetMesafe; // En Yak�n Mesafe De�eri Tutulur. 
}
		
else if(SepetMesafe>Mesafe && j==2) // En K�sa Mesafeyi Bul . 3.Nokta i�in
{ 
/* En Yak�n 3.Noktan�n Bulunmas� , Mesafe , X, Y, �ndex Bilgilerinin Sakland��� K�s�m*/
		Yakin_Nokta_index=p; // �ndex De�erini Sepet �ndex De�i�kenine Ata.
		SepetMesafe=Mesafe; // Yeni En K�sa Mesafem Bulunan K�sa Mesafedir.
		Yakin_Nokta_X[j]=Grid[p].get_x(); // Bulunan X De�eri Dizide Tutulur 
        Yakin_Nokta_Y[j]=Grid[p].get_y();  // Bulunan Y De�eri Dizide Tutulur 
        Yakin_Nokta_Mesafe[j]=SepetMesafe;  // En Yak�n Mesafe De�eri Tutulur.
}
		
else if(SepetMesafe>Mesafe && j==3) // En K�sa Mesafeyi Bul . 4.Nokta i�in
{ 
/* En Yak�n 4.Noktan�n Bulunmas� , Mesafe , X, Y, �ndex Bilgilerinin Sakland��� K�s�m*/
		Yakin_Nokta_index=p; // �ndex De�erini Sepet �ndex De�i�kenine Ata.
		SepetMesafe=Mesafe; // Yeni En K�sa Mesafem Bulunan K�sa Mesafedir.
		Yakin_Nokta_X[j]=Grid[p].get_x(); // Bulunan X De�eri Dizide Tutulur 
        Yakin_Nokta_Y[j]=Grid[p].get_y(); // Bulunan Y De�eri Dizide Tutulur
        Yakin_Nokta_Mesafe[j]=SepetMesafe; // En Yak�n Mesafe De�eri Tutulur.
}
}

/* Bir �nceki Noktay� Yeniden Almamas� i�in Uzak Konuma At�lan Noktan�n Bilgilerinin Sakland��� K�s�m*/
Hedef_Nokta_index[j]=Yakin_Nokta_index; // En K�sa Mesafenin �ndexi Tutulur
Hedef_Nokta_X[j]=Grid[Yakin_Nokta_index].get_x(); // En K�sa Mesafenin X  De�eri Tutulur
Hedef_Nokta_Y[j]=Grid[Yakin_Nokta_index].get_y(); // En K�sa Mesafenin Y De�eri Tutulur
Grid[Yakin_Nokta_index]=Nokta(150,50); // Bir Daha Bu Noktay� Sorgulamamak i�in konumunu de�i�tirebilice�imiz en uzak noktaya de�i�tiririz
    	
cout<<endl; // 1 Sat�r Alta Ge�
		
}

/* En Yak�n 4 Noktan�n Hedefe Olan Uzakl�klar�*/
Deqisken_Mesafe=500.0; // Sepet Mesafe Sorgusu i�in Kullan�lan De�i�ken
/*4 Defa �al��acak D�ng�*/
for(int Z=0;Z<4;Z++) 
{				
Mesafe=sqrt(pow((bitis_X1-Hedef_Nokta_X[Z]),2)+pow((bitis_Y1-Hedef_Nokta_Y[Z]),2)); // Uzakl�k Hesaplamas� Yap�l�r.	   
//cout<<Z+1<<". Noktan�n Hedefe Uzakl��� : "<<uzaklik<<endl;
/* Yukar�daki Yorum Sat�r� Kald�r�larak 4 Noktan�n Hedefe Olan Uzakl�klar� Saptan�r*/ 					
if(Deqisken_Mesafe>Mesafe) // S�rekli Azalan Uzakl�k De�erinin Sorgusu
{					
		Deqisken_Mesafe=Mesafe; // En K�sa Uzakl��� Tazeleyip Ata
		baslangic_X1=Hedef_Nokta_X[Z]; // Eski X De�erini Ata 
		baslangic_Y1=Hedef_Nokta_Y[Z]; // Eski Y De�erini Ata    
}
}
/* Eski Nokta ile Yeni Nokta Aras�nda "." �izgisi �ekilir .*/	
NoktaLine(nX,nY,baslangic_X1,baslangic_Y1);// Girilen De�erlere Kadar Do�ru Olu�turucacak �ekilde Noktalar B�rak
Sleep(500); // 500ms Gecikme S�resi

/* Uzak Konumu ()150,50) Olarak Atand���nda &  Hedef Nokta X:150 & Y:50 Olursa  Olu�an Problemi A�mak i�in Olan K�s�m*/	
if(baslangic_X1==150 && baslangic_Y1==50) 
{  
	  	//	cout<<" # Hedefe Ula��ld� ... ";
	  		NoktaLine(baslangic_X1,baslangic_Y1,bitis_X1,bitis_Y1); // Hedefe En Yak�n Noktaya Haraket Et
	  		Sleep(500); // 500ms Gecikme S�resi
	  		while(1)
			{
			gotoxy(0,51); // Girilen De�ere Haraket Et
		    ToplamYol += Deqisken_Mesafe; // ToplamYolu GeciciUzakl�k De�eri Kadar Artt�r
            cout<<" ==> Yol Boyunca Al�nan Mesafe : "<<ToplamYol<<endl; // Al�nan Toplam Yolu Ekrana Bas
    		return 0; // D�ng�y� Bitir
		    }		   		    
} 

/* Katsay�lar Denemeler Sonucunda Elde Edilmi�tir.*/
else if (abs(Deqisken_Mesafe-SepetUzaklik)<=10.0 && Deqisken_Mesafe < 10.0 ) // Hedeften �nceki Yak�n Noktalar Hedefe Yak�nsa , Hedefe �lerle
{
//	cout<<endl<<"  Hedefe Ula�t�n�z ...  "<<endl;
NoktaLine(baslangic_X1,baslangic_Y1,bitis_X1,bitis_Y1); // Girilen De�erlere Kadar Do�ru Olu�turucacak �ekilde Noktalar B�rak
Sleep(500); // 500ms Gecikme S�resi

           while(1) // Sonsuz D�ng�ye Gir
		{
			gotoxy(0,51); // Girilen De�ere Haraket Et
			ToplamYol += Deqisken_Mesafe; // ToplamYolu GeciciUzaklik Kadar Artt�r
            cout<<" ==> Yol Boyunca Al�nan Mesafe : "<<ToplamYol<<endl; // Al�nan Toplam Yolu Ekrana Bas
    		return 0; // D�ng�y� Bitir
		}	
}

/* Se�ilen Noktan�n Hedefe Olan En K�sa Mesafeyi Bulunan Yer*/		    	
else if(SepetUzaklik<Deqisken_Mesafe) // E�er Hedefe Olan Uzakl�k Artmaya Ba�larsa Dur . !
{ 
//	cout<<endl<<"  Hedefe Ula�t�n�z ...  "<<endl;
NoktaLine(baslangic_X1,baslangic_Y1,bitis_X1,bitis_Y1); // Girilen De�erlere Kadar Do�ru Olu�turucacak �ekilde Noktalar B�rak
Sleep(500); // 500ms Gecikme S�resi

           while(1) // Sonsuz D�ng�ye Gir
		{
			gotoxy(0,51); // Girilen De�ere Haraket Et
			ToplamYol += Deqisken_Mesafe; // ToplamYolu GeciciUzaklik Kadar Artt�r
            cout<<" ==> Yol Boyunca Al�nan Mesafe : "<<ToplamYol<<endl; // Al�nan Toplam Yolu Ekrana Bas
    		return 0; // D�ng�y� Bitir
		}			
}

SepetUzaklik=Deqisken_Mesafe; // Eski Uzaklik Yeni Uzaklik De�erine E�ittir.	 
ToplamYol += SepetMesafe; // Al�nan Toplam Yolu Saptanan Mesafe De�eri Kadar Artt�r
			    
nX=baslangic_X1; // Eski Kordinat�n X De�eri , Yeni Kordinat�n X De�eri Olur.
nY=baslangic_Y1; // Eski Kordinat�n Y De�eri , Yeni Kordinat�n Y De�eri Olur.	  	 
}
}
	
int main(void)  // Ana Main Fonksiyonu

{ 
string AnaEkranModu = "1"; // Ekran Modu i�in Kullan�lan Char Dizisi

while(1) // Sonsuz D�ng�
{
	setlocale(LC_ALL,"Turkish"); // Konsol Ekran� T�rk�e Yap�ld�
	
	if(AnaEkranModu == "1") // E�er Ekran Modu "1" Karakterine E�it mi
	{
	AnaEkranModu="0"; // Menu Durumu S�f�rla
	SystemFunction(); // �al��ma Fonksiyonunu �a��r
	gotoxy(0,53); // Girilen De�ere Haraket Et
	cout<<"## Tekrar �al��t�rmak ��in 1 Tu�lay�n�z ... "<<endl<<endl; // Kullan�c�ya �kaz Bildirilmesi
	cout<<"## Tu�lanan Say� : "; // Kullan�c�ya �kaz Bildirildi
	cin>>AnaEkranModu; // Kullan�c�dan �nput Al	
	}
		
	if(AnaEkranModu =="1") // Kullan�c�dan "1" Al�rsan Ekran� �nce Bir Temizle
	{
	 system("cls"); // Ekran� Temizle	
	}
			
	else if(AnaEkranModu != "1") // Kullan�c�dan "1" Almazsan A��a��daki Sat�rlar� Y�r�t.
	{
		cout<<endl; // 1 Sat�r A��a�� Ge�
		cout<<"  Hatal� Se�im ! L�tfen Yeniden Denemek i�in ENTER'� Tu�lay�n�z."<<endl; // Kullan�c�ya �kaz Bildirilmesi
		getch(); // Karakter Girilene Kadar Bekle
		cout<<endl; // 1 Sat�r Alta Ge�ir	
		for(int P=0; P<80; P++) // 50 Defa �al��an Bir D�ng�
		{
			cout<<"*"; // Ekrana Yan Yana * Karakterini Bas
			Sleep(10); // Ekran� 10ms Beklet (Gecikme S�resi)	
		}
		cout<<endl; // Ekran� 1 Sat�r Alta Ge�ir
		system("cls"); // Ekran� Temizle
		gotoxy(0,0); // Girilen Noktaya Haraket Et
		cout<<"## Tekrar �al��t�rmak ��in 1 Tu�lay�n�z ... "<<endl<<endl; // Kullan�c�ya �kaz Bildirilmesi
	    cout<<"## Tu�lanan Say� : "; // Kullan�c�ya �kaz Bildirilmesi
	    cin>>AnaEkranModu; // Kullan�c�dan �nput Al
	    system("cls"); // Ekran� Temizle
	}
}
}

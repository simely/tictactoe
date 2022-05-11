#include <stdio.h>

char kutu[10] = {'o','1','2','3','4','5','6','7','8','9'};
char oyuncu1[50], oyuncu2[50];

void tahtayiBastir() {
	
	// Oyun tahtas�n� yazd�r�r.
	
    printf("\n\t\t\t      ---TIC TAC TOE---\n\n");
    printf("%s : X\t\t\t\t\t\t\t    %s : O\n",oyuncu1, oyuncu2);
    printf("\n\t\t\t         |         |         ");
    printf("\n\t\t\t    %c    |    %c    |    %c   ",kutu[1],kutu[2],kutu[3]);
    printf("\n\t\t\t         |         |         ");
    printf("\n\t\t\t---------|---------|---------");
    printf("\n\t\t\t         |         |         ");
    printf("\n\t\t\t    %c    |    %c    |    %c   ",kutu[4],kutu[5],kutu[6]);
    printf("\n\t\t\t         |         |         ");
    printf("\n\t\t\t---------|---------|---------");
    printf("\n\t\t\t         |         |         ");
    printf("\n\t\t\t    %c    |    %c    |    %c   ",kutu[7],kutu[8],kutu[9]);
    printf("\n\t\t\t         |         |         ");
}

int oyunBaslat() {
	
	int oyuncu = 1, i, secim;
	char isaret;
	
	printf("1.Oyuncu : ");
	scanf("%s",oyuncu1);
	printf("2.Oyuncu : ");
	scanf("%s",oyuncu2);

	do {
		
		tahtayiBastir();
		
		oyuncu = (oyuncu % 2) ? 1 : 2;  // oyuncu de�i�keninin de�erinin 2 ile b�l�m�nden kalan varsa oyuncu = 1 de�erini al�r, yoksa oyuncu = 2 de�erini al�r.
		
		if(oyuncu == 1) {
		    printf("\n\n%s bir numara sec : ",oyuncu1);
		    scanf("%d",&secim);
		}
		
		else if(oyuncu == 2) {
		    printf("\n\n%s bir numara sec : ",oyuncu2);
	 	    scanf("%d",&secim);
		}
			
		isaret = (oyuncu == 1) ? 'X' : 'O';
		
		// Girilen say�n�n oldu�u kutuda girilen say� karakteri varsa yani X veya O yoksa hangi oyuncunun hamlesi oldu�una ba�l� olarak X veya O yerle�tirilir.
			
	    if(secim == 1 && kutu[1] == '1')
			kutu[1] = isaret;
			   
		else if(secim == 2 && kutu[2] == '2')
			kutu[2] = isaret;
			   
		else if(secim == 3 && kutu[3] == '3')
			kutu[3] = isaret;
			   
		else if(secim == 4 && kutu[4] == '4')
			kutu[4] = isaret;
			   
		else if(secim == 5 && kutu[5] == '5')
			kutu[5] = isaret;
			   
		else if(secim == 6 && kutu[6] == '6')
			kutu[6] = isaret;
			   
		else if(secim == 7 && kutu[7] == '7')
			kutu[7] = isaret;
			   
		else if(secim == 8 && kutu[8] == '8')
			kutu[8] = isaret;
			   
		else if(secim == 9 && kutu[9] == '9')
			kutu[9] = isaret;
			   
			else {
			   printf("\n>> HATALI SECIM!\n>> DOGRU SAYI GIRDIGINIZDEN EMIN OLUN!\n");
			   
			   oyuncu--;  // Hatal� se�im yap�ld���nda ayn� oyuncunun tekrar oynayabilmesi i�in oyuncu de�i�keni 1 azalt�l�r.
		}
		
		i = kazananKontrol();
		
		oyuncu++;  // S�radaki oyuncuya ge�mek i�in oyuncu de�i�keni 1 artt�r�l�r.
}

    while(i == -1);
    
    tahtayiBastir();
    
		if(i == 1 && oyuncu - 1 == 1)
		    printf("\n>> %s OYUNU KAZANDI",oyuncu1);
		    
		else if(i == 1 && oyuncu - 1 == 2)
		    printf("\n>> %s OYUNU KAZANDI",oyuncu2);
		    
		else if(i == 0)
		    printf("\n>> BERABERE");
}

int kazananKontrol() {
	
	// Oyunun durumuna g�re return 1 oyunun kazananla sonu�land���n�, 0 berabere bitti�ini, -1 oyunun devam etti�ini g�sterir.
	
	if(kutu[1] == kutu[2] && kutu[2] == kutu[3])
	    return 1;
	    
	else if(kutu[4] == kutu[5] && kutu[5] == kutu[6])
	    return 1;
	    
	else if(kutu[7] == kutu[8] && kutu[8] == kutu[9])
	    return 1;
	    
	else if(kutu[1] == kutu[4] && kutu[4] == kutu[7])
	    return 1;
	    
	else if(kutu[2] == kutu[5] && kutu[5] == kutu[8])
	    return 1;

	else if(kutu[3] == kutu[6] && kutu[6] == kutu[9])
	    return 1;
	    
	else if(kutu[1] == kutu[5] && kutu[5] == kutu[9])
	    return 1;
	    
	else if(kutu[3] == kutu[5] && kutu[5] == kutu[7])
	    return 1;
	    
	else if(kutu[1] != '1' && kutu[2] != '2' && kutu[3] != '3' && kutu[4] != '4' && kutu[5] != '5' && kutu[6] != '6' && kutu[7] != '7' && kutu[8] != '8' && kutu[9] != '9')
	    return 0;   // T�m kutular�n X veya O ile i�aretlendi�ini ama kazanma durumunun olmad���n� g�sterir.
	    
	else
	    return -1;
}

void tahtaReset() {
	
	// Oyun tahtas�n� s�f�rlar.
	
	kutu[1] = '1', kutu[2] = '2', kutu[3] = '3', kutu[4] = '4', kutu[5] = '5', kutu[6] = '6', kutu[7] = '7', kutu[8] = '8', kutu[9] = '9';
}

int main() {
	
	oyunBaslat();
	
	char tekrar;
	
	printf("\nTekrar oynamak ister misiniz? (E/H) : ");
	scanf("%s",&tekrar);
	
	if(tekrar == 'E') {
		
		do {
			
		    tahtaReset();
		    oyunBaslat();
		
            printf("\nTekrar oynamak ister misiniz? (E/H) : ");
	        scanf("%s",&tekrar);
} 

    while(tekrar == 'E');

}

    else if(tekrar == 'H')
      printf("IYI GUNLER :)");
		    
    return 0;
}

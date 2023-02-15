#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *temp = NULL;


void sonaEkle(int veri){
	struct node *eklenecek = (struct node*)malloc(sizeof(struct node));
	eklenecek->data = veri;
	eklenecek->next = NULL;
	
	if(start == NULL){
		start = eklenecek;
	}
	
	else{
		temp = start;
		
		while(temp->next != NULL){
			temp = temp->next;
		}
		
		temp->next = eklenecek;	
	}
}

void basaEkle(int basa){
	struct node *basaGelecek = (struct node*)malloc(sizeof(struct node));
	
	basaGelecek -> data = basa;
	basaGelecek -> next = start;
	start = basaGelecek;
	
}

void oncekiArayaEkle(int eklenecekDeger, int arananDeger){
	struct node *arayaEklenecek = (node*)malloc(sizeof(node));
		
		arayaEklenecek->data = eklenecekDeger;
		
		temp = start;
		while(temp->next->data != arananDeger){
			temp = temp->next;
		}
		struct node *onceki = (node*)malloc(sizeof(node));
		onceki = temp->next;
		temp->next = arayaEklenecek;
		arayaEklenecek->next = onceki;	

}

void sonrakiArayaEkle(int eklenecekDeger, int arananDeger){
	
	struct node *sonrakiArayaEkle = (struct node*)malloc(sizeof(node));
	sonrakiArayaEkle->data = eklenecekDeger;
	
	temp = start;
	
	while(temp->next->data != arananDeger){
		temp = temp->next;
	}
	temp = temp->next;

	struct node *sonraki = (struct node*)malloc(sizeof(node));

	sonraki = temp->next;
	temp->next = sonrakiArayaEkle;
	sonrakiArayaEkle->next = sonraki;
}

void sondanSil(){
	if(start == NULL){
		printf("Hic Dugum Yok Zaten!"); 
	}									
	else{
		temp = start;
	//Sondan bir önceki eleman  bulunur
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		free(temp->next); 
		temp->next = NULL;
	}
}

void bastanSil(){
	struct node *ikinci = NULL;
	ikinci = start->next;
	free(start);
	start = ikinci;
}

void aradanSil(int silinecek){
	  if(start->data == silinecek){
	  	bastanSil();
	  }
	 else{
	 	temp = start;
	 	
	 	while(temp->next->data != silinecek){
	 		temp = temp->next;
		 }
		 if(temp->next == NULL){
		 	sondanSil();
		 }
		 else{
		 	struct node *onceki = NULL;
		 	struct node *sonraki = NULL;
		 	
		 	onceki = temp;
		 	sonraki = temp->next->next;
		 	free(temp->next);
		 	onceki->next = sonraki;
		 }
	 }
}



void yazdir(){
	temp = start;
	
	while(temp->next != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("%d -> ",temp->data);
}


int main(){
	
	int secenek, i=1, donguSayisi, eklenecek, aranan, sil;
	int son,bas;
	
	printf("Dongu Sayisi Giriniz:  ");
	scanf("%d",&donguSayisi);
	
	while(i<=donguSayisi){
		
		printf("\n1- Basa Ekleme:");
		printf("\n2- Sona Ekleme:");
		printf("\n3- Aranandan(onceki) Ekleme:");
		printf("\n4- Aranandan(sonraki) Ekleme:");
		printf("\n5- Sondan Node Silme:");
		printf("\n6- Bastan Node Silme:");
		printf("\n7- Aradan Node Silme:");
		printf("\nYapmak istediginiz islemi giriniz: ");
		scanf("%d",&secenek);
	
	
		switch(secenek){
			case 1:
				printf("Hangi Sayiyi Basa Eklemek Istersiniz: ");
				scanf("%d",&bas);
				basaEkle(bas);
				yazdir();
				break;	
			case 2:
				printf("Hangi Sayiyi Sona Eklemek Istersiniz: ");
				scanf("%d",&son);
				sonaEkle(son);
				yazdir();
				break;
			case 3:
				printf("Araya Eklenecek Elemani Giriniz: ");
				scanf("%d",&eklenecek);
				printf("Hangi Elemandan Once Eklenecek: ");
				scanf("%d",&aranan);
				
				oncekiArayaEkle(eklenecek, aranan);
				yazdir();
				break;
			case 4:
				printf("Araya Eklenecek Elemani Giriniz: ");
				scanf("%d",&eklenecek);
				printf("Hangi Elemandan Sonra Eklenecek: ");
				scanf("%d",&aranan);
				
				sonrakiArayaEkle(eklenecek, aranan);
				yazdir();
				break;
			case 5:
				sondanSil();
				yazdir();
				break;
		
			case 6:
				bastanSil();
				yazdir();
				break;
		
			case 7:
				printf("Silinecek Veriyi Giriniz: ");
				scanf("%d", &sil);
				aradanSil(sil);
				yazdir();
		}
		i++;
	}
}










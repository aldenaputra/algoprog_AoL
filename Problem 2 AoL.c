#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
	char name[15];
	char phone[14];
	char address[30];
};

struct data teman[8];

void dataArchive()
{
	strcpy(teman[0].name, "Dini Noviani");
	strcpy(teman[0].phone, "081225224336");
	strcpy(teman[0].address, "Pekalongan, Jawa Tengah");
	
	strcpy(teman[1].name, "Dini Maryati");
	strcpy(teman[1].phone, "081225224337");
	strcpy(teman[1].address, "Semarang, Jawa Tengah");
	
	strcpy(teman[2].name, "Fahri");
	strcpy(teman[2].phone, "081225224338");
	strcpy(teman[2].address, "Jayapura, Papua");
	
	strcpy(teman[3].name, "Fahrur");
	strcpy(teman[3].phone, "081227224336");
	strcpy(teman[3].address, "Sintang, Kalimantan Barat");
	
	strcpy(teman[4].name, "Zafir");
	strcpy(teman[4].phone, "081235294339");
	strcpy(teman[4].address, "Samarinda, Kalimantan Timur");
	
	strcpy(teman[5].name, "Ruben");
	strcpy(teman[5].phone, "081205220336");
	strcpy(teman[5].address, "Malang, Jawa Timur");
	
	strcpy(teman[6].name, "Tria");
	strcpy(teman[6].phone, "081225224336");
	strcpy(teman[6].address, "Bandung, Jawa Barat");
}

int main()
{
	dataArchive();
	
	char search[15] = {};
	printf("Attention! Please be aware of case sensitivity!\n");
	printf("Search Data: ");
	scanf("%[^\n]", search);
	
	int len_search = strlen(search);
	int i, j;	
	printf("\n|NAME\t\t|PHONE\t\t|ADDRESS\n");
	
	int cekPair, flag, not_exist = 0;
	int last = 0;
	for(i = 0; i < 7; i++)
	{
		flag = 0;
		cekPair = 0;
		if(len_search > 1)
		{
			flag = 1;
			for(j = 0; j < strlen(teman[i].name) - 1; j++)
			{
				if(teman[i].name[j] == search[cekPair] && teman[i].name[j + 1] == search[cekPair + 1])
				{
					cekPair++;
				}
			}
			
			if(cekPair == len_search - 1)
			{
				printf("|%-15s|%-15s|%s\n", teman[i].name, teman[i].phone, teman[i].address);
			}
			else
			{
				not_exist++;
			}
		}
		
		else
		{
			j = 0;
			do
			{
				if(teman[i].name[j] == search[0])
				{
					flag = 1;
				}
				j++;
			}
			while(j < strlen(teman[i].name) && flag != 1);
			
			if(flag == 1)
			{
				last = 1;
				printf("|%-15s|%-15s|%s\n", teman[i].name, teman[i].phone, teman[i].address);
			}
		}
	}
	
//	printf("%d %d %d\n", not_exist, flag, last);
	if((not_exist == 7 || flag == 0) && last == 0)
	{
		printf("|Data Not Exist\n");
	}
	return 0;
}

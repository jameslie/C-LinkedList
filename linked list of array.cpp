#include <iostream>
#define true 1
#define false 0

using namespace std;

typedef struct 
{
	int info;
	int next; 
}typenode;

typenode elemen[100];
int list = 0,akhirlist,kosong = 0,akhirkosong;
int listkosong();
void buatnodebaru();
void sisipnode(int IB);
void cetaklist();

int banyak, bantu, nilai;
int main()
{
	int pilih;
	
	do
	{
		cetaklist();
		
		cout << "1. BUAT LIST BARU\n2. SISIP NODE\n3. HAPUS NODE\n4. CARI NODE\n5. EXIT\n";
		cout << "PILIHAN : ";
		cin >> pilih;
		
		switch(pilih)
		{
			case 1:
				cout << "===BUAT NODE BARU !!!===" << endl;
				buatnodebaru();
			break;
			case 2:
				cout << "===SISIP NODE !!!===" << endl;
				cout << "Masukan Nilai yang Mau di sisip : ";
				cin >> nilai;
				sisipnode(nilai);
			break;
			case 3:
				
			break;
			case 4:
			
			break;
			case 5:
				return 0;
			break;
			default:
				cout << "PILIHAN YANG ANDA MASUKAN SALAH !!!" << endl;
			break;
		}
	}
	while(pilih != 5);
}

int listkosong()
{
	if (list==0)
		return(true);
	else
		return(false);
}

void buatnodebaru()
{
	cout << "Masukan banyak list : ";
	cin >> banyak;
				
	for(int i = 1; i <= banyak; i++)
	{
		cout << "List ke - " << i << " : ";
		cin >> elemen[i].info;
		
		if(elemen[i].info != 0)
		{
			if(i == 1)
			{
				list = i;
				akhirlist = i;
				elemen[akhirlist].next = 0;
			}
			else if(elemen[i].info < elemen[list].info)
			{
				elemen[i].next = list;
				akhirlist = list;
				list = i;
				elemen[akhirlist].next = 0;
			}
			else
			{
				//sissipakhir
				if(elemen[i].info > elemen[akhirlist].info)
				{
					bantu = akhirlist;
					elemen[bantu].next = i;
					akhirlist = i;
					elemen[akhirlist].next = 0;
				}
				else
				{
					bantu = list;
					//sisiptengah
					while(elemen[i].info > elemen[bantu].info && elemen[bantu].next != akhirlist)
					bantu = elemen[bantu].next;
					
					elemen[i].next = elemen[bantu].next;
					elemen[bantu].next = i;
				}
			}
		}
		else
		{
			elemen[i].next = kosong;
			if(elemen[i].next == 0)
			{
				akhirkosong = i;
				kosong = i;
			}
			else
			{
				kosong = i;
			}
		}
	}
	cout << endl;
}
int misal = banyak; 
void sisipnode(int IB)
{
	int listbaru, k, m, n, x;
	
	if(listkosong())
	{
		elemen[kosong].info = IB;
		listbaru = elemen[kosong].next;
		elemen[kosong].next = 0;
		akhirlist = kosong;
		list = kosong;
		kosong = bantu;
	}
	else
	{
		if(IB < elemen[list].info)
		{
			listbaru = kosong;
			elemen[listbaru].info = IB;
			elemen[listbaru].next = list;
			list = listbaru;
		}
		else if(IB > elemen[akhirlist].info)
		{
			listbaru=kosong; 
			kosong=elemen[kosong].next;
			elemen[listbaru].info=IB;
			elemen[listbaru].next=0;
			elemen[akhirlist].next=listbaru;
			akhirlist=listbaru; 
		}
		else
		{
			n=list;
			x=elemen[n].info;
			while(IB>x)
			{
				m=n;
				n=elemen[n].next;
				x=elemen[n].info;
			}
			k=elemen[kosong].next;
			elemen[m].next=kosong;
			elemen[kosong].info=IB;
			elemen[kosong].next=n;
			kosong=k;
		}
	}
}

void cetaklist()
{
	int n,m;
	n=list;
	m=kosong;
	cout << "isi list : \n";
	
	if(misal <= 1)
	{
		cout << elemen[list].info;
		
		cout << "\nIndex tempat-tempat kosong: \n";
		if(m == 0)
		{
			cout << " ";
			cout << endl;
		}
		else
		{
			do
			{
				cout << m << " ";
				m=elemen[m].next;
			}
			while(elemen[m].next!=0);
			cout << " " << akhirkosong;
			cout << endl;
        }
	}
	else
	{
		do
		{
			cout << elemen[n].info << " ";
			n=elemen[n].next;
		}
		while (elemen[n].next!=0);
		cout << " "<< elemen[akhirlist].info <<endl ;
		
		cout << "\nIndex tempat-tempat kosong: \n";
		if(elemen[m].next == 0)
		{
			cout << " ";
			cout << endl;
		}
		else
		{
			do
			{
				cout << m << " ";
				m=elemen[m].next;
			}
			while(elemen[m].next!=0);
			cout << " " << akhirkosong;
			cout << endl;
        }
	}
}

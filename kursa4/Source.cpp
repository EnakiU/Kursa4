
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<Windows.h>

using namespace std;
int n1 = 0,n2=0;

struct Deque
{
	struct Deque1 *deq;
	struct Deque *sled;
};

struct Deque1
{
	char f;
	struct Deque1 *prv;
	struct Deque1 *nxt;
	
};

int proverka(char p[100])
{
	int flag = 1, i = 0;
	while (p[i] == ' ')
		i++;
	for (; (p[i] != '\0') && (flag == 1); i++)
	{
		if (!isdigit(p[i]))
			flag = 0;
	}
	return flag;
}


void listprint(struct Deque1 *hight, struct Deque1 *doelementa)
{
	n2 = 0;
	struct Deque1 *h, *g;
	h = hight;
	if ((hight != doelementa))
		g = doelementa;

	else g = h;
	if (doelementa->prv == hight)
		g = doelementa;
	cout << "\n     ������ �������:  ";
	if (hight != doelementa)
	{
		while (h != doelementa)
		{

			if (h->f != '/0')
			{
				cout << h->f << "  ";
				n2++;
			}
			else
				printf("\n������ �����\n");

			h = h->nxt;

		}

	}
	if (h->f != '/0')
	{
		cout << h->f << "  ";
		n2++;
	}
	cout << endl;
	cout << "\n   �������� �������:  ";
	if (hight != doelementa)
	{

		while (g != hight)
		{
			if (g->f != '/0')
			{
				cout << g->f << "  ";
			}
			else
				printf("\n������ �����\n");

			g = g->prv;
		}
	}


	if (g->f != '/0')
	{
		cout << g->f << "  ";
	}
	else
		printf("\n������ �����\n");
	printf("\n");
}
void prv(struct Deque1 *hight, struct Deque1 *doelementa)
{
	n2 = 0;
	struct Deque1 *h, *g;
	h = hight;
	if ((hight != doelementa))
		g = doelementa;

	else g = h;
	if (doelementa->prv == hight)
		g = doelementa;
	//cout << "\n     ������ �������:  ";
	if (hight != doelementa)
	{
		while (h != doelementa)
		{

			if (h->f != '/0')
			{
				//cout << h->f << "  ";
				n2++;
			}
			else
				printf("\n������ �����\n");

			h = h->nxt;

		}

	}
	if (h->f != '/0')
	{
		//cout << h->f << "  ";
		n2++;
	}
	//cout << endl;
	//cout << "\n   �������� �������:  ";
	if (hight != doelementa)
	{

		while (g != hight)
		{
			if (g->f != '/0')
			{
				//cout << g->f << "  ";
			}
			else
				printf("\n������ �����\n");

			g = g->prv;
		}
	}


	if (g->f != '/0')
	{
		//cout << g->f << "  ";
	}
	else
		printf("\n������ �����\n");
	printf("\n");
}

Deque1 * AddL(Deque1 *nach, char c) //���������� �������� � ������

{
	struct Deque1 * neww = NULL;
	neww = (struct Deque1*) malloc(sizeof(struct Deque1));
	if (neww == NULL)
	{
		printf("\n������. ������ �� ����������\n");
		exit;
	}

	neww->prv = NULL;
	neww->nxt = nach;
	nach->prv = neww;
	nach = neww;
	nach->f = c;
	return nach;
}

Deque1 * AddR(Deque1 *konec, char c) //���������� �������� � �����

{
	struct Deque1 * neww = NULL;
	neww = (struct Deque1*) malloc(sizeof(struct Deque1));
	if (neww == NULL)
	{
		printf("\n������. ������ �� ����������\n");
		exit;
	}
	neww->nxt = NULL;
	neww->prv = konec;
	neww->f = '\0';
	konec->nxt = neww;
	neww->f = c;
	return neww;
}

int pustota(struct Deque1 * nach)
{
	int flag = 0;
	if (nach == NULL || (nach->f == '\0' && nach->nxt == NULL && nach->prv == NULL))
		flag = 1;
	return flag;
}


struct Deque1 * clean(struct Deque1 *p)
{
	struct Deque1 *k;
	if (p != NULL)
		while (p->nxt != NULL)
		{
			k = p;
			p = p->nxt;
			k->f = '\0';
			free(k);
			k = NULL;
			p->f = '\0';
		}
	//p->f = '\0';
	free(p);
	p = NULL;
	return p;
}

struct Deque1 * deletL(struct Deque1 * nach)
{
	struct Deque1 *del;
	del = nach;
	if (nach->nxt != NULL)
		nach = nach->nxt;
	else nach = NULL;
	free(del);
	return nach;
}

struct Deque1 * deletR(struct Deque1 * konec, struct Deque1 * nach)
{
	struct Deque1 *del;
	if (nach != konec)
	{
		while (nach->nxt != konec)
		{

			nach = nach->nxt;
		}

		del = nach->nxt;
		nach->nxt = NULL;
	}
	else
	{
		del = nach;
		nach = NULL;
	}
	free(del);
	return nach;
}

struct Deque1 * vzatL(struct Deque1 *nach)
{
	char vzatiy = nach->f;
	nach = deletL(nach);
	printf("\n������ ���: \n");
	cout << vzatiy << endl;
	return nach;

}

struct Deque1 * vzatR(struct Deque1 *konec, struct Deque1 *nach)
{
	char vzatiy = nach->f;
	konec = deletR(konec, nach);
	printf("\n������ �������: \n");
	cout << vzatiy << endl;
	return konec;

}

void listprint(struct Deque1 *hight)
{
	
	struct Deque1 *h;
	h = hight;
	if (h != NULL)
		if (h->f == '\0')
			printf("������ �����");
	while (h->nxt != NULL)
	{

		if (h->f != '/0')
			cout << h->f << "  ";
		else
			printf("������ �����\n");
		h = h->nxt;

	}

	if (h->f != '/0')
		cout << h->f << "  ";
	else
		printf("������ �����\n");

	printf("\n");
}




//---------------------------------------------------------------------------------------------------------------------------------------
Deque * menu2(Deque * K) //������� �������
{

	int flag = 0;
	int number = 0;

	char p[100];

	struct Deque1 *bilo = NULL;
	struct Deque1 *nach = K->deq;
	struct Deque1 *konec = NULL;
	if (nach != NULL)

		if (nach->nxt != NULL)
		{
			konec = nach;
			while (konec->nxt != NULL)
			{
				konec = konec->nxt;
			}
		}
		else
			konec = nach;

	Deque1 D;

	int  zahod;
	
	do
	{
		cout << "\n1. ������ ������ � �����" << endl;
		cout << "2. ������� ��� ������" << endl;
		cout << "3. ��������: ��� ���� / �� ����" << endl;
		cout << "4. ������� ������ �������" << endl;
		cout << "5. ������� ��������� �������" << endl;
		cout << "6. ������� ������ �������" << endl;
		cout << "7. ������� ��������� �������" << endl;
		cout << "8. ����� ������ �������" << endl;
		cout << "9. ����� ��������� �������" << endl;
		cout << "10. �������� ������ �������" << endl;
		cout << "11. �������� ��������� �������" << endl;
		cout << "12. �������� ������� � ������" << endl;
		cout << "13. �������� ������� � �����" << endl;
		cout << "14. ������� ��� ��������" << endl;
		cout << "15. ��������� ������ � �����" << endl;
		cout << "����� ������� > ";
		cin >> p;
		cout << endl;

		if (proverka(p))
		{
			number = atoi(p);
			if ((number < 16) && (number >= 1))
			{
				if ((number == 1))
				{
					if (flag)
						cout << "\n!������ � ����� ��� ������!\n";
					else
						cout << endl << "�� ������ ������!" << endl;
					flag = 1;

					if (nach == NULL)
					{
						nach = (struct Deque1*)malloc(sizeof(struct Deque1));
						if (nach == NULL)
						{
							printf("\n!������:������ �� ����������!\n");
							exit;
						}
						nach->f = '\0';
						nach->nxt = NULL;
						nach->prv = NULL;

						zahod = 1;

						konec = nach;
					}
					prv(nach, konec);
					
				}

				if ((flag == 1)) {
					if (number < 10 && number>1 && !pustota(nach))
					{
						printf("\n��������� ��� ��:\n");
						listprint(nach, konec);
					}




					//-----------------------------------------------
					if (!pustota(nach))
						zahod = 0;
					else zahod = 1;
					switch (number)  // ������� �������� �� ������ ������ �� �������
					{
					case 2:
					{  if (pustota(nach))
						printf("\n��� ����. ������� 12 ��� 13 \n");
					else
					{
						nach = clean(nach);



						printf("\n��� ������\n");
						zahod = 1;

						nach = (struct Deque1*)malloc(sizeof(struct Deque1));
						if (nach == NULL)
						{
							printf("\n������! ������ �� ����������!\n");
							exit;
						}

						konec = nach;
						nach->nxt = NULL;
						nach->prv = NULL;
						nach->f = '\0';
						zahod = 1;
					}
					n2 = 0;
					break; }

					//-----------------------------------------------
					case 3: {  if (pustota(nach))
						printf("\n��� ����\n");
							else
						printf("\n��� �� ����\n");
						break; }
							break;
							//-----------------------------------------------
					case 4:
					{ if (pustota(nach))
						printf("\n��� ������ ������� 12 ��� 13\n");
					else
					{
						cout << "\n������ �������: ";
						cout << nach->f << endl;
					}
					break; }

					//-----------------------------------------------
					case 5:
					{ if (pustota(nach))
						printf("\n��� ���� ������� 12 ��� 13\n");
					else
					{
						cout << "\n��������� �������: ";
						cout << konec->f << endl;
					}
					break; }

					//-----------------------------------------------
					case 6:
					{  if (pustota(nach))
						printf("\n ��� ���� ������� 12 ��� 13\n");
					else
						nach = deletL(nach);

					if (nach == NULL)
					{
						zahod = 1;
						nach = (struct Deque1*)malloc(sizeof(struct Deque1));
						if (nach == NULL)
						{
							printf("\n������:������ �� ����������!\n");
							exit;
						}
						nach->nxt = NULL;
						nach->prv = NULL;
						nach->f = '\0';
						konec = nach;
					}
					n2--;
					break; }
					//-----------------------------------------------
					case 7:
					{  if (pustota(nach))
						printf("\n ��� ���� ������� 12 ��� 13\n");
					else
						konec = deletR(konec, nach);

					if (konec == NULL)
					{
						zahod = 1;
						konec = (struct Deque1*)malloc(sizeof(struct Deque1));
						if (konec == NULL)
						{
							printf("\n������:������ �� ����������!\n");
							exit;
						}
						konec->nxt = NULL;
						konec->prv = NULL;
						konec->f = '\0';

						nach = konec;
					}
					n2--;
					break; }

					//-----------------------------------------------
					case 8:
					{  if (pustota(nach))
						printf("\n ��� ���� ������� 12 ��� 13\n");
					else
						nach = vzatL(nach);
					if (nach == NULL)
					{
						zahod = 1;
						nach = (struct Deque1*)malloc(sizeof(struct Deque1));
						if (nach == NULL)
						{
							printf("\n������:������ �� ����������!\n");
							exit;
						}
						nach->nxt = NULL;
						nach->prv = NULL;
						nach->f = '\0';
						konec = nach;
					}
					n2--;
					break; }
					//-----------------------------------------------
					case 9:
					{  if (pustota(nach))
						printf("\n ��� ���� ������� 12 ��� 13\n");
					else
						konec = vzatR(konec, nach);

					if (konec == NULL)
					{
						zahod = 1;
						konec = (struct Deque1*)malloc(sizeof(struct Deque1));
						if (konec == NULL)
						{
							printf("\n������:������ �� ����������!\n");
							exit;
						}
						konec->nxt = NULL;
						konec->prv = NULL;
						konec->f = '\0';
						nach = konec;
					}
					n2--;
					break; }

					//-----------------------------------------------
					case 10: {  if (pustota(nach))
						printf("\n ��� ���� ������� 12 ��� 13\n");
							 
					else
					{
					char c;
					cout << "\n������� ������ �������\n";
					cin >> c;
					printf("\n��������� ��� ��\n");
					listprint(nach, konec);
					nach->f = c;

					}
							 break; }

							 //-----------------------------------------------
					case 11:
					{  if (pustota(nach))
						printf("\n��� ���� ������� 12 ��� 13\n");
					else
					{
						char c;
						cout << "\n������� ������ �������\n";
						cin >> c;
						printf("\n��������� ��� ��\n");
						listprint(nach, konec);
						konec->f = c;
						
					}

					break; }

					//-----------------------------------------------
					case 12:
					{ 
						if (n2 < 5)
						{
							if (zahod)
							{
								char c;
								cout << "\n������� ����� �������\n";
								cin >> c;
								nach->f = c;
								printf("\n��������� ��� ��� ����\n");
								zahod = 0;
							}
							else
							{
								char c;
								bilo = (struct Deque1*)malloc(sizeof(struct Deque1));
								if (bilo == NULL)
								{
									printf("\n������:������ �� ����������!\n");
									exit;
								}
								cout << "\n������� ����� �������\n";
								cin >> c;
								*bilo = *nach;
								bilo->f = nach->f;
								printf("\n��������� ��� ��\n");

								listprint(nach, konec);
								nach = AddL(nach, c);


							}
							n2++;
						}
						else
							cout << "!�� �������� �������!" << endl;
					break; }
					//-----------------------------------------------
					case 13: { 
						if (n2 < 5)
						{
							if (zahod)
							{
								char c;
								cout << "\n������� ����� �������\n";
								cin >> c;
								nach->f = c;
								printf("\n��������� ��� ��� ����\n");
								zahod = 0;
							}
							else
							{
								char c;
								cout << "\n������� ����� �������\n";
								cin >> c;
								printf("\n��������� ��� ��\n");
								listprint(nach, konec);
								konec = AddR(konec, c);

							}
							n2++;
						}
						else
							cout << "!�� �������� �������!" << endl;
							 break; }

							 //-----------------------------------------------

					case 14:
					{  if (pustota(nach))
						printf("\n��� ���� ������� 12 ��� 13\n");
					else
						listprint(nach, konec);
					break; }

					case 15:
					{ flag = 0;
					//                        if (nach!=NULL) {
					//                        nach = clean (nach);
					//                        printf("\n��� ������\n");
					//                        }
					break;
					}

					//-----------------------------------------------


					}
					if (number < 14 && number >3 && !pustota(nach))
					{
						printf("\n��������� ��� �����:\n");
						listprint(nach, konec);
					}
					if (number < 10 && number >7 && pustota(nach))
					{

						printf("\n��� ����\n");

					}
					//                             if((number == 10 || number == 11) && pustota(nach))
					//                             { printf("\n��������� ��� �����:\n");
					//                                 listprint(nach);
					//                             }

				}


				else
					if ((number != 1))
						printf("\n������� ������ � �����\n");
			}
			else
				printf("\n������������ ����\n");
		}
		else
			printf("\n������������ ����\n");




	} while (number != 15);
	K->deq = nach;
	return K;
}

//---------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------------------------------------


#include <iostream>




void listprint(struct Deque *hight, struct Deque *doelementa)
{
	struct Deque *h;
	h = hight;
	int i = 1;
	printf("\n");

	if (hight != doelementa)
	{
		while (h->sled != doelementa)
		{
			printf("%d: ", i);
			if (h->deq != NULL)
				listprint(h->deq);
			else
				printf("\n������ �����\n");
			printf("\n");
			h = h->sled;
			i++;
		}
	}
	printf("%d: ", i);
	if (h->deq != NULL)
		listprint(h->deq);
	else
		printf("\n������ �����\n");
	printf("\n");
}

Deque * AddL(Deque *nach) //���������� �������� � ������

{
	struct Deque * neww = NULL;
	neww = (struct Deque*) malloc(sizeof(struct Deque));
	if (neww == NULL)
	{
		printf("\n������. ������ �� ����������\n");
		exit;
	}

	neww->deq = NULL;
	neww->sled = nach;
	nach = neww;
	neww = menu2(neww);
	return nach;
}

Deque * AddR(Deque *konec) //���������� �������� � �����

{
	struct Deque * neww = NULL;
	neww = (struct Deque*) malloc(sizeof(struct Deque));
	if (neww == NULL)
	{
		printf("\n������. ������ �� ����������\n");
		exit;
	}
	neww->sled = NULL;
	neww->deq = NULL;
	konec->sled = neww;
	neww = menu2(neww);
	return neww;
}

int pustota(struct Deque * nach)
{
	int flag = 0;
	if (nach == NULL || (nach->deq == NULL && nach->sled == NULL))
		flag = 1;
	return flag;
}


struct Deque * clean(struct Deque *p)
{
	struct Deque *k;
	if (p != NULL)
		while (p->sled != NULL)
		{
			k = p;
			p = p->sled;
			k->deq = clean(k->deq);
			free(k);
			k = NULL;
		}
	p->deq = clean(p->deq);
	free(p);
	p = NULL;
	return p;
}

struct Deque * deletL(struct Deque * nach)
{
	struct Deque *del;
	del = nach;
	if (nach->sled != NULL)
		nach = nach->sled;
	else nach = NULL;
	free(del);
	return nach;
}

struct Deque * deletR(struct Deque * konec, struct Deque * nach)
{
	struct Deque *del;
	if (nach != konec) {
		while (nach->sled != konec) {

			nach = nach->sled;
		}

		del = nach->sled;
		nach->sled = NULL;
	}
	else {
		del = nach;
		nach = NULL;
	}
	free(del);
	return nach;
}

struct Deque * vzatL(struct Deque *nach)
{
	struct Deque1 * vzatiy = nach->deq;
	nach = deletL(nach);
	printf("\n������ �������: \n");
	listprint(vzatiy);
	return nach;

}

struct Deque * vzatR(struct Deque *konec, struct Deque *nach)
{
	struct Deque1 * vzatiy = konec->deq;
	konec = deletR(konec, nach);
	printf("\n������ ���: \n");
	listprint(vzatiy);
	return konec;

}

void listprint(struct Deque *hight)
{
	struct Deque *h;
	h = hight;
	int i = 1;
	printf("\n");
	while (h->sled != NULL)
	{
		printf("%d: ", i);
		if (h->deq != NULL)
			listprint(h->deq);
		else
			printf("������ �����\n");
		printf("\n");
		h = h->sled;
		i++;
	}
	printf("%d: ", i);
	if (h->deq != NULL)
		listprint(h->deq);
		
	else
		printf("������ �����\n");
	
	printf("\n");
}




//---------------------------------------------------------------------------------------------------------------------------------------
int main() //������� �������
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int flag = 0;
	int number = 0;

	char p[100];

	struct Deque *bilo = NULL;
	struct Deque *nach = NULL;
	struct Deque *konec = NULL;

	Deque D;

	int  zahod;
	do
	{
		cout << "\n1. ������ ������ � ����� �����" << endl;
		cout << "2. ������� ��� ������" << endl;
		cout << "3. ��������: ��� ���� / �� ����" << endl;
		cout << "4. ������� ������ ���������� ���" << endl;
		cout << "5. ������� ��������� ���������� ���" << endl;
		cout << "6. ������� ������ ���������� ���" << endl;
		cout << "7. ������� ��������� ���������� ���" << endl;
		cout << "8. ����� ������ ���������� ���" << endl;
		cout << "9. ����� ��������� ���������� ���" << endl;
		cout << "10. �������� ������ ���������� ���" << endl;
		cout << "11. �������� ��������� ���������� ���" << endl;
		cout << "12. �������� ���������� ��� � ������" << endl;
		cout << "13. �������� ���������� ��� � �����" << endl;
		cout << "14. ������� ��� ���������� ���" << endl;
		cout << "15. ��������� ������ � �����" << endl;
		cout << "16. �����\n\n";
		cout << "����� ������� > ";
		cin >> p;
		cout << endl;

		if (proverka(p))
		{
			number = atoi(p);
			if ((number <= 16) && (number >= 1))
			{
				if (number == 1)
				{
					if (flag)
						cout << "\n!������ � ����� ��� ������!\n";
					else
						cout << endl << "�� ������ ������!" << endl;
					flag = 1;

					if (nach == NULL)
					{
						nach = (struct Deque*)malloc(sizeof(struct Deque));
						if (nach == NULL)
						{
							printf("\n!������:������ �� ����������!\n");
							exit;
						}
						nach->deq = NULL;
						nach->sled = NULL;

						zahod = 1;

						konec = nach;
					}
					
				}

				if (flag == 1) {
					if (number < 10 && number>1 && !pustota(nach))
					{
						printf("\n��������� ��� ��:\n");
						listprint(nach);
					}




					//-----------------------------------------------

					switch (number)  // ������� �������� �� ������ ������ �� �������
					{
					case 2:
					{  if (pustota(nach))
						printf("\n��� ����. ������� 12 ��� 13 \n");
					else
					{
						nach = clean(nach);
						printf("\n��� ������\n");
						zahod = 1;

						nach = (struct Deque*)malloc(sizeof(struct Deque));
						if (nach == NULL)
						{
							printf("\n������! ������ �� ����������!\n");
							exit;
						}
						nach->sled = NULL;
						nach->deq = NULL;
						konec = nach;
						zahod = 1;
					}
					n1 = 0;
					break; }

					//-----------------------------------------------
					case 3: {  if (pustota(nach))
						printf("\n��� ����\n");
							else
						printf("\n��� �� ����\n");
						break; }
							break;
							//-----------------------------------------------
					case 4:
					{ if (pustota(nach))
						printf("\n��� ������ ������� 12 ��� 13\n");
					else
					{
						printf("\n������ ���������� ���: ");
						listprint(nach->deq);
					}
					break; }

					//-----------------------------------------------
					case 5:
					{ if (pustota(nach))
						printf("\n��� ���� ������� 12 ��� 13\n");
					else
					{
						printf("\n��������� ���������� ���: ");
						listprint(konec->deq);
					}
					break; }

					//-----------------------------------------------
					case 6:
					{  if (pustota(nach))
						printf("\n ��� ���� ������� 12 ��� 13\n");
					else
						nach = deletL(nach);

					if (nach == NULL)
					{
						zahod = 1;
						nach = (struct Deque*)malloc(sizeof(struct Deque));
						if (nach == NULL)
						{
							printf("\n������:������ �� ����������!\n");
							exit;
						}
						nach->sled = NULL;
						nach->deq = NULL;
						konec = nach;
					}
					n1--;
					break; }
					//-----------------------------------------------
					case 7:
					{  if (pustota(nach))
						printf("\n ��� ���� ������� 12 ��� 13\n");
					else
						konec = deletR(konec, nach);
					
					if (konec == NULL)
					{
						zahod = 1;
						konec = (struct Deque*)malloc(sizeof(struct Deque));
						if (konec == NULL)
						{
							printf("\n������:������ �� ����������!\n");
							exit;
						}
						konec->sled = NULL;
						konec->deq = NULL;

						nach = konec;
					}
					n1--;
					break; }

					//-----------------------------------------------
					case 8:
					{  if (pustota(nach))
						printf("\n ��� ���� ������� 12 ��� 13\n");
					else
						nach = vzatL(nach);
					if (nach == NULL)
					{
						zahod = 1;
						nach = (struct Deque*)malloc(sizeof(struct Deque));
						if (nach == NULL)
						{
							printf("\n������:������ �� ����������!\n");
							exit;
						}
						nach->sled = NULL;
						nach->deq = NULL;
						konec = nach;
					}
					n1--;
					break; }
					//-----------------------------------------------
					case 9:
					{  if (pustota(nach))
						printf("\n ��� ���� ������� 12 ��� 13\n");
					else
						konec = vzatR(konec, nach);

					if (konec == NULL)
					{
						zahod = 1;
						konec = (struct Deque*)malloc(sizeof(struct Deque));
						if (konec == NULL)
						{
							printf("\n������:������ �� ����������!\n");
							exit;
						}
						konec->sled = NULL;
						konec->deq = NULL;
						nach = konec;
					}
					n1--;
					break; }

					//-----------------------------------------------
					case 10: {  if (pustota(nach))
						printf("\n ��� ���� ������� 12 ��� 13\n");
							 else
					{
						bilo = (struct Deque*)malloc(sizeof(struct Deque));
						if (bilo == NULL)
						{
							printf("\n������:������ �� ����������!!\n");
							exit;
						}
						*bilo = *nach;
						bilo->deq = (struct Deque1*)malloc(sizeof(struct Deque1));
						if (bilo->deq == NULL)
						{
							printf("\n������:������ �� ����������!!\n");
							exit;
						}
						nach = menu2(nach);
						*(bilo->deq) = *(nach->deq);
						printf("\n��������� ��� ��:\n");
						listprint(bilo);
					}
							 break; }

							 //-----------------------------------------------
					case 11:
					{  if (pustota(nach))
						printf("\n��� ���� ������� 12 ��� 13\n");
					else
					{
						konec = menu2(konec);
						printf("\n��������� ��� ��\n");
						listprint(nach, konec);
					}

					break; }

					//-----------------------------------------------
					case 12:
					{ if (n1 < 5)
					{
						if (zahod)
						{
							nach = menu2(nach);
							printf("\n��������� ��� ��� ����\n");
							zahod = 0;
						}
						else
						{
							bilo = (struct Deque*)malloc(sizeof(struct Deque));
							if (bilo == NULL)
							{
								printf("\n������:������ �� ����������!\n");
								exit;
							}
							*bilo = *nach;
							bilo->deq = (struct Deque1*)malloc(sizeof(struct Deque1));
							if (bilo->deq == NULL)
							{
								printf("\n������:������ �� ����������!\n");
								exit;
							}
							*(bilo->deq) = *(nach->deq);
							nach = AddL(nach);
							printf("\n��������� ��� ��\n");

							listprint(bilo);

						}
						n1++;
					}
					else
						cout << "!�� �������� �������!" << endl;
					break; }
					//-----------------------------------------------
					case 13: { 
						if (n1 < 5)
						{
							if (zahod)
							{
								konec = menu2(konec);
								printf("\n��������� ��� ��� ����\n");
								zahod = 0;
							}
							else
							{
								konec = AddR(konec);
								printf("\n��������� ��� ��\n");
								listprint(nach, konec);
							}
							n1++;
						}
						else
							cout << "!�� �������� �������!" << endl;
							 break; }

							 //-----------------------------------------------

					case 14:
					{  if (pustota(nach))
						printf("\n��� ���� ������� 12 ��� 13\n");
					else
						listprint(nach);
					break; }

					case 15:
					{ flag = 0;
						if (nach!=NULL) 
						{
							nach = clean (nach);
					        printf("\n��� ������\n");
					    }
						n1 = 0;
					break;
					}

					//-----------------------------------------------

					case 16: break;
					}
					if (number < 14 && number >3 && !pustota(nach))
					{
						
						printf("\n��������� ��� �����:\n");
						listprint(nach);
					}
					if (number < 10 && number >7 && pustota(nach))
					{

						printf("\n��� ����\n");
						
					}
					//                             if((number == 10 || number == 11) && pustota(nach))
					//                             { printf("\n��������� ��� �����:\n");
					//                                 listprint(nach);
					//                             }

				}


				else
					if ((number != 1) && (number != 16))
						printf("\n������� ������ � �����\n");
			}
			else
				printf("\n������������ ����\n");
		}
		else
			printf("\n������������ ����\n");



			n2 = 0;
	} while (number != 16);

	if (nach != NULL) {
		nach = clean(nach);
		printf("\n��� ������\n");
	}
	system("pause");
}

//---------------------------------------------------------------------------

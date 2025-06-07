#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <locale.h>
#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH - 2)

//���밪 �Լ�
int abs(int n) {
	if (n < 0) {
		return -n;
	}
	else if (n > 0) {
		return n;
	}
	else if (n == 0) {
		return 0;
	}
	return n;
}

//�� ũ�� �Լ�
void print_first_and_last_line(void) {
	for (int i = 0; i < ROOM_WIDTH; i++) {
		printf("#");
	}
	printf("\n");
}

void print_second_line(void) {
	printf("#");
	for (int i = 1; i < ROOM_WIDTH - 1; i++) {
		if (i == HME_POS) {
			printf("H");
		}
		else if (i == BWL_PO) {
			printf("B");
		}
		else {
			printf(" ");
		}
	}
	printf("#\n");
}

void print_cat_position1(int where) {
	printf("#");
	if (where == 9) {
		for (int i = 1; i < ROOM_WIDTH - 1; i++) {
			if (i == where - 1) {
				printf("C");
			}
			else {
				printf(" ");
			}
		}
	}
	else {
		for (int i = 1; i < ROOM_WIDTH - 1; i++) {
			if (i == where) {
				printf("C");
			}
			else if (i == where - 1) {
				printf(".");
			}
			else {
				printf(" ");
			}
		}
	}
	printf("#\n");
}

void print_cat_position2(int where) {
	printf("#");
	if (where == 0) {
		for (int i = 1; i < ROOM_WIDTH - 1; i++) {
			if (i == where + 1) {
				printf("C");
			}
			else {
				printf(" ");
			}
		}
	}
	else {
		for (int i = 1; i < ROOM_WIDTH - 1; i++) {
			if (i == where) {
				printf("C");
			}
			else if (i == where + 1) {
				printf(".");
			}
			else {
				printf(" ");
			}
		}
	}
	printf("#\n");
}


int main(void) {
	srand((unsigned int)time(NULL));
	char cat[100]; //����� �̸�
	int intimacy = 2, soup = 0; //ģ�е� ,����
	int act, dice; // ��ȣ�ۿ�, �ֻ��� ��
	int where = 1; // �����(C) ��ġ
	int soupType; // ���� ����
	int feel = 3; // ���
	int scratcher = 0; // ��ũ��ó �ʱ�ȭ
	int scratcher_where = 0; // ��ũ��ó ��ġ �ʱ�ȭ
	int cat_tower = 0; // ĹŸ�� �ʱ�ȭ
	int cat_tower_where = 0; // ĹŸ�� ��ġ �ʱ�ȭ
	int CP = 0; // CP �ʱ�ȭ
	int turn = 1; // �� �ʱ�ȭ
	int previous_where; // ���� ��ġ
	int toyMouse = 0; // �峭�� �� �ʱ�ȭ
	int laserPointer = 0; // ������ ������ �ʱ�ȭ
	


	printf("****�߿��̿� ����****\n");
	printf("      /\\_/\\  \n");
	printf(" /\\  / o o \\ \n");
	printf("//\\\\ \\~(*)~/ \n");
	printf("`  \\/   ^ /   \n");
	printf("   | \\|| ||   \n");
	printf("   \\ '|| ||   \n");
	printf("    \\)()-())  \n");
	printf("�߿����� �̸��� ���� �ּ���: ");
	scanf_s("%s", cat, sizeof(cat));
	printf("�߿����� �̸��� %s�Դϴ�.\n", cat);
	Sleep(1000);
	system("cls");


	while (1) {
		Sleep(500);
		printf("==================== ���� ���� ===================\n");
		printf("������� ���� ����: %d��\n", soup);
		printf("������� ����(0~4): %d\n", intimacy);
		switch (intimacy) {
		case 0:
			printf(" �翡 ���� ������ �Ⱦ��մϴ�.\n");
			break;
		case 1:
			printf(" ���� ���Ǳ� ����Դϴ�.\n");
			break;
		case 2:
			printf(" �׷����� �� ���� �����Դϴ�.\n");
			break;
		case 3:
			printf(" �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
			break;
		case 4:
			printf(" ���� �������Դϴ�.\n");
			break;
		}


		printf("==================================================\n\n");
		Sleep(500);

		printf("%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n", cat);
		printf("�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", 6 - intimacy);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");



		



		Sleep(500);
		printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?  ");
		printf("0. �ƹ��͵� ���� ����  ");
		printf("1. �ܾ� �ֱ�  \n");
		while (1) {
			printf(">> ");
			scanf_s("%d", &act);
			if (act == 0 || act == 1) {
				break;
			}
		}


		if (act == 0) {
			printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
			printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			dice = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			if (dice <= 4) {
				printf("ģ�е��� �������ϴ�.\n");
				intimacy--;
				if (intimacy < 0) {
					intimacy = 0;
				}
			}
			else {
				printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
			}
		}
		else if (act == 1) {
			printf("%s�� ���� �ܾ��־����ϴ�.\n", cat);
			printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			dice = rand() % 6 + 1;
			if (dice < 5) {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("ģ�е��� �״���Դϴ�.\n");
			}
			else {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("ģ�е��� �������ϴ�.\n");
				intimacy++;
				if (intimacy > 4) {
					intimacy = 4;
				}
			}
		}
		printf("���� ģ�е�: %d\n", intimacy);
		Sleep(2500);

		system("cls");

		//---------------------------------ver2--------------------------------
		Sleep(500);
		printf("==================== ���� ���� ===================\n");
		printf("������� ���� ����: %d��\n", soup);

		// 2-2 ����â CP, ��� ���� �߰�
		
		printf("CP: %d ����Ʈ\n", CP);
		printf("%s�� ���(0~3): %d\n", cat, feel);

		switch (feel) {
		case 0:
			printf(" ����� �ſ� ���޴ϴ�.\n");
			break;
		case 1:
			printf(" �ɽ����մϴ�.\n");
			break;
		case 2:
			printf(" �Ļ��� �����ϴ�.\n");
			break;
		case 3:
			printf(" ������ �θ��ϴ�.\n");
			break;
		}
		//

		printf("������� ����(0~4): %d\n", intimacy);
		switch (intimacy) {
		case 0:
			printf(" �翡 ���� ������ �Ⱦ��մϴ�.\n");
			break;
		case 1:
			printf(" ���� ���Ǳ� ����Դϴ�.\n");
			break;
		case 2:
			printf(" �׷����� �� ���� �����Դϴ�.\n");
			break;
		case 3:
			printf(" �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
			break;
		case 4:
			printf(" ���� �������Դϴ�.\n");
			break;
		}


		printf("==================================================\n\n");
		Sleep(500);

		// 2-2 ��� ������
		printf("6-%d: �ֻ��� ���� %d�����̸� �׳� ����� �������ϴ�.\n", intimacy, 6 - intimacy);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
		dice = rand() % 6 + 1;
		printf("%d��(��) ���Խ��ϴ�.\n", dice);
		if (dice <= 6 - intimacy) {
			printf("%s�� ����� �������ϴ�: %d->%d\n", cat, feel, feel - 1);
			feel--;
			if (feel < 0) {
				feel = 0;
			}
		}
		else {
			printf("������ ����� �������� �ʾҽ��ϴ�.\n");
		}
		
		//

		//2-3 �̵�

		previous_where = where; // ���� ��ġ ����

		switch (feel) {
		case 0:
			printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", cat);
			print_first_and_last_line();
			print_second_line();
			print_print_cat_position2(where);
			print_first_and_last_line();
			break;
		case 1:
			
			

			if (abs(scratcher_where - where) > abs(cat_tower_where - where)) {
				if (scratcher_where - where > 0) {
					where++; // ��ũ��ó�� �̵�
					printf("%s��(��) �ɽ����ϸ� ��ũ��ó ������ �̵��մϴ�.\n", cat);
				}
				else if (scratcher_where - where < 0) {
					where--; // ��ũ��ó�� �̵�
					printf("%s��(��) �ɽ����ϸ� ��ũ��ó ������ �̵��մϴ�.\n", cat);
				}
				else if (scratcher_where - where == 0) {
					where = scratcher_where; // ��ũ��ó�� �̵�
					printf("%s��(��) �ɽ����ϸ� ��ũ��ó �ʿ��� ����մϴ�.\n", cat);
				}
				break;
			}

			else if (abs(scratcher_where - where) < abs(cat_tower_where - where)) {
				if (cat_tower_where - where > 0) {
					where++; // ĹŸ���� �̵�
					printf("%s��(��) �ɽ����ϸ� ��Ÿ�� ������ �̵��մϴ�.\n", cat);
				}
				else if (cat_tower_where - where < 0) {
					where--; // ĹŸ���� �̵�
					printf("%s��(��) �ɽ����ϸ� ��Ÿ�� ������ �̵��մϴ�.\n", cat);
				}
				else if (cat_tower_where - where == 0) {
					where = cat_tower_where; // ĹŸ���� �̵�
					printf("%s��(��) �ɽ����ϸ� ��Ÿ�� �ʿ��� ����մϴ�.\n", cat);
				}
				break;
			}
			
			

			if (scratcher == 0 && cat_tower == 0) {
				printf("�� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
				feel--;
			}
			
			break;
		case 2:
			printf("%s��(��) ������� �Ļ��� ���� �ֽ��ϴ�.\n", cat);
			break;
		case 3:
			printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.\n", cat);
			print_first_and_last_line();
			print_second_line();
			print_print_cat_position1(where);
			print_first_and_last_line();
			break;
		}

		if (where < 1) {
			where = 1;
		}
		if (where > 8) {
			where = 8;
		}

		//
		Sleep(500);
		//2-4 �ൿ
		if (where == HME_POS) {
			if (where == previous_where) 
			feel++;
		}
		else if (where == BWL_PO) {
			
			soupType = rand() % 3;
			switch (soupType) {
			case 0:
				printf("%s��(��) ����� ������ ��������ϴ�!\n", cat);
				break;
			case 1:
				printf("%s��(��) ����ݸ� ������ ��������ϴ�!\n", cat);
				break;
			case 2:
				printf("%s��(��) ���� ������ ��������ϴ�!\n", cat);
				break;
			}

			soup++;
			printf("������� ���� ����: %d��\n\n", soup);
			
		}
		else if (where == scratcher_where) {
			printf("%s��(��) %s���� ����� Ǯ�� �ֽ��ϴ�.\n", cat, scratcher);
			printf("����� ���� ���������ϴ�: %d->%d\n",feel, feel + 1);
			feel++;

		}
		else if (where == cat_tower_where) {
			printf("%s��(��) %s���� ���ƴٴմϴ�.\n", cat, cat_tower);
			printf("����� ���� ���������ϴ�: %d->%d\n", feel, feel + 2);
			feel += 2;
		}
		printf("\n");
		//
		Sleep(500);
		//2-5 ��ȣ�ۿ� �Է�
		printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
		printf(" 0. �ƹ��͵� ���� ����\n");
		printf(" 1. �ܾ� �ֱ�\n");
		for (int i = 2; i < 4; i++) {
			if (toyMouse == 1) {
				printf(" %d. �峭�� ��� ��� �ֱ�%s\n", i);
				continue;
			}
			if (laserPointer == 1) {
				printf(" %d. ������ �����ͷ� ��� �ֱ�\n", i);
			}
		}
		while (1) {
			printf(">> ");
			scanf_s("%d", &act);
			if (act >= 0 && act <= 4) {
				break;
			}
		}
		//
		
		//2-6 ��ȣ�ۿ� ó��
		switch (act) {
		case 0:
			printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
			printf("%s�� ����� ���������ϴ�: %d->%d\n", cat, feel, feel - 1);
			printf("5/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			dice = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			if (dice <= 5) {
				printf("������� ���谡 �������ϴ�.\n");
				intimacy--;
				if (intimacy < 0) {
					intimacy = 0;
				}
			}
			else {
				printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
			}
			break;
		case 1:
			printf("%s(��)�� �ܾ��־����ϴ�.\n", cat);
			printf("%s�� ����� �״���Դϴ�: %d\n", cat, feel);
			printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
			printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
			dice = rand() % 6 + 1;
			if (dice >= 5) {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("ģ�е��� �������ϴ�.\n");
				intimacy++;
				if (intimacy > 4) {
					intimacy = 4;
				}	
			}
			else {
				printf("%d��(��) ���Խ��ϴ�!\n", dice);
				printf("ģ�е��� �״���Դϴ�.\n");
			}
			break;
		case 2:
			if (toyMouse == 1) {
				printf("�峭�� ��� %s�� ��� �־����ϴ�.\n", cat);
				printf("%s�� ����� ���� ���������ϴ�: %d->%d\n", cat, feel, feel + 1);
				feel++;
				dice = rand() % 6 + 1;
				if (dice >= 4) {
					printf("%d��(��) ���Խ��ϴ�!\n", dice);
					printf("ģ�е��� �������ϴ�.\n");
					intimacy++;
					if (intimacy > 4) {
						intimacy = 4;
					}
				}
				else {
					printf("%d��(��) ���Խ��ϴ�!\n", dice);
					printf("ģ�е��� �״���Դϴ�.\n");
				}
			}

			if (laserPointer == 1) {
				printf("������ �����ͷ� %s�� �ų��� ��� �־����ϴ�.\n", cat);
				printf("%s�� ����� �� ���������ϴ�: %d->%d\n", cat, feel, feel + 2);
				feel += 2;
				dice = rand() % 6 + 1;
				if (dice >= 2) {
					printf("%d��(��) ���Խ��ϴ�!\n", dice);
					printf("ģ�е��� �������ϴ�.\n");
					intimacy++;
					if (intimacy > 4) {
						intimacy = 4;
					}
				}
				else {
					printf("%d��(��) ���Խ��ϴ�!\n", dice);
					printf("ģ�е��� �״���Դϴ�.\n");
				}
			}
		case 3:
			if (laserPointer == 1) {
				printf("������ �����ͷ� %s�� �ų��� ��� �־����ϴ�.\n", cat);
				printf("%s�� ����� �� ���������ϴ�: %d->%d\n", cat, feel, feel + 2);
				feel += 2;
				dice = rand() % 6 + 1;
				if (dice >= 2) {
					printf("%d��(��) ���Խ��ϴ�!\n", dice);
					printf("ģ�е��� �������ϴ�.\n");
					intimacy++;
					if (intimacy > 4) {
						intimacy = 4;
					}
				}
				else {
					printf("%d��(��) ���Խ��ϴ�!\n", dice);
					printf("ģ�е��� �״���Դϴ�.\n");
				}
			break;
		default:
			break;
		}

		//
		Sleep(500);
		//2-7 cp ����
			CP += (feel > 0 ? feel - 1 : 0) + intimacy;
		printf("%s�� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n", cat, (feel > 0 ? feel - 1 : 0) + intimacy);
		printf("���� CP: %d ����Ʈ\n", CP);
		// 	
		Sleep(500);
		//2-8 ����
		printf("���� ���� CP: %d CP\n", CP);
		printf("�������� ������ �� �� �ֽ��ϴ�.\n");
		printf("� ������ �����ұ��?\n");
		printf(" 0. �ƹ� �͵� ���� �ʴ´�.\n");
		if (toyMouse == 1) 
			printf(" 1. �峭�� ��: 1 CP (ǰ��)\n");
		else 
			printf(" 1. �峭�� ��: 1 CP\n");

		if (laserPointer == 1)
			printf(" 2. ������ ������: 2 CP (ǰ��)\n");
		else
			printf(" 2. ������ ������: 2 CP\n");

		if (scratcher == 1)
			printf(" 3. ��ũ��ó: 4 CP (ǰ��)\n");
		else
			printf(" 3. ��ũ��ó: 4 CP\n");

		if (cat_tower == 1)
			printf(" 4. ĹŸ��: 6 CP (ǰ��)\n");
		else
			printf(" 4. ĹŸ��: 6 CP\n");



		while (1) {
			printf(">> ");
			scanf_s("%d", &act);
			if (act >= 0 && act <= 4) {
				switch (act) {
				case 0:
					printf("�ƹ� �͵� ���� �ʽ��ϴ�.\n");
					break;
				case 1:
					if (toyMouse == 1) {
						printf("�峭�� �㸦 �̹� �����߽��ϴ�.\n");
						break;
					}
					if (CP >= 1) {
						printf("�峭�� �㸦 �����߽��ϴ�.\n");
						CP -= 1;
						printf("���� CP %d ����Ʈ\n", CP);
						toyMouse = 1;
					}
					else {
						printf("CP�� �����մϴ�.\n");
					}
					break;
				case 2:
					if (laserPointer == 1) {
						printf("������ �����͸� �̹� �����߽��ϴ�.\n");
						break;
					}
					if (CP >= 2) {
						printf("������ �����͸� �����߽��ϴ�.\n");
						CP -= 2;
						printf("���� CP %d ����Ʈ\n", CP);
						laserPointer = 1;
					}
					else {
						printf("CP�� �����մϴ�.\n");
					}
					break;
				case 3:
					if (scratcher == 1) {
						printf("��ũ��ó�� �̹� �����߽��ϴ�.\n");
						break;
					}
					if (CP >= 4) {
						printf("��ũ��ó�� �����߽��ϴ�.\n");
						CP -= 4;
						printf("���� CP %d ����Ʈ\n", CP);
						scratcher = 1;
						scratcher_where = rand() % (ROOM_WIDTH - 2) + 1; // ��ũ��ó ��ġ ���� ����
						while (scratcher_where == HME_POS || scratcher_where == BWL_PO) {
							scratcher_where = rand() % (ROOM_WIDTH - 2) + 1; // ��ũ��ó ��ġ�� ���̳� ���� ��ġ�� �ʵ���
						}


					}
					else {
						printf("CP�� �����մϴ�.\n");
					}
					break;
				case 4:
					if (cat_tower == 1) {
						printf("ĹŸ���� �̹� �����߽��ϴ�.\n");
						break;
					}
					if (CP >= 6) {
						printf("ĹŸ���� �����߽��ϴ�.\n");
						CP -= 6;
						printf("���� CP %d ����Ʈ\n", CP);
						cat_tower = 1;
						cat_tower_where = rand() % (ROOM_WIDTH - 2) + 1; // ĹŸ�� ��ġ ���� ����
						while (cat_tower_where == HME_POS || cat_tower_where == BWL_PO || cat_tower_where == scratcher_where) {
							cat_tower_where = rand() % (ROOM_WIDTH - 2) + 1; // ĹŸ�� ��ġ�� ���̳� ���� ��ġ�� �ʵ���
						}
					}
					else {
						printf("CP�� �����մϴ�.\n");
					}
					break;
				default:
					break;
				}
				break;
			}
		}
		
		//

		turn++;
	}




	return 0;

}
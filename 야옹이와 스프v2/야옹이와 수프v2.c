#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <locale.h>
#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH - 2)

int main(void) {
	srand((unsigned int)time(NULL));
	char cat[100]; //����� �̸�
	int intimacy = 2, soup = 0; //ģ�е� ,����
	int act, dice; // ��ȣ�ۿ�, �ֻ��� ��
	int where = 1; // �����(C) ��ġ
	int soupType; // ���� ����

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



		dice = rand() % 6 + 1;
		if (dice >= 6 - intimacy) {
			where++;
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			printf("���� ������ �����Դϴ�.\n");
			Sleep(500);
			if (where == 8 || where == 9) {
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

			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}
			printf("\n");

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
			printf("#");
			printf("\n");



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

			printf("#");
			printf("\n");

			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}
			printf("\n");
		}
		else {
			where--;
			printf("%d��(��) ���Խ��ϴ�!\n", dice);
			printf("�� ������ �����Դϴ�.\n");
			Sleep(500);

			if (where == 1 || where == 0) {
				printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n\n", cat);
			}

			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}
			printf("\n");

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
			printf("#");
			printf("\n");

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
			printf("#");
			printf("\n");

			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}
			printf("\n");
		}

		if (where < 1) {
			where = 1;
		}
		if (where > 8) {
			where = 8;
		}



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
		int feel = 3;
		int CP = 0;
	
		printf("CP: %d ����Ʈ\n", CP);
		printf("%s�� ���(0~3): %d", cat, feel);

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

	}




	return 0;

}
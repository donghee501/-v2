#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <locale.h>
#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH - 2)
//방 크기 함수
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
	char cat[100]; //고양이 이름
	int intimacy = 2, soup = 0; //친밀도 ,수프
	int act, dice; // 상호작용, 주사위 수
	int where = 1; // 고양이(C) 위치
	int soupType; // 수프 종류
	int feel = 3; // 기분
	char scratcher[] = "스크레처"; // 스크래처 이름
	char cat_tower[] = "캣타워"; // 캣타워 이름
	int CP = 0; // CP 초기화
	int turn = 1; // 턴 초기화
	int previous_where;

	printf("****야옹이와 수프****\n");
	printf("      /\\_/\\  \n");
	printf(" /\\  / o o \\ \n");
	printf("//\\\\ \\~(*)~/ \n");
	printf("`  \\/   ^ /   \n");
	printf("   | \\|| ||   \n");
	printf("   \\ '|| ||   \n");
	printf("    \\)()-())  \n");
	printf("야옹이의 이름을 지어 주세요: ");
	scanf_s("%s", cat, sizeof(cat));
	printf("야옹이의 이름은 %s입니다.\n", cat);
	Sleep(1000);
	system("cls");


	while (1) {
		Sleep(500);
		printf("==================== 현재 상태 ===================\n");
		printf("현재까지 만든 수프: %d개\n", soup);
		printf("집사와의 관계(0~4): %d\n", intimacy);
		switch (intimacy) {
		case 0:
			printf(" 곁에 오는 것조차 싫어합니다.\n");
			break;
		case 1:
			printf(" 간식 자판기 취급입니다.\n");
			break;
		case 2:
			printf(" 그럭저럭 쓸 만한 집사입니다.\n");
			break;
		case 3:
			printf(" 훌륭한 집사로 인정 받고 있습니다.\n");
			break;
		case 4:
			printf(" 집사 껌딱지입니다.\n");
			break;
		}


		printf("==================================================\n\n");
		Sleep(500);

		printf("%s 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n", cat);
		printf("주사위 눈이 %d 이상이면 냄비 쪽으로 이동합니다.\n", 6 - intimacy);
		printf("주사위를 굴립니다. 또르륵...\n");



		



		Sleep(500);
		printf("어떤 상호작용을 하시겠습니까?  ");
		printf("0. 아무것도 하지 않음  ");
		printf("1. 긁어 주기  \n");
		while (1) {
			printf(">> ");
			scanf_s("%d", &act);
			if (act == 0 || act == 1) {
				break;
			}
		}


		if (act == 0) {
			printf("아무것도 하지 않습니다.\n");
			printf("4/6의 확률로 친밀도가 떨어집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");
			dice = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다!\n", dice);
			if (dice <= 4) {
				printf("친밀도가 떨어집니다.\n");
				intimacy--;
				if (intimacy < 0) {
					intimacy = 0;
				}
			}
			else {
				printf("다행히 친밀도가 떨어지지 않았습니다.\n");
			}
		}
		else if (act == 1) {
			printf("%s의 턱을 긁어주었습니다.\n", cat);
			printf("2/6의 확률로 친밀도가 높아집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");
			dice = rand() % 6 + 1;
			if (dice < 5) {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("친밀도는 그대로입니다.\n");
			}
			else {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("친밀도가 높아집니다.\n");
				intimacy++;
				if (intimacy > 4) {
					intimacy = 4;
				}
			}
		}
		printf("현재 친밀도: %d\n", intimacy);
		Sleep(2500);

		system("cls");

		//---------------------------------ver2--------------------------------
		Sleep(500);
		printf("==================== 현재 상태 ===================\n");
		printf("현재까지 만든 수프: %d개\n", soup);

		// 2-2 상태창 CP, 기분 설정 추가
		
		printf("CP: %d 포인트\n", CP);
		printf("%s이 기분(0~3): %d\n", cat, feel);

		switch (feel) {
		case 0:
			printf(" 기분이 매우 나쁩니다.\n");
			break;
		case 1:
			printf(" 심심해합니다.\n");
			break;
		case 2:
			printf(" 식빵을 굽습니다.\n");
			break;
		case 3:
			printf(" 골골송을 부릅니다.\n");
			break;
		}
		//

		printf("집사와의 관계(0~4): %d\n", intimacy);
		switch (intimacy) {
		case 0:
			printf(" 곁에 오는 것조차 싫어합니다.\n");
			break;
		case 1:
			printf(" 간식 자판기 취급입니다.\n");
			break;
		case 2:
			printf(" 그럭저럭 쓸 만한 집사입니다.\n");
			break;
		case 3:
			printf(" 훌륭한 집사로 인정 받고 있습니다.\n");
			break;
		case 4:
			printf(" 집사 껌딱지입니다.\n");
			break;
		}


		printf("==================================================\n\n");
		Sleep(500);

		// 2-2 기분 나빠짐
		printf("6-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", intimacy, 6 - intimacy);
		printf("주사위를 굴립니다. 또르르...\n");
		dice = rand() % 6 + 1;
		printf("%d이(가) 나왔습니다.\n", dice);
		if (dice <= 6 - intimacy) {
			printf("%s의 기분이 나빠집니다: %d->%d\n", cat, feel, feel - 1);
			feel--;
			if (feel < 0) {
				feel = 0;
			}
		}
		else {
			printf("다행히 기분이 나빠지지 않았습니다.\n");
		}
		
		//

		//2-3 이동

		previous_where = where; // 이전 위치 저장

		switch (feel) {
		case 0:
			printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", cat);
			print_first_and_last_line();
			print_second_line();
			print_print_cat_position2(where);
			print_first_and_last_line();
			break;
		case 1:
			printf("%s은(는) 심심해서 %s 쪽으로 이동합니다.\n", cat);
			print_first_and_last_line();
			print_second_line();

			if (놀이기구x) {
				printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
				feel--;
			}
			if (가까운 놀이기구 집쪽) {
				print_cat_position2(where);
			}
			else {
				print_cat_position1(where);

			}
			
			print_first_and_last_line();

			break;
		case 2:
			printf("%s은(는) 기분좋게 식빵을 굽고 있습니다.\n", cat);
			break;
		case 3:
			printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", cat);
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
		//2-4 행동
		if (where == HME_POS) {
			if (where == previous_where) 
			feel++;
		}
		else if (where == BWL_PO) {
			
			soupType = rand() % 3;
			switch (soupType) {
			case 0:
				printf("%s이(가) 양송이 수프를 만들었습니다!\n", cat);
				break;
			case 1:
				printf("%s이(가) 브로콜리 수프를 만들었습니다!\n", cat);
				break;
			case 2:
				printf("%s이(가) 감자 수프를 만들었습니다!\n", cat);
				break;
			}

			soup++;
			printf("현재까지 만든 수프: %d개\n\n", soup);
			
		}
		else if (where == 스크레처) {
			printf("%s이(가) %s에서 기분을 풀고 있습니다.\n", cat, scratcher);
			printf("기분이 조금 좋아졌습니다: %d->%d\n",feel, feel + 1);
			feel++;

		}
		else if (where == 캣타워) {
			printf("%s이(가) %s에서 날아다닙니다.\n", cat, cat_tower);
			printf("기분이 제법 좋아졌습니다: %d->%d\n", feel, feel + 2);
			feel += 2;
		}
		printf("\n");
		//
		Sleep(500);
		//2-5 상호작용 입력
		printf("어떤 상호작용을 하시겠습니까?\n");
		printf(" 0. 아무것도 하지 않음\n");
		printf(" 1. 긁어 주기\n");
		for (int i = 2; i < 4; i++) {
			if (장난감 쥐o) {
				printf(" %d. 장난감 쥐로 놀아 주기%s\n", i);
				continue;
			}
			if (레이저o) {
				printf(" %d. 레이저 포인터로 놀아 주기\n", i);
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
		
		//2-6 상호작용 처리
		switch (act) {
		case 0:
			printf("아무것도 하지 않습니다.\n");
			printf("%s의 기분이 나빠졌습니다: %d->%d\n", cat, feel, feel - 1);
			printf("5/6의 확률로 친밀도가 떨어집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");
			dice = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다!\n", dice);
			if (dice <= 5) {
				printf("집사와의 관계가 나빠집니다.\n");
				intimacy--;
				if (intimacy < 0) {
					intimacy = 0;
				}
			}
			else {
				printf("다행히 친밀도가 떨어지지 않았습니다.\n");
			}
			break;
		case 1:
			printf("%s(이)를 긁어주었습니다.\n", cat);
			printf("%s의 기분은 그대로입니다: %d\n", cat, feel);
			printf("2/6의 확률로 친밀도가 높아집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");
			dice = rand() % 6 + 1;
			if (dice >= 5) {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("친밀도가 높아집니다.\n");
				intimacy++;
				if (intimacy > 4) {
					intimacy = 4;
				}	
			}
			else {
				printf("%d이(가) 나왔습니다!\n", dice);
				printf("친밀도는 그대로입니다.\n");
			}
			break;
		case 2:
			if (장난감 쥐o) {
				printf("장난감 쥐로 %s와 놀아 주었습니다.\n", cat);
				printf("%s의 기분이 조금 좋아졌습니다: %d->%d\n", cat, feel, feel + 1);
				feel++;
				dice = rand() % 6 + 1;
				if (dice >= 4) {
					printf("%d이(가) 나왔습니다!\n", dice);
					printf("친밀도가 높아집니다.\n");
					intimacy++;
					if (intimacy > 4) {
						intimacy = 4;
					}
				}
				else {
					printf("%d이(가) 나왔습니다!\n", dice);
					printf("친밀도는 그대로입니다.\n");
				}
			}

			if (레이저o) {
				printf("레이저 포인터로 %s와 신나게 놀아 주었습니다.\n", cat);
				printf("%s의 기분이 꽤 좋아졌습니다: %d->%d\n", cat, feel, feel + 2);
				feel += 2;
				dice = rand() % 6 + 1;
				if (dice >= 2) {
					printf("%d이(가) 나왔습니다!\n", dice);
					printf("친밀도가 높아집니다.\n");
					intimacy++;
					if (intimacy > 4) {
						intimacy = 4;
					}
				}
				else {
					printf("%d이(가) 나왔습니다!\n", dice);
					printf("친밀도는 그대로입니다.\n");
				}
			}
		case 3:
			if (레이저o) {
				printf("레이저 포인터로 %s와 신나게 놀아 주었습니다.\n", cat);
				printf("%s의 기분이 꽤 좋아졌습니다: %d->%d\n", cat, feel, feel + 2);
				feel += 2;
				dice = rand() % 6 + 1;
				if (dice >= 2) {
					printf("%d이(가) 나왔습니다!\n", dice);
					printf("친밀도가 높아집니다.\n");
					intimacy++;
					if (intimacy > 4) {
						intimacy = 4;
					}
				}
				else {
					printf("%d이(가) 나왔습니다!\n", dice);
					printf("친밀도는 그대로입니다.\n");
				}
			break;
		default:
			break;
		}

		//
		Sleep(500);
		//2-7 cp 생산
			CP += (feel > 0 ? feel - 1 : 0) + intimacy;
		printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", cat, (feel > 0 ? feel - 1 : 0) + intimacy);
		printf("보유 CP: %d 포인트\n", CP);
		// 	
		Sleep(500);
		

		turn++;
	}




	return 0;

}
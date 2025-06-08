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

void print_second_line(int scratcher_where, int cat_tower_where) {
	printf("#");
	for (int i = 1; i < ROOM_WIDTH - 1; i++) {
		if (i == HME_POS) {
			printf("H");
		}
		else if (i == BWL_PO) {
			printf("B");
		}
		else if (i == scratcher_where) {
			printf("S");
		}
		else if (i == cat_tower_where) {
			printf("T");
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

void print_cat_stay(int where) {
	printf("#");
	for (int i = 1; i < ROOM_WIDTH - 1; i++) {
		if (i == where) {
			printf("C");
		}
		else {
			printf(" ");
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
	int scratcher = 0; // 스크래처 초기화
	int scratcher_where = 0; // 스크래처 위치 초기화
	int cat_tower = 0; // 캣타워 초기화
	int cat_tower_where = 0; // 캣타워 위치 초기화
	int CP = 0; // CP 초기화
	int turn = 1; // 턴 초기화
	int previous_where; // 이전 위치
	int toyMouse = 0; // 장난감 쥐 초기화
	int laserPointer = 0; // 레이저 포인터 초기화



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
			if (feel < 0) feel = 0;
		}
		else {
			printf("다행히 기분이 나빠지지 않았습니다.\n");
		}

		//

		//2-3 이동

		previous_where = where; // 이전 위치 저장

		switch (feel) {
		case 0:
			printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n\n", cat);
			where--;
			print_first_and_last_line();
			print_second_line(scratcher_where, cat_tower_where);
			print_cat_position2(where);
			print_first_and_last_line();
			break;
		case 1:
			if (scratcher == 0 && cat_tower == 1) {
				if (cat_tower_where - where > 0) {
					where++;
					printf("%s은(는) 심심해하며 켓타워 쪽으로 이동합니다.\n\n", cat);
					print_first_and_last_line();
					print_second_line(scratcher_where, cat_tower_where);
					print_cat_position1(where);
					print_first_and_last_line();
				}
				else if (cat_tower_where - where < 0) {
					where--;
					printf("%s은(는) 심심해하며 켓타워 쪽으로 이동합니다.\n\n", cat);
					print_first_and_last_line();
					print_second_line(scratcher_where, cat_tower_where);
					print_cat_position2(where);
					print_first_and_last_line();
				}
				else if (cat_tower_where - where == 0) {
					where = cat_tower_where;
					printf("%s은(는) 심심해하며 켓타워 쪽에서 대기합니다.\n\n", cat);
					print_first_and_last_line();
					print_second_line(scratcher_where, cat_tower_where);
					print_cat_stay(where);
					print_first_and_last_line();
				}
				break;
			}

			if (scratcher == 1 && cat_tower == 0) {
				if (scratcher_where - where > 0) {
					where++;
					printf("%s은(는) 심심해하며 스크레처 쪽으로 이동합니다.\n\n", cat);
					print_first_and_last_line();
					print_second_line(scratcher_where, cat_tower_where);
					print_cat_position1(where);
					print_first_and_last_line();
				}
				else if (scratcher_where - where < 0) {
					where--;
					printf("%s은(는) 심심해하며 스크레처 쪽으로 이동합니다.\n\n", cat);
					print_first_and_last_line();
					print_second_line(scratcher_where, cat_tower_where);
					print_cat_position2(where);
					print_first_and_last_line();
				}
				else if (scratcher_where - where == 0) {
					where = scratcher_where;
					printf("%s은(는) 심심해하며 스크레처 쪽에서 대기합니다.\n\n", cat);
					print_first_and_last_line();
					print_second_line(scratcher_where, cat_tower_where);
					print_cat_stay(where);
					print_first_and_last_line();
				}
				break;
			}

			if (scratcher == 1 && cat_tower == 1) {
				// 스크래처로 이동
				if (abs(scratcher_where - where) > abs(cat_tower_where - where)) {
					if (scratcher_where - where > 0) {
						where++;
						printf("%s은(는) 심심해하며 스크레처 쪽으로 이동합니다.\n\n", cat);
						print_first_and_last_line();
						print_second_line(scratcher_where, cat_tower_where);
						print_cat_position1(where);
						print_first_and_last_line();
					}
					else if (scratcher_where - where < 0) {
						where--;
						printf("%s은(는) 심심해하며 스크레처 쪽으로 이동합니다.\n\n", cat);
						print_first_and_last_line();
						print_second_line(scratcher_where, cat_tower_where);
						print_cat_position2(where);
						print_first_and_last_line();
					}
					else if (scratcher_where - where == 0) {
						where = scratcher_where;
						printf("%s은(는) 심심해하며 스크레처 쪽에서 대기합니다.\n\n", cat);
						print_first_and_last_line();
						print_second_line(scratcher_where, cat_tower_where);
						print_cat_stay(where);
						print_first_and_last_line();
					}

					break;
				}
				// 캣타워로 이동
				else if (abs(scratcher_where - where) < abs(cat_tower_where - where)) {
					if (cat_tower_where - where > 0) {
						where++;
						printf("%s은(는) 심심해하며 켓타워 쪽으로 이동합니다.\n\n", cat);
						print_first_and_last_line();
						print_second_line(scratcher_where, cat_tower_where);
						print_cat_position2(where);
						print_first_and_last_line();
					}
					else if (cat_tower_where - where < 0) {
						where--;
						printf("%s은(는) 심심해하며 켓타워 쪽으로 이동합니다.\n\n", cat);
						print_first_and_last_line();
						print_second_line(scratcher_where, cat_tower_where);
						print_cat_position1(where);
						print_first_and_last_line();
					}
					else if (cat_tower_where - where == 0) {
						where = cat_tower_where;
						printf("%s은(는) 심심해하며 켓타워 쪽에서 대기합니다.\n\n", cat);
						print_first_and_last_line();
						print_second_line(scratcher_where, cat_tower_where);
						print_cat_stay(where);
						print_first_and_last_line();
					}
					break;
				}
			}
			



			if (scratcher == 0 && cat_tower == 0) {
				printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n\n");
				feel--;
				if (feel < 0) feel = 0;
				print_first_and_last_line();
				print_second_line(scratcher_where, cat_tower_where);
				print_cat_stay(where);
				print_first_and_last_line();
			}

			break;
		case 2:
			printf("%s은(는) 기분좋게 식빵을 굽고 있습니다.\n\n", cat);
			print_first_and_last_line();
			print_second_line(scratcher_where, cat_tower_where);
			print_cat_stay(where);
			print_first_and_last_line();
			break;
		case 3:
			printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n\n", cat);
			where++;
			print_first_and_last_line();
			print_second_line(scratcher_where, cat_tower_where);
			print_cat_position1(where);
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
		else if (where == scratcher_where) {
			printf("%s이(가) 스크레처에서 기분을 풀고 있습니다.\n", cat);
			printf("기분이 조금 좋아졌습니다: %d->%d\n", feel, (feel + 1 > 3 ? 3 : feel + 1));
			feel++;

		}
		else if (where == cat_tower_where) {
			printf("%s이(가) 켓타워에서 날아다닙니다.\n", cat);
			printf("기분이 제법 좋아졌습니다: %d->%d\n", feel, (feel + 2 > 3 ? 3 : feel + 2));
			feel += 2;
		}
		if (feel > 3) feel = 3;

		printf("\n");
		//
		Sleep(500);
		//2-5 상호작용 입력
		printf("어떤 상호작용을 하시겠습니까?\n");
		printf(" 0. 아무것도 하지 않음\n");
		printf(" 1. 긁어 주기\n");
		for (int i = 2; i < 4; i++) {
			if (toyMouse == 1 && i != 3) {
				printf(" %d. 장난감 쥐로 놀아 주기\n", i);
				continue;
			}
			if (laserPointer == 1) {
				printf(" %d. 레이저 포인터로 놀아 주기\n", i);
				break;
			}
		}
		while (1) {
			printf(">> ");
			scanf_s("%d", &act);
			if (act >= 0 && act <= 1) break;
			if (act == 2) {
				if (toyMouse == 1 || laserPointer == 1) break;
			}
			if (act == 3) {
				if (toyMouse == 1 && laserPointer == 1) break;
			}
			
		}
		printf("\n");
		//

		Sleep(500);


		//2-6 상호작용 처리
		switch (act) {
		case 0:
			printf("아무것도 하지 않습니다.\n");
			printf("%s의 기분이 나빠졌습니다: %d->%d\n", cat, feel, (feel - 1 < 0 ? 0 : feel - 1));
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
			feel--;
			if (feel < 0) feel = 0;
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
			if (toyMouse == 1) {
				printf("장난감 쥐로 %s와 놀아 주었습니다.\n", cat);
				printf("%s의 기분이 조금 좋아졌습니다: %d->%d\n", cat, feel, (feel + 1 > 3 ? 3 : feel + 1));
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
				if (feel > 3) feel = 3;
				break;
			}

			if (laserPointer == 1) {
				printf("레이저 포인터로 %s와 신나게 놀아 주었습니다.\n", cat);
				printf("%s의 기분이 꽤 좋아졌습니다: %d->%d\n", cat, feel, (feel + 2 > 3 ? 3 : feel + 2));
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
			if (feel > 3) feel = 3;
			break;
		case 3:
			if (laserPointer == 1) {
				printf("레이저 포인터로 %s와 신나게 놀아 주었습니다.\n", cat);
				printf("%s의 기분이 꽤 좋아졌습니다: %d->%d\n", cat, feel, (feel + 2 > 3 ? 3 : feel + 2));
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
				if (feel > 3) feel = 3;
			}
			
				break;
		default:
			break;
		}
		printf("\n");
		Sleep(500);
		
		//

		Sleep(500);

		//2-7 cp 생산
		CP += (feel > 0 ? feel - 1 : 0) + intimacy;
		printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", cat, (feel > 0 ? feel - 1 : 0) + intimacy);
		printf("보유 CP: %d 포인트\n", CP);
		// 	

		Sleep(500);

		//2-8 상점
		printf("상점에서 물건을 살 수 있습니다.\n");
		printf("어떤 물건을 구매할까요?\n");
		printf(" 0. 아무 것도 사지 않는다.\n");
		if (toyMouse == 1)
			printf(" 1. 장난감 쥐: 1 CP (품절)\n");
		else
			printf(" 1. 장난감 쥐: 1 CP\n");

		if (laserPointer == 1)
			printf(" 2. 레이저 포인터: 2 CP (품절)\n");
		else
			printf(" 2. 레이저 포인터: 2 CP\n");

		if (scratcher == 1)
			printf(" 3. 스크래처: 4 CP (품절)\n");
		else
			printf(" 3. 스크래처: 4 CP\n");

		if (cat_tower == 1)
			printf(" 4. 캣타워: 6 CP (품절)\n");
		else
			printf(" 4. 캣타워: 6 CP\n");



		while (1) {
			printf(">> ");
			scanf_s("%d", &act);
			if (act >= 0 && act <= 4) {
				switch (act) {
				case 0:
					printf("아무 것도 사지 않습니다.\n");
					break;
				case 1:
					if (toyMouse == 1) {
						printf("장난감 쥐를 이미 구매했습니다.\n");
						break;
					}
					if (CP >= 1) {
						printf("장난감 쥐를 구매했습니다.\n");
						CP -= 1;
						printf("보유 CP %d 포인트\n", CP);
						toyMouse = 1;
					}
					else {
						printf("CP가 부족합니다.\n");
					}
					break;
				case 2:
					if (laserPointer == 1) {
						printf("레이저 포인터를 이미 구매했습니다.\n");
						break;
					}
					if (CP >= 2) {
						printf("레이저 포인터를 구매했습니다.\n");
						CP -= 2;
						printf("보유 CP %d 포인트\n", CP);
						laserPointer = 1;
					}
					else {
						printf("CP가 부족합니다.\n");
					}
					break;
				case 3:
					if (scratcher == 1) {
						printf("스크래처를 이미 구매했습니다.\n");
						break;
					}
					if (CP >= 4) {
						printf("스크래처를 구매했습니다.\n");
						CP -= 4;
						printf("보유 CP %d 포인트\n", CP);
						scratcher = 1;
						scratcher_where = rand() % (ROOM_WIDTH - 2) + 1; // 스크래처 위치 랜덤 설정
						while (scratcher_where == HME_POS || scratcher_where == BWL_PO) {
							scratcher_where = rand() % (ROOM_WIDTH - 2) + 1; // 스크래처 위치가 집이나 냄비에 겹치지 않도록
						}


					}
					else {
						printf("CP가 부족합니다.\n");
					}
					break;
				case 4:
					if (cat_tower == 1) {
						printf("캣타워를 이미 구매했습니다.\n");
						break;
					}
					if (CP >= 6) {
						printf("캣타워를 구매했습니다.\n");
						CP -= 6;
						printf("보유 CP %d 포인트\n", CP);
						cat_tower = 1;
						cat_tower_where = rand() % (ROOM_WIDTH - 2) + 1; // 캣타워 위치 랜덤 설정
						while (cat_tower_where == HME_POS || cat_tower_where == BWL_PO || cat_tower_where == scratcher_where) {
							cat_tower_where = rand() % (ROOM_WIDTH - 2) + 1; // 캣타워 위치가 집이나 냄비에 겹치지 않도록
						}
					}
					else {
						printf("CP가 부족합니다.\n");
					}
					break;
				default:
					break;
				}
				break;
			}
		}
		Sleep(2500);
		system("cls");

		//

		

		
		turn++;
		}




		return 0;

	}

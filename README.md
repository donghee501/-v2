# 야옹이와 수프 v2

- 학번: 20210483 / 이름: 이동희
- 
## v1 기본 기능 및 상태창 추가 내용(2-1, 2-2)
- 고양이 이름 입력 및 고양이 모양 출력
- 수프 만들기: 냄비 위치에 도달 시 랜덤 수프 1개 생성
- 기분(0~3), 친밀도(0~4), 수프 개수 상태창 출력
- 기분 및 친밀도 변화 확률 구현

## v2 추가 기능
- 기분 기반 행동(2-3):
  - 기분 0: 집으로 이동
  - 기분 1: 더 가까운 놀이기구 쪽으로 이동 (없을 경우 기분 하락)
  - 기분 2: 제자리 대기
  - 기분 3: 냄비 쪽으로 이동
  - 
- 고양이가 이동한 위치에 따라 다음 행동 수행 (2-4):
  - **집(H) 위치에 제자리 대기 중**이면 → 기분 +1 (단, 막 들어왔을 때는 제외)
  - **냄비(B) 위치**면 → 수프를 1개 만들고, 수프 종류(양송이/브로콜리/감자)는 무작위로 출력됨
  - **스크래처(S) 위치**면 → 기분 +1 (`feel++`)
  - **캣타워(T) 위치**면 → 기분 +2 (`feel += 2`)
  - 
-상호작용 확장 (2-5): 장난감 쥐, 레이저 포인터 구매 및 사용 가능

- 매 턴 상호작용을 선택, 선택지는 물품 구매 현황에 따라 변경 (2-6):
  - 0: 아무것도 하지 않음
    - 기분 -1 (최소 0), 5/6 확률로 친밀도 -1
  - 1: 긁어주기
    - 기분 변화 없음, 2/6 확률로 친밀도 +1
  - 2: 장난감 쥐로 놀기 (보유 시)
    - 기분 +1, 3/6 확률로 친밀도 +1
  - 3: 레이저 포인터로 놀기 (보유 시)
    - 기분 +2, 5/6 확률로 친밀도 +1

- CP 생산 (2-7): MAX(0, 기분–1) + 친밀도 공식 적용
  
- 상점 시스템 구현(2-8):
  - CP로 장난감 쥐(1), 레이저 포인터(2), 스크래처(4), 캣타워(6) 구매 가능
  - 위치 겹침 방지 로직 포함
  - 스크래처(S), 캣타워(T) 랜덤 위치 설정 및 방 출력 구현

## 돌발 퀘스트(2-9)
- 매 3턴마다 등장
- 고양이의 현재 기분과 친밀도를 입력받는 퀴즈
- 성공 시 즉시 게임 종료 및 최종 상태 출력
- 실패 시 게임 계속 진행됨



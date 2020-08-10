//Binary search tree using Array
//Data Structure HW3
//2016037069 한재윤

#include<stdio.h>
#include<math.h>  //자식값을 한 레벨 상승시킬때 pow명령문을 사용하기 위해 추가했습니다. 

#define ARRAYINDEX 2046 //트리 레벨 10까지 배열크기 
#define LEVELSIZE 10 //트리레벨 10
#define AN 0 //트리값 0으로 초기화 (포인터와 다르게 정수형 배열은 NULL개념이 없으므로 초기화를 특정 정수로 초기화)
#define PARENTS (i-1)/2 //이진탐색트리의 부모
#define CHILDLEFT i * 2 + 1 //이진탐색트리 왼쪽자식
#define CHILDRIGHT i * 2 + 2 //이진탐색트리 오른쪽자식

int BSTarray[ARRAYINDEX] = { AN, }; //트리 배열 선언 후 초기화
int i = 0; //트리 인덱스 전역변수 선언

//트리에 값 추가
Insert(int x) {
	if (BSTarray[0] == AN ) { //root에 값이 없을경우
		BSTarray[0] = x;
		printf("%d 값을 트리에 추가하였습니다.\n", x);
	}
	else if (x < BSTarray[i]) { //추가할 값이 트리값보다 작으면
		if (BSTarray[CHILDLEFT] != AN) { //왼쪽 자식이 존재하면
			i = CHILDLEFT;			//왼쪽 자식노드위치로 이동후
			return Insert(x);		//재귀함수 호출
		}
		else {
			BSTarray[CHILDLEFT] = x; //해당 위치에 추가할 값을 추가
			printf("%d 값을 트리에 추가하였습니다.\n",x);
		}
	}
	else if (BSTarray[i] < x) { //추가할 값이 트리값보다 크면
		if (BSTarray[CHILDRIGHT] != AN) { // 오른쪽 자식이 존재할경우
			i = CHILDRIGHT;  //오른쪽 자식 위치로 이동
			return Insert(x);  //재귀함수 호출
		}
		else {
			BSTarray[CHILDRIGHT] = x;  //왼쪽 또는 오른쪽 자식위치로 이동하여 값이 없을 경우 해당위치에 값 추가
			printf("%d 값을 트리에 추가하였습니다. \n",x);
		}
	}
	else printf("%d 가 같은 값이 트리에 존재합니다.\n", x);  //위의 조건문을 만족하지못하면 이미 값이 있음
}

//찾으려는 트리 위치 찾는 함수(배열인덱스값 찾기)
Search(int x) { 
	if (BSTarray[0] == x) //root트리값이 찾으려는 값이면 찾으려는 값 반환
		return i;

	else if (x < BSTarray[i]) { //찾으려는 값이 트리값보다 작을 경우
		if (BSTarray[CHILDLEFT] == AN) {  //왼쪽자식에 아무것도 없는 경우
			printf("%d 값을 찾을 수 없습니다.\n", x); 
			return; // 함수 종료
		}
		else if ((BSTarray[CHILDLEFT] !=x) && (BSTarray[CHILDLEFT] != AN)) { //왼쪽값이 찾으려는 트리값이 아니며 오른쪽 자식에 값이 있을때
			if (x < BSTarray[i]) {//찾으려는 값이 해당값보다 작은경우
				i = CHILDLEFT;  //왼쪽자식으로 이동
				return Search(x); //재귀함수 호출
			}
			else if (BSTarray[i] < x) {  //찾으려는 트리값이 오른쪽보다 클경우
				i = CHILDRIGHT;  // 오른쪽자식 위치로 이동
				return Search(x); //재귀함수 
			}
		}

		else {
			if (BSTarray[CHILDLEFT] == x) 
				return CHILDLEFT;
		}
	}

	else if (BSTarray[i] < x) {
		if (BSTarray[CHILDRIGHT] == AN) {
			printf("%d 값을 찾을 수 없습니다.\n", x);
		}

		else if (BSTarray[CHILDRIGHT] != x && BSTarray[CHILDRIGHT] != AN) {
			if (x < BSTarray[i]) {
				i = CHILDLEFT;
				return Search(x);
			}
			else if (BSTarray[i] < x) {
				i = CHILDRIGHT;
				return Search(x);
			}
		}

		else {
			if (BSTarray[CHILDRIGHT] == x)
				return CHILDRIGHT;
		}
	}

	else {
	printf("%d 값을 찾을 수 없습니다.\n", x);
	return -1;
	}
}

Delete(int x) { //트리 삭제
	int storeI = 0; // i값 임시저장 변수
	i = Search(x); //삭제할 트리 위치 찾기
	storeI = i;
	int L = 0;

	//삭제하려는 트리의 자식이 없는 경우 >>> 해당 트리값 삭제
	if ((BSTarray[CHILDLEFT] == AN) && (BSTarray[CHILDRIGHT] == AN)) {
		if (BSTarray[i] == x) {
			BSTarray[i] = AN;
			printf("%d 값을 삭제하였습니다.\n", x);
		}
		else {
			printf("삭제하려는 트리값이 없습니다.\n");
			return 0;
		}
	}

	//자식이 하나인경우
	else if (((BSTarray[CHILDLEFT] == AN) && (BSTarray[CHILDRIGHT] != AN)) || ((BSTarray[CHILDLEFT] != AN) && (BSTarray[CHILDRIGHT] == AN))) {
		//왼쪽자식 없으면 >>> 오른쪽 자식을 삭제한 트리 자리로 이동한다. 
		if ((BSTarray[CHILDLEFT] == AN) && (BSTarray[CHILDRIGHT] != AN)) {
			int L = LEVEL(i);  //삭제할 트리의 레벨을 계산
			RIGHT_CHILD_move_PARENTS(L);  //삭제한 트리 하위트리값들을 한레벨씩 위로 올림
			printf("%d 값을 삭제하였습니다.\n", x);
		}

		//오른쪽 자식없으면 >>> 왼쪽 자식을 삭제한 트리 자리로 이동한다. 
		else if ((BSTarray[CHILDLEFT] != AN) && (BSTarray[CHILDRIGHT] == AN)) {
			int L = LEVEL(i);  //삭제할 트리의 레벨을 계산
			LEFT_CHILD_move_PARENTS(L);  //삭제한 트리 하위트리값들을 한레벨씩 위로 올림
			printf("%d 값을 삭제하였습니다.\n", x);
		}
	}

	//자식이 둘다 있는 경우
	else if ((BSTarray[CHILDLEFT] != AN) && (BSTarray[CHILDRIGHT] != AN)) 
{		/*
		후계자를 왼쪽 하위트리에서 가장 큰 값 또는 오른쪽 하위트리에서 가장 작은값으로 후계자를 정할 수 있지만
		이 코드에서는 삭제 대상 트리를 기준으로 왼쪽 하위트리에서 가장 큰 값을 후계자로 지목
		왼쪽하위 트리에서 후계자를 지목할때, 자식이 없거나 왼쪽 자식만 가지고 있는 경우의 수밖에 발생하지 않음.*/
		i = CHILDLEFT;
		while (1)
		{
			if(BSTarray[CHILDRIGHT] == AN)
				break;
			i = CHILDRIGHT;
		}

		if ((BSTarray[CHILDLEFT] == AN) && (BSTarray[CHILDLEFT] == AN)) {
				BSTarray[storeI] = BSTarray[i];
				BSTarray[i] = AN;
		}

		//후계자가 하나의 왼쪽 자식을 가지고 있는경우 
		else if (BSTarray[CHILDLEFT] != AN && (BSTarray[CHILDRIGHT] == AN)) {
			BSTarray[PARENTS] = BSTarray[i];
			BSTarray[i] = AN; 
			L = LEVEL(i);  //후계자로 지목된 
			LEFT_CHILD_move_PARENTS(L);
		}
		
		printf("%d 값을 삭제하였습니다.\n", x);
	}

	else {
		printf("%d 값이 트리에 없습니다.\n", x);
	}
}

//전위 순회 탐색
PrintPreorder(int i) {
	if (BSTarray[i] != AN) {
		printf("%d_", BSTarray[i]);
		PrintPreorder(CHILDLEFT);
		PrintPreorder(CHILDRIGHT);
	}
}

//중위 순회 탐색
PrintInorder(int i) {
	if (BSTarray[i] != AN) {
		PrintInorder(CHILDLEFT);
		printf("%d_", BSTarray[i]);
		PrintInorder(CHILDRIGHT);
	}
}

//중위 순회 탐색
PrintPostorder(int i) {
	if (BSTarray[i] != AN) {
		PrintPostorder(CHILDLEFT);
		PrintPostorder(CHILDRIGHT);
		printf("%d_", BSTarray[i]);
	}
}

//트리값의 위치가 어느 레벨에 있는지 찾기 (ROOT 트리값 = 0 레벨)
int LEVEL(int L) { //인덱스로 레벨 구분 함수
	if      (L == 0) {                     return 0;  }
	else if ((1 <= L) && (L <= 2)) {       return 1;  }
	else if ((3 <= L) && (L <= 6)) {       return 2;  }
	else if ((7 <= L) && (L <= 14)) {      return 3;  }
	else if ((15 <= L) && (L <= 30)) {     return 4;  }
	else if ((31 <= L) && (L <= 62)) {     return 5;  }
	else if ((63 <= L) && (L <= 126)) {    return 6;  }
	else if ((127 <= L) && (L <= 254)) {   return 7;  }
	else if ((255 <= L) && (L <= 510)) {   return 8;  }
	else if ((511 <= L) && (L <= 1022)) {  return 9;  }
	else if ((1023 <= L) && (L <= 2046)) { return 10; }
	else if ((2047 <= L) && (L <= 4094)) { return 11; }
	else if ((4095 <= L) && (L <= 8190)) { return 12; }
	else if ((8191 <= L) && (L <= 16382)) { return 13; }
	else if ((16383 <= L) && (L <= 32766)) { return 14; }
	else if ((32767 <= L) && (L <= 65534)) { return 15; }
}

//자식노드가 하나있을 때 오른쪽 자식의 하위 트리들을 레벨 1씩 올림
int RIGHT_CHILD_move_PARENTS(int storeLEVEL) {
	int LEVEL = storeLEVEL;
	int countLEVEL;
	int sum = 0;
	for (countLEVEL = 0; countLEVEL <= LEVELSIZE - LEVEL-2; countLEVEL++)
	{//LEVELSIZE - LEVEL-2 을 한 이유가 전체 레벨(10) 중에서 마지막 레벨의 자식트리는 존재하지 않으며, 삭제할 레벨의 노드는 연산에서 제외하여야 하기때문입니다.
		int maxminus = pow(2, countLEVEL) - 1;
		for (int minus = 0; minus <= maxminus; minus++)
		{
			BSTarray[i - minus] = BSTarray[CHILDRIGHT - minus];
			BSTarray[CHILDRIGHT - minus] = AN;
		}
		i = CHILDRIGHT;
		if (i > ARRAYINDEX) {
			break;
		}
	}
}

//자식노드가 하나있을 때 왼쪽 자식의 하위 트리들을 레벨 1씩 올림
int LEFT_CHILD_move_PARENTS(int storeLEVEL) {
	int LEVEL = storeLEVEL;
	int countLEVEL;
	for (countLEVEL = 0; countLEVEL <= LEVELSIZE - LEVEL-2; countLEVEL++)
	{
		int maxminus = pow(2, countLEVEL) - 1;
		for (int add = 0; add <= maxminus; add++)
		{
			BSTarray[i + add] = BSTarray[CHILDLEFT + add];
			BSTarray[CHILDLEFT + add] = AN;
		}
		i = CHILDLEFT;
		if (i > ARRAYINDEX) {
			break;
		}
	}
}

int main() {
	printf("■■■■■■■■■■■■■■■■■\n");
	printf("■Binary Search Tree using Array■\n");
	printf("■       2016037069 한재윤      ■\n");
	printf("■      Data Structure HW3      ■\n");
	printf("■■■■■■■■■■■■■■■■■\n\n");

	//Notice!!! >>> 아래명령문으로 함수호출시 전역변수 i = AN; 선언 후 함수 호출 하시기 바랍니다.
	//Notice!!! >>> i = AN;을 선언하지 않을시 트리 배열 인덱스를 가리키는 i값이 초기화 되지않아 제대로 동작하지 않습니다.
	//Notice!!! >>> 정수형 배열이므로 실수형, 문자형은 사용할 수 없습니다.
	//Notice!!! >>> 이 코드의 이진 탐색 트리는 최대 레벨 10까지 구현하였습니다. (root = 0레벨)

	//Given Example (주어진 예제, 직접 함수 호출)
	/*
	i = AN; Insert(5);
	i = AN; Insert(2);
	i = AN; Insert(3);
	i = AN; Insert(1);
	i = AN; Insert(8);
	i = AN; Insert(10);
	i = AN; Insert(9);
	i = AN; Insert(6);
	i = AN; printf("Inorder Traversal: "); PrintInorder(i); printf("\n");
	i = AN; printf("\n");
	i = AN; Delete(2);
	i = AN; printf("Inorder Traversal: "); PrintInorder(i); printf("\n");
	i = AN; printf("\n");
	i = AN; Delete(5);
	i = AN; printf("Inorder Traversal: "); PrintInorder(i); printf("\n");
	i = AN; printf("\n");
	*/
	
	//R&D: 트리값 임의 설정 (버그수정용, 주석처리)
	
	//LV: 0
	BSTarray[0] = 1; //A

	//LV: 1
	BSTarray[1] = 2; //H
	BSTarray[2] = 3; //D

	//LV: 2
	BSTarray[3] = 4; //C
	BSTarray[4] = 5; //B
	BSTarray[5] = 6; //E
	BSTarray[6] = 7; //G

	//LV: 3
	//BSTarray[7] = 12;
	BSTarray[8] = 8; //I
	//BSTarray[9] = 6;
	//BSTarray[10] = 7;
	//BSTarray[11] = 112;
	//BSTarray[12] = 140;
	//BSTarray[13] = 165;
	//STarray[14] = 8;

	i = AN; printf("전위탐색: "); PrintPreorder(i); printf("\n");
	i = AN; printf("중위탐색: "); PrintInorder(i); printf("\n");
	i = AN; printf("후위탐색: "); PrintPostorder(i); printf("\n");

	/*
	//LV: 4
	//BSTarray[15] = 6;
	//BSTarray[16] = 18;
	//BSTarray[17] = 35;
	//BSTarray[18] = 45;
	BSTarray[19] = 57;
	BSTarray[20] = 68;
	BSTarray[21] = 88;
	BSTarray[22] = 97;
	BSTarray[23] = 106;
	BSTarray[24] = 118;
	BSTarray[25] = 135;
	BSTarray[26] = 145;
	BSTarray[27] = 157;
	BSTarray[28] = 168;
	BSTarray[29] = 188;
	BSTarray[30] = 207;

	//LV: 5
	BSTarray[31] = AN;
	BSTarray[32] = AN;
	BSTarray[33] = AN;
	BSTarray[34] = AN;
	BSTarray[35] = AN;
	BSTarray[36] = AN;
	BSTarray[37] = AN;
	BSTarray[38] = AN;
	BSTarray[39] = AN;
	BSTarray[40] = AN;
	BSTarray[41] = AN;
	BSTarray[42] = AN;
	BSTarray[43] = AN;
	BSTarray[44] = AN;
	BSTarray[45] = AN;
	BSTarray[46] = AN;
	BSTarray[47] = AN;
	BSTarray[48] = AN;
	BSTarray[49] = AN;
	BSTarray[50] = AN;
	BSTarray[51] = AN;
	BSTarray[52] = AN;
	BSTarray[53] = AN;
	BSTarray[54] = AN;
	BSTarray[55] = AN;
	BSTarray[56] = AN;
	BSTarray[57] = AN;
	BSTarray[58] = AN;
	BSTarray[59] = AN;
	BSTarray[60] = AN;
	BSTarray[61] = AN;
	BSTarray[62] = AN;
	*/

	/*
	//do-while, switch기능 (코딩실력 늘릴겸 한번 추가해 보았습니다....)
	int function_switch = 0;
	int insertnumber = 0;
	int deletenumber = 0;
	do {
		printf("\n1.Insert  2.Delete  3.PrintInorder 4.프로그램종료");
		printf("\n사용할 기능을 입력하세요. (1,2,3,4) : ");
		scanf_s("%d", &function_switch);
		switch (function_switch) {

		case 1:
			i = AN;
			printf("트리에 추가할 값을 정수로 입력하세요. (0은 넣을 수 없습니다.) : ");
			scanf_s("%d", &insertnumber);
			if (insertnumber == 0) {
				printf("0을 입력할 수 없습니다. 다시 입력해주세요:");
				break;
			}
			Insert(insertnumber);
			break;
		case 2:
			i = AN;
			printf("트리에 삭제할 값을 정수로 입력하세요. (0은 넣을 수 없습니다.) : ");
			scanf_s("%d", &deletenumber);
			if (deletenumber == 0) {
				printf("0을 입력할 수 없습니다. 다시 입력해주세요:");
				break;
			}
			Delete(deletenumber);
			break;

		case 3:
			i = AN;
			printf("Inorder Traversal: ");
			PrintInorder(i);
			printf("\n");
			break;

		case 4:
			printf("프로그램을 종료합니다.");
			break;

		default:
			printf("지원하지 않는 기능입니다. 다시 입력하세요.\n");
			break;
		}
	} while (function_switch != 4);
	*/
}

/*
Log..
20.05.18 : Insert제작
20.05.19 : Insert수정, Delete제작
20.05.20 : Insert완성, Search제작
20.05.21 : Search제작, Level완성
20.05.22 : PrintInorder완성
20.05.23 : Delete완성, 버그발견 (왼쪽 자식 하위트리를 1레벨씩 올리는 과정에서 연산 오류)
20.05.24 : 버그수정 및 코드 가독성 향상, 메인함수 스위치문 추가
20.05.30 : 최종수정 및 테스트
*/

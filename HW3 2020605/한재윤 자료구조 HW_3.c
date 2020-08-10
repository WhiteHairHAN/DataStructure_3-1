//Binary search tree using Array
//Data Structure HW3
//2016037069 ������

#include<stdio.h>
#include<math.h>  //�ڽİ��� �� ���� ��½�ų�� pow��ɹ��� ����ϱ� ���� �߰��߽��ϴ�. 

#define ARRAYINDEX 2046 //Ʈ�� ���� 10���� �迭ũ�� 
#define LEVELSIZE 10 //Ʈ������ 10
#define AN 0 //Ʈ���� 0���� �ʱ�ȭ (�����Ϳ� �ٸ��� ������ �迭�� NULL������ �����Ƿ� �ʱ�ȭ�� Ư�� ������ �ʱ�ȭ)
#define PARENTS (i-1)/2 //����Ž��Ʈ���� �θ�
#define CHILDLEFT i * 2 + 1 //����Ž��Ʈ�� �����ڽ�
#define CHILDRIGHT i * 2 + 2 //����Ž��Ʈ�� �������ڽ�

int BSTarray[ARRAYINDEX] = { AN, }; //Ʈ�� �迭 ���� �� �ʱ�ȭ
int i = 0; //Ʈ�� �ε��� �������� ����

//Ʈ���� �� �߰�
Insert(int x) {
	if (BSTarray[0] == AN ) { //root�� ���� �������
		BSTarray[0] = x;
		printf("%d ���� Ʈ���� �߰��Ͽ����ϴ�.\n", x);
	}
	else if (x < BSTarray[i]) { //�߰��� ���� Ʈ�������� ������
		if (BSTarray[CHILDLEFT] != AN) { //���� �ڽ��� �����ϸ�
			i = CHILDLEFT;			//���� �ڽĳ����ġ�� �̵���
			return Insert(x);		//����Լ� ȣ��
		}
		else {
			BSTarray[CHILDLEFT] = x; //�ش� ��ġ�� �߰��� ���� �߰�
			printf("%d ���� Ʈ���� �߰��Ͽ����ϴ�.\n",x);
		}
	}
	else if (BSTarray[i] < x) { //�߰��� ���� Ʈ�������� ũ��
		if (BSTarray[CHILDRIGHT] != AN) { // ������ �ڽ��� �����Ұ��
			i = CHILDRIGHT;  //������ �ڽ� ��ġ�� �̵�
			return Insert(x);  //����Լ� ȣ��
		}
		else {
			BSTarray[CHILDRIGHT] = x;  //���� �Ǵ� ������ �ڽ���ġ�� �̵��Ͽ� ���� ���� ��� �ش���ġ�� �� �߰�
			printf("%d ���� Ʈ���� �߰��Ͽ����ϴ�. \n",x);
		}
	}
	else printf("%d �� ���� ���� Ʈ���� �����մϴ�.\n", x);  //���� ���ǹ��� �����������ϸ� �̹� ���� ����
}

//ã������ Ʈ�� ��ġ ã�� �Լ�(�迭�ε����� ã��)
Search(int x) { 
	if (BSTarray[0] == x) //rootƮ������ ã������ ���̸� ã������ �� ��ȯ
		return i;

	else if (x < BSTarray[i]) { //ã������ ���� Ʈ�������� ���� ���
		if (BSTarray[CHILDLEFT] == AN) {  //�����ڽĿ� �ƹ��͵� ���� ���
			printf("%d ���� ã�� �� �����ϴ�.\n", x); 
			return; // �Լ� ����
		}
		else if ((BSTarray[CHILDLEFT] !=x) && (BSTarray[CHILDLEFT] != AN)) { //���ʰ��� ã������ Ʈ������ �ƴϸ� ������ �ڽĿ� ���� ������
			if (x < BSTarray[i]) {//ã������ ���� �ش簪���� �������
				i = CHILDLEFT;  //�����ڽ����� �̵�
				return Search(x); //����Լ� ȣ��
			}
			else if (BSTarray[i] < x) {  //ã������ Ʈ������ �����ʺ��� Ŭ���
				i = CHILDRIGHT;  // �������ڽ� ��ġ�� �̵�
				return Search(x); //����Լ� 
			}
		}

		else {
			if (BSTarray[CHILDLEFT] == x) 
				return CHILDLEFT;
		}
	}

	else if (BSTarray[i] < x) {
		if (BSTarray[CHILDRIGHT] == AN) {
			printf("%d ���� ã�� �� �����ϴ�.\n", x);
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
	printf("%d ���� ã�� �� �����ϴ�.\n", x);
	return -1;
	}
}

Delete(int x) { //Ʈ�� ����
	int storeI = 0; // i�� �ӽ����� ����
	i = Search(x); //������ Ʈ�� ��ġ ã��
	storeI = i;
	int L = 0;

	//�����Ϸ��� Ʈ���� �ڽ��� ���� ��� >>> �ش� Ʈ���� ����
	if ((BSTarray[CHILDLEFT] == AN) && (BSTarray[CHILDRIGHT] == AN)) {
		if (BSTarray[i] == x) {
			BSTarray[i] = AN;
			printf("%d ���� �����Ͽ����ϴ�.\n", x);
		}
		else {
			printf("�����Ϸ��� Ʈ������ �����ϴ�.\n");
			return 0;
		}
	}

	//�ڽ��� �ϳ��ΰ��
	else if (((BSTarray[CHILDLEFT] == AN) && (BSTarray[CHILDRIGHT] != AN)) || ((BSTarray[CHILDLEFT] != AN) && (BSTarray[CHILDRIGHT] == AN))) {
		//�����ڽ� ������ >>> ������ �ڽ��� ������ Ʈ�� �ڸ��� �̵��Ѵ�. 
		if ((BSTarray[CHILDLEFT] == AN) && (BSTarray[CHILDRIGHT] != AN)) {
			int L = LEVEL(i);  //������ Ʈ���� ������ ���
			RIGHT_CHILD_move_PARENTS(L);  //������ Ʈ�� ����Ʈ�������� �ѷ����� ���� �ø�
			printf("%d ���� �����Ͽ����ϴ�.\n", x);
		}

		//������ �ڽľ����� >>> ���� �ڽ��� ������ Ʈ�� �ڸ��� �̵��Ѵ�. 
		else if ((BSTarray[CHILDLEFT] != AN) && (BSTarray[CHILDRIGHT] == AN)) {
			int L = LEVEL(i);  //������ Ʈ���� ������ ���
			LEFT_CHILD_move_PARENTS(L);  //������ Ʈ�� ����Ʈ�������� �ѷ����� ���� �ø�
			printf("%d ���� �����Ͽ����ϴ�.\n", x);
		}
	}

	//�ڽ��� �Ѵ� �ִ� ���
	else if ((BSTarray[CHILDLEFT] != AN) && (BSTarray[CHILDRIGHT] != AN)) 
{		/*
		�İ��ڸ� ���� ����Ʈ������ ���� ū �� �Ǵ� ������ ����Ʈ������ ���� ���������� �İ��ڸ� ���� �� ������
		�� �ڵ忡���� ���� ��� Ʈ���� �������� ���� ����Ʈ������ ���� ū ���� �İ��ڷ� ����
		�������� Ʈ������ �İ��ڸ� �����Ҷ�, �ڽ��� ���ų� ���� �ڽĸ� ������ �ִ� ����� ���ۿ� �߻����� ����.*/
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

		//�İ��ڰ� �ϳ��� ���� �ڽ��� ������ �ִ°�� 
		else if (BSTarray[CHILDLEFT] != AN && (BSTarray[CHILDRIGHT] == AN)) {
			BSTarray[PARENTS] = BSTarray[i];
			BSTarray[i] = AN; 
			L = LEVEL(i);  //�İ��ڷ� ����� 
			LEFT_CHILD_move_PARENTS(L);
		}
		
		printf("%d ���� �����Ͽ����ϴ�.\n", x);
	}

	else {
		printf("%d ���� Ʈ���� �����ϴ�.\n", x);
	}
}

//���� ��ȸ Ž��
PrintPreorder(int i) {
	if (BSTarray[i] != AN) {
		printf("%d_", BSTarray[i]);
		PrintPreorder(CHILDLEFT);
		PrintPreorder(CHILDRIGHT);
	}
}

//���� ��ȸ Ž��
PrintInorder(int i) {
	if (BSTarray[i] != AN) {
		PrintInorder(CHILDLEFT);
		printf("%d_", BSTarray[i]);
		PrintInorder(CHILDRIGHT);
	}
}

//���� ��ȸ Ž��
PrintPostorder(int i) {
	if (BSTarray[i] != AN) {
		PrintPostorder(CHILDLEFT);
		PrintPostorder(CHILDRIGHT);
		printf("%d_", BSTarray[i]);
	}
}

//Ʈ������ ��ġ�� ��� ������ �ִ��� ã�� (ROOT Ʈ���� = 0 ����)
int LEVEL(int L) { //�ε����� ���� ���� �Լ�
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

//�ڽĳ�尡 �ϳ����� �� ������ �ڽ��� ���� Ʈ������ ���� 1�� �ø�
int RIGHT_CHILD_move_PARENTS(int storeLEVEL) {
	int LEVEL = storeLEVEL;
	int countLEVEL;
	int sum = 0;
	for (countLEVEL = 0; countLEVEL <= LEVELSIZE - LEVEL-2; countLEVEL++)
	{//LEVELSIZE - LEVEL-2 �� �� ������ ��ü ����(10) �߿��� ������ ������ �ڽ�Ʈ���� �������� ������, ������ ������ ���� ���꿡�� �����Ͽ��� �ϱ⶧���Դϴ�.
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

//�ڽĳ�尡 �ϳ����� �� ���� �ڽ��� ���� Ʈ������ ���� 1�� �ø�
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
	printf("������������������\n");
	printf("��Binary Search Tree using Array��\n");
	printf("��       2016037069 ������      ��\n");
	printf("��      Data Structure HW3      ��\n");
	printf("������������������\n\n");

	//Notice!!! >>> �Ʒ���ɹ����� �Լ�ȣ��� �������� i = AN; ���� �� �Լ� ȣ�� �Ͻñ� �ٶ��ϴ�.
	//Notice!!! >>> i = AN;�� �������� ������ Ʈ�� �迭 �ε����� ����Ű�� i���� �ʱ�ȭ �����ʾ� ����� �������� �ʽ��ϴ�.
	//Notice!!! >>> ������ �迭�̹Ƿ� �Ǽ���, �������� ����� �� �����ϴ�.
	//Notice!!! >>> �� �ڵ��� ���� Ž�� Ʈ���� �ִ� ���� 10���� �����Ͽ����ϴ�. (root = 0����)

	//Given Example (�־��� ����, ���� �Լ� ȣ��)
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
	
	//R&D: Ʈ���� ���� ���� (���׼�����, �ּ�ó��)
	
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

	i = AN; printf("����Ž��: "); PrintPreorder(i); printf("\n");
	i = AN; printf("����Ž��: "); PrintInorder(i); printf("\n");
	i = AN; printf("����Ž��: "); PrintPostorder(i); printf("\n");

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
	//do-while, switch��� (�ڵ��Ƿ� �ø��� �ѹ� �߰��� ���ҽ��ϴ�....)
	int function_switch = 0;
	int insertnumber = 0;
	int deletenumber = 0;
	do {
		printf("\n1.Insert  2.Delete  3.PrintInorder 4.���α׷�����");
		printf("\n����� ����� �Է��ϼ���. (1,2,3,4) : ");
		scanf_s("%d", &function_switch);
		switch (function_switch) {

		case 1:
			i = AN;
			printf("Ʈ���� �߰��� ���� ������ �Է��ϼ���. (0�� ���� �� �����ϴ�.) : ");
			scanf_s("%d", &insertnumber);
			if (insertnumber == 0) {
				printf("0�� �Է��� �� �����ϴ�. �ٽ� �Է����ּ���:");
				break;
			}
			Insert(insertnumber);
			break;
		case 2:
			i = AN;
			printf("Ʈ���� ������ ���� ������ �Է��ϼ���. (0�� ���� �� �����ϴ�.) : ");
			scanf_s("%d", &deletenumber);
			if (deletenumber == 0) {
				printf("0�� �Է��� �� �����ϴ�. �ٽ� �Է����ּ���:");
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
			printf("���α׷��� �����մϴ�.");
			break;

		default:
			printf("�������� �ʴ� ����Դϴ�. �ٽ� �Է��ϼ���.\n");
			break;
		}
	} while (function_switch != 4);
	*/
}

/*
Log..
20.05.18 : Insert����
20.05.19 : Insert����, Delete����
20.05.20 : Insert�ϼ�, Search����
20.05.21 : Search����, Level�ϼ�
20.05.22 : PrintInorder�ϼ�
20.05.23 : Delete�ϼ�, ���׹߰� (���� �ڽ� ����Ʈ���� 1������ �ø��� �������� ���� ����)
20.05.24 : ���׼��� �� �ڵ� ������ ���, �����Լ� ����ġ�� �߰�
20.05.30 : �������� �� �׽�Ʈ
*/

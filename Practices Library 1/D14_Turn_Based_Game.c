/*
回合制游戏《传奇霸业，是兄弟就来干》 
游戏规则：
小春(HP == a)遇到了一只黄金哥布林(HP == x)。 
小春每次能对哥布林造成b点伤害，哥布林每次能对小春造成y点伤害。 
作为玩家的小春怎么可能随便让哥布林打死呢！他有治疗神药，每次能恢复c点HP。 HP无上限。
小春先攻击，一方一个回合，如果小春的血量在下回合承受不住哥布林的一次攻击时就会回血。小春
需要操作多少次才能打死哥布林？（治疗次数+攻击次数）输出最小操作次数。
*/
#include <stdio.h>
#include <stdlib.h>
int solution(int a, int b, int c, int x, int y) {
	int s=0;
	while(x>0) {
		if(b>=x) 	//下一回合可以打死哥布林
        {
			s++;
			x-=b;
			break;	//哥布林死亡就结束
		}
		if(a<=y) 	//如果小春的血量在下回合承受不住哥布林的一次攻击时就会回血
        {
			a+=c;
			a-=y;
			s++;
			continue;
		}
		s++;
		x-=b;	//攻击哥布林
		a-=y;	//被哥布林攻击
	}
	return s;
}
int main() {
	int arr1[3],sum;
    printf("输入小春的血量 攻击力 治疗量：");
	for (int i = 0; i < 3; i++) {
		scanf("%d", &arr1[i]);
	}
	int player_hp = arr1[0];	//player_hp = a
	int player_attack = arr1[1];	//player_attack = b
	int c = arr1[2];
	int arr2[2];
    printf("输入哥布林的血量 攻击力：");
	for (int i = 0; i < 2; i++) {
		scanf("%d", &arr2[i]);
	}
	int monster_hp = arr2[0];	//monster_hp = x
	int monster_attack = arr2[1];	//monster_attack = y
	sum=solution(player_hp, player_attack, c,monster_hp, monster_attack);
    printf("最小操作次数（治疗次数+攻击次数）:%d\n",sum);
    system("pause");
	return 0;
}

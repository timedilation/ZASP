//2019/03/09 복습 -- 전역변수 사용 안하고 짜는 방법
/** 동전이 있는데 25센트, 10센트, 5센트, 1센트 짜리가 있는데 액수를 만들수 있는 가짓수를 구하는 함수
input: 액수
output: 가짓수 **/

public static int ans=0; 
public static void returnMoney(int Money, int LastMoney){
    if(Money>=25 && LastMoney>25){
		for(int i=1;i<=Money/25;i++){
			ans++;
			returnMoney(Money-25*i, 25); 
    }
	}
	if(Money>=10 && LastMoney>10){
		for(int i=1;i<=Money/10;i++){
			ans++;
			returnMoney(Money-10*i, 10);
    }
  }
  if(Money>=5 && LastMoney>5){
	  for(int i=1;i<=Money/5;i++){
		  ans++;
			returnMoney(Money-5*i, 5);
    }
  }
  if(Money>0){
	  ans++;
	  return;
   }
}
public static int num_of_way(int money){
  returnMoney(money,26);
	return ans;
}




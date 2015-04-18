#include <iostream>
using namespace std;
int kt[15][6]={
 {3, 0, 11, 10},
 {4, 9, 17, 12, 1},
 {5, 8, 16, 18, 13, 2},
 {4, 7, 15, 14, 3},
 {3, 4, 5, 6},
 {3, 0, 1, 2},        
 {4, 11, 12, 13, 3},
 {5, 10, 17, 18, 14, 4},
 {4, 9, 16, 15, 5},
 {3, 8, 7, 6},
 {3, 2, 3, 4},          
 {4, 1, 13, 14, 5},
 {5, 0, 12, 18, 15, 6}, 
 {4, 11, 17, 16, 7},
 {3, 8, 9, 10}          
};
int x[19];   
int m[20];   
int nghiem;  

//1 == OK
//0 == not ok
int check() {
  for (int i = 0; i < 15; i++) {
	 int t = 0;                 
	 int ok = 1;                
	 for (int j = 1; j <= kt[i][0]; j++) {  
		t += x[kt[i][j]];                   
		if (x[kt[i][j]] == 0) ok = 0;       
	 }
	 if (t != 38 && ok == 1) return 0;      
	 if (t >= 38 && ok == 0) return 0;      
  }
  return 1;                                
}

void Init() {
  nghiem = 0;
  for (int i = 0; i<=18; i++) {           
	 x[i] = 0;  
	 m[i + 1] = 0;
  }
}

void show() {
  //if (nghiem) return;                    //b? qua d? in m?i nghi?m
  cout << "Nghiem " << ++nghiem << ": ";
  for (int i = 0; i < 19; i++)          
	 cout << x[i] << " ";               
  cout << endl;                         
}

//fill number 1..19 to box i
void Try(int i) {                       
  //if (nghiem) return;                 
  for (int j = 1; j <= 19; j++)         
	 if (!m[j]) {                       
		x[i] = j;                       
		m[j] = 1;                       
		if (check())                    
		  if (i == 18) show();          
		  else Try(i + 1);              
		x[i] = 0;                       
		m[j] = 0;                       
	 }
}
int main() {
  Init();
  Try(0);
  cout <<"bye\n";
  return 0;
}
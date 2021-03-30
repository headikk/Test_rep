#include <iostream>
#include <queue>  
 
using namespace std;
 
int main() {
  queue <int> q; 
  
  cout << "Введите 7 чисел: " << endl;
 
  for (int h = 0; h < 7; h++) { 
    int a; 
    
    cin >> a;
      
    q.push(a);  
  }
  
  cout << endl;
  cout << "Самый первый элемент в очереди: " << q.front() << endl;  
  
  q.pop();// удаляем элемент из очереди
    
  cout << "Новый первый элемент (после удаления): " << q.front() << endl;
    
  if (!q.empty()) cout << "Очередь не пуста!" << endl; 
  
  cout << "Размер очереди:" << q.size() << endl;
    
  return 0;
}

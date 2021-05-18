#include<iostream>
#include<string.h>
#define max 15
using namespace std;
template<class T>
class List
{
private:
	 T *begin,*end;
	 int vk1;
	 T*v;
	 T value;
public:
	 List(int size);
	 ~List() { delete[]v; };
	 void Add(T value);
	 void Delete(T value,int size);
	 void Print();
	 void Sum(T value, T value1);
};
template<class T>
List<T>::List(int size) {
	 v = new T[size];
	 vk1 = 0;
}
template<class T> void
List<T>::Add(T value) {
	 if (begin == NULL) {
		  v[vk1] = value;
		  begin = &v[vk1];
	 }
	 v[vk1++] = value;
	 end = &v[vk1-1];
}
template<class T> void
List<T>::Print() {
	 int i = 0;
	 v[i] = *begin;
	 cout << "\n Черга:" << endl;
	 for (; &v[i] < end; i++) {
		  cout << v[i]<<" ";
	 }
}
template<class T> void
List<T>::Delete(T value,int size) {
	 for (int i = 0; i < size; i++) {
		  if (v[i] == value) {
				if (&v[i] == begin) {
					 begin = &v[i + 1];
					 v[i] = NULL;
				}
				if (&v[i] == end) {
					 end = &v[i - 1];
					 v[i] = NULL;
				}
				if (&v[i] != begin && &v[i] != end) {
					 for (; &v[i] != end; i++) {
						  v[i] = v[i+1];
					 }
					 v[i] = NULL;

				}
		  }
	 }
}
template<class T> void
List<T>::Sum(T value, T value1) {
	 T Sum = value + value1;
	 cout <<"\n Сума елементів:"<<Sum;
}
int main() {
	 system("chcp 1251");
	 int data[max];
	 int size = max;
	 for (int i = 0; i < max; i++) {
		  cin >> data[i];
		  if (data[i] == 000) {
				size = i;
				break;
		  }
	 }
	 int*p[max];
	 for (int i = 0; i < size; i++) {
		  p[i] = &data[i];
	 }
	 List<int>stack(size);
	 for (int i = 0; i < size; i++) {
		  stack.Add(*p[i]);
	 }
	 stack.Print();
	 stack.Delete(*p[3],size);
	 stack.Sum(*p[2], *p[4]);
	 stack.Print();
}
	
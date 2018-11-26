//��FIFO�������ڶ����еĹ�����ʽ�� 
//���µ�Ŀ���ǰ����㣺 ��� FIFO �Ͷ��еĶ��壻 �ܹ��Լ�ʵ�ֶ��У� 
//��Ϥ���ö��нṹ�� ʹ�ö���������򵥵����⡣
//
//�����ȳ������ݽṹ
//
//���� - ʵ��
//
//ѭ������
//
//���ѭ������
//
//ѭ������ - ʵ��
//
//���� - �÷�
//Moving Average from Data Stream
//
//
//���к͹����������
//�Ⱦ����������Ĳ������ �������������BFS����һ�ֱ������������ݽṹ��������ͼ�����㷨�� 
//��ǰ���������ǿ���ʹ�� BFS ������ִ�в�������� ����Ҳ����ʹ�� BFS ����ͼ��
//���磬���ǿ���ʹ�� BFS �ҵ�����ʼ��㵽Ŀ�����·�����ر������·����
//���ǿ����ڸ�������龰��ʹ�� BFS �������п��ܵ�״̬��
//����������£����ǿ��԰�״̬������ͼ�еĽ�㣬���ԺϷ��Ĺ���·����Ϊͼ�еıߡ� 
//���½��У����ǽ���Ҫ���� BFS ����ι����ģ������ع�ע������ΰ�������ʵ�� BFS �㷨��
//���ǻ����ṩһЩ��ϰ������������ƺ�ʵ�� BFS �㷨��
//
//
//ջ�������ȳ������ݽṹ
//���½��У����ǽ�������һ�ִ���˳������ȳ���LIFO����
//�Լ���Ӧ�����ݽṹ��ջ�� ��ɱ��½ں��㽫�� ��� LIFO �� ջ�Ķ��壻
//�ܹ��ö�̬����ʵ��ջ�� ��Ϥ����ջ�ṹ�� �ܹ�ʹ��ջ������⡣
//
//
//ջ�������������
//�Ⱦ����������ı��� �� BFS ���ƣ�
//�������������DFS������������ / ͼ�б��� / ��������һ����Ҫ�㷨��
//Ҳ�����ڸ�����ĳ�����ʹ�á� �������ı��������ᵽ�ģ����ǿ����� DFS ���� ǰ�������
//��������ͺ��������������������˳������һ����ͬ�����ԣ��������ǵ�������Ľ�㣬����������Զ������ݡ�
//��Ҳ�� DFS �� BFS ֮����������BFS��Զ��������̽�����������Ѿ��ڵ�ǰ�㼶���������н�㡣
//ͨ��������ʹ�õݹ�ʵ�� DFS��ջ�ڵݹ���������Ҫ�����á��ڱ����У����ǽ�������ִ�еݹ�ʱջ�����á�
//���ǻ�������չʾ�ݹ��ȱ�㣬���ṩ��һ��û�еݹ�� DFS ʵ�֡� ��׼������ʱ��DFS ��һ����Ҫ�Ļ��⡣
//DFS ��ʵ�����������졣�����ص����ջ������� DFS ��Ӧ�õģ�����������õ���� DFS ��ԭ��
//Ҫ��ͨ DFS �㷨������Ҫ��������ϰ��
//
//
//С��
//��ǰ����½��У����ǽ������������ݽṹ�����к�ջ 
//1. ���� ������һ�� FIFO ʽ�����ݽṹ����һ��Ԫ�ؽ������ȴ���
//��������Ҫ��������Ӻͳ��ӡ����ǿ���ʹ�ô�������ָ��Ķ�̬������ʵ�ֶ��С� 
//���ǿ���ʹ�ù������������BFS���� ���л���һЩ��Ҫ����չ��
//���磺 ˫�˶��� ���ȶ��� �����ں���Ŀ�Ƭ�н�����Щ�ṹ�� 
//2. ջ ջ��һ�� LIFO ʽ�����ݽṹ�����һ��Ԫ�ؽ������ȴ���
//��������Ҫ������push �� pop��ջ��ʵ�ַǳ��򵥣�ʹ�ö�̬���������ʵ��ջ��
//������ LIFO ԭ��ʱ������ʹ��ջ���������������DFS����ջ��һ����ҪӦ�á� 
//3. �ܽ� ��֮����Ӧ���ܹ����ͱȽ����¼����� FIFO �� LIFO�� ���� �� ջ�� BFS �� DFS��
//Ҫ��������������⣬��õİ취����ѵ�������½��У�����Ϊ���ṩ�˸�����ϰ��
//
//��ǰ����
//���ѭ������
//
//
//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ��
//��������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ�
//���ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
//���ʵ��Ӧ��֧�����²�����
//MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//	Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//		   enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//		   deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
//		   isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
//		   isFull() : ���ѭ�������Ƿ�������


#include<iostream>
using namespace std;

class MyCircularQueue {
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		_array = new int[k];
		_left = 0;
		_right = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (_left - 1 != _right)
		{
			_array[_left++] = value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (_left != _right)
		{
			_left++;
			return true;
		}
		else
		{
			return false;
		}
	}

	/** Get the front item from the queue. */
	int Front() {
		return _array[_left];
	}

	/** Get the last item from the queue. */
	int Rear() {
		return _array[_right];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		if (_right == _left)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		if (_right + 1 == _left)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	int *_array;
	int _left;
	int _right;
};

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue obj = new MyCircularQueue(k);
* bool param_1 = obj.enQueue(value);
* bool param_2 = obj.deQueue();
* int param_3 = obj.Front();
* int param_4 = obj.Rear();
* bool param_5 = obj.isEmpty();
* bool param_6 = obj.isFull();
*/

int main()
{
	MyCircularQueue q(3);
	cout << q.isEmpty() << endl;
	cout << q.enQueue(1) << endl;
	cout << q.enQueue(2) << endl;
	cout << q.enQueue(3) << endl;
	cout << q.deQueue() << endl;
	cout << q.Front() << endl;
	cout << q.Rear() << endl;
	cout << q.isFull() << endl;
	system("pause");
	return 0;
}
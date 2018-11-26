//（FIFO）及其在队列中的工作方式。 
//本章的目的是帮助你： 理解 FIFO 和队列的定义； 能够自己实现队列； 
//熟悉内置队列结构； 使用队列来解决简单的问题。
//
//先入先出的数据结构
//
//队列 - 实现
//
//循环队列
//
//设计循环队列
//
//循环队列 - 实现
//
//队列 - 用法
//Moving Average from Data Stream
//
//
//队列和广度优先搜索
//先决条件：树的层序遍历 广度优先搜索（BFS）是一种遍历或搜索数据结构（如树或图）的算法。 
//如前所述，我们可以使用 BFS 在树中执行层序遍历。 我们也可以使用 BFS 遍历图。
//例如，我们可以使用 BFS 找到从起始结点到目标结点的路径，特别是最短路径。
//我们可以在更抽象的情景中使用 BFS 遍历所有可能的状态。
//在这种情况下，我们可以把状态看作是图中的结点，而以合法的过渡路径作为图中的边。 
//本章节中，我们将简要介绍 BFS 是如何工作的，并着重关注队列如何帮助我们实现 BFS 算法。
//我们还将提供一些练习，供你自行设计和实现 BFS 算法。
//
//
//栈：后入先出的数据结构
//本章节中，我们将介绍另一种处理顺序后入先出（LIFO），
//以及相应的数据结构，栈。 完成本章节后，你将： 理解 LIFO 和 栈的定义；
//能够用动态数组实现栈； 熟悉内置栈结构； 能够使用栈解决问题。
//
//
//栈和深度优先搜索
//先决条件：树的遍历 与 BFS 类似，
//深度优先搜索（DFS）是用于在树 / 图中遍历 / 搜索的另一种重要算法。
//也可以在更抽象的场景中使用。 正如树的遍历中所提到的，我们可以用 DFS 进行 前序遍历，
//中序遍历和后序遍历。在这三个遍历顺序中有一个共同的特性：除非我们到达最深的结点，否则我们永远不会回溯。
//这也是 DFS 和 BFS 之间最大的区别，BFS永远不会深入探索，除非它已经在当前层级访问了所有结点。
//通常，我们使用递归实现 DFS。栈在递归中起着重要的作用。在本章中，我们将解释在执行递归时栈的作用。
//我们还将向你展示递归的缺点，并提供另一个没有递归的 DFS 实现。 在准备面试时，DFS 是一个重要的话题。
//DFS 的实际设计因题而异。本章重点介绍栈是如何在 DFS 中应用的，并帮助你更好地理解 DFS 的原理。
//要精通 DFS 算法，还需要大量的练习。
//
//
//小结
//在前面的章节中，我们介绍了两个数据结构：队列和栈 
//1. 队列 队列是一种 FIFO 式的数据结构：第一个元素将被首先处理。
//有两个重要操作：入队和出队。我们可以使用带有两个指针的动态数组来实现队列。 
//我们可以使用广度优先搜索（BFS）。 队列还有一些重要的扩展，
//例如： 双端队列 优先队列 我们在后面的卡片中介绍这些结构。 
//2. 栈 栈是一种 LIFO 式的数据结构：最后一个元素将被首先处理。
//有两个重要操作：push 和 pop。栈的实现非常简单，使用动态数组就足以实现栈。
//当满足 LIFO 原则时，我们使用栈。深度优先搜索（DFS）是栈的一个重要应用。 
//3. 总结 总之，你应该能够理解和比较以下几组概念： FIFO 和 LIFO； 队列 和 栈； BFS 和 DFS。
//要熟练掌握这个主题，最好的办法就是训练。本章节中，我们为你提供了更多练习。
//
//向前往后
//设计循环队列
//
//
//设计你的循环队列实现。 循环队列是一种线性数据结构，
//其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，
//我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
//你的实现应该支持如下操作：
//MyCircularQueue(k) : 构造器，设置队列长度为 k 。
//Front : 从队首获取元素。如果队列为空，返回 - 1 。
//	Rear : 获取队尾元素。如果队列为空，返回 - 1 。
//		   enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
//		   deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
//		   isEmpty() : 检查循环队列是否为空。
//		   isFull() : 检查循环队列是否已满。


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
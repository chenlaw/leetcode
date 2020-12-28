#include <thread>
#include<iostream>
#include<mutex>
using namespace std;
// ��Ʊ������100��
volatile int tickets = 100;
// ȫ�ֵĻ�����
std::mutex mtx;

// �̺߳���
void sellTicketTask(std::string wndName)
{
	while (tickets > 0)
	{
		// ��ȡ��������Դ
		mtx.lock();
		if (tickets > 0)
		{
			std::cout << wndName << " ������" << tickets << "��Ʊ" << std::endl;
			tickets--;
		}
		// �ͷŻ�������Դ
		mtx.unlock();

		// ÿ����һ��Ʊ��˯��100ms����ÿ�����ڶ��л�����Ʊ

	}
}

// ģ�⳵վ������Ʊ��ʹ��C++11 �̻߳�����mutex
int main()
{
	// ��������ģ�ⴰ����Ʊ�߳�
	std::thread t1(sellTicketTask, "��Ʊ����һ");
	std::thread t2(sellTicketTask, "��Ʊ���ڶ�");
	std::thread t3(sellTicketTask, "��Ʊ������");

	// �ȴ������߳�ִ�����
	t1.join();
	t2.join();
	t3.join();

	return 0;
}

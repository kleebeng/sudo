#include "pch.h"
#include "CppUnitTest.h"
#include"../sudoku/func.cpp"
//ע�⣬�����·��������Ҫ�ֶ��޸�

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			//����Խ��ֵ
			int a = produceOutputIntoTxt(0);
			int b = produceOutputIntoTxt(1000001);
			int c = produceOutputIntoTxt(-1);
			Assert::AreEqual(a, -1);
			Assert::AreEqual(b, -1);
			Assert::AreEqual(c, -1);
		}
		TEST_METHOD(TestMethod2)
		{
			//����ֵ
			int a = produceOutputIntoTxt(1000);
			Assert::AreEqual(a, 0);
		}
		TEST_METHOD(TestMethod3)
		{
			//������ȷ�ľŹ���λ��
			int a = getBlockNum(3, 3);
			Assert::AreEqual(a, 4);
		}
		TEST_METHOD(TestMethod4)
		{
			//���Դ���ľŹ���λ��
			int a = getBlockNum(0, 9);
			Assert::AreEqual(a, -1);
		}
		TEST_METHOD(TestMethod5)
		{
			//������ȷ����flag
			setFlag(1, 2, 3, 1);
			int a = getBlockNum(1, 2);
			Assert::AreEqual(DEAL::col_count[2][3], 1);
			Assert::AreEqual(DEAL::row_count[1][3], 1);
			Assert::AreEqual(DEAL::block_count[a][3], 1);
		}
		TEST_METHOD(TestMethod6)
		{
			int a = dealQuestion("asdfadsfadga");//���Դ���·��
			Assert::AreEqual(a, -1);
		}
		TEST_METHOD(TestMethod7)
		{
			int a = dealQuestion("pro.txt");//���Դ����ļ��������ʽ����
			Assert::AreEqual(a, -1);
		}
		TEST_METHOD(TestMethod8)
		{
			int a = dealQuestion("ques.txt");//������ȷ�ļ�
			Assert::AreEqual(a, 0);		//����0
		}
		TEST_METHOD(TestMethod9)
		{
			int a = dfs(1, 1);		//����dfs������ȷ
			Assert::AreEqual(a, 1);			//����true
		}
		TEST_METHOD(TestMethod10)
		{
			memset(DEAL::col_count, 1, sizeof(DEAL::col_count));
			int a = dfs(0, 100);
			Assert::AreEqual(a, 0);		//���Դ����dfs������false
		}
		TEST_METHOD(TestMethod11)
		{
			memset(DEAL::col_count, 0, sizeof(DEAL::col_count));
			memset(DEAL::row_count, 0, sizeof(DEAL::row_count));
			memset(DEAL::block_count, 0, sizeof(DEAL::block_count));
			int a = judge(2, 2, 2);		//���Է�����ȷ��judge
			Assert::AreEqual(a, 1);
		}
	};
}

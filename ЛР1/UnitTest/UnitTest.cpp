#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab1/List.h"
#include "../Lab1/List.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(BiListTest)
	{
	public:
		BiList Empty;
		BiList NotEmpty;
		TEST_METHOD_INITIALIZE(SetUp)
		{
			for (size_t i = 0; i < 3; i++)
				NotEmpty.push_back(i + 1);
		}
		TEST_METHOD(IsEmpty_for_NotEmpty)
		{
			Assert::AreEqual(NotEmpty.isEmpty(), false);
		}
		TEST_METHOD(IsEmpty_for_Empty)
		{
			Assert::AreEqual(Empty.isEmpty(), true);
		}
		TEST_METHOD(Get_Size_for_Empty)
		{
			size_t real_size = 0;
			Assert::AreEqual(Empty.get_size(), real_size);
		}
		TEST_METHOD(Get_Size_for_NotEmpty)
		{
			size_t real_size = 3;
			Assert::AreEqual(NotEmpty.get_size(), real_size);
		}
		TEST_METHOD(at_correct_index)
		{
			Assert::AreEqual(NotEmpty.at(2), 2);
		}
		TEST_METHOD(at_incorrect_index)
		{
			try
			{
				Empty.at(4);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Incorrect index.");
			}
		}
		TEST_METHOD(Push_Back_NotEmpty)
		{
			NotEmpty.push_back(5);
			Assert::AreEqual(NotEmpty.at(4), 5);
		}
		TEST_METHOD(Push_Front_NotEmpty)
		{
			NotEmpty.push_front(0);
			Assert::AreEqual(NotEmpty.at(1), 0);
		}
		TEST_METHOD(remove_correct_index)
		{
			int temp = NotEmpty.at(3);
			NotEmpty.remove(2);
			Assert::AreEqual(NotEmpty.at(2), temp);
		}
		TEST_METHOD(Pop_Back_for_NotEmpty)
		{
			size_t real_size = NotEmpty.get_size() - 1;
			NotEmpty.pop_back();
			Assert::AreEqual(NotEmpty.get_size(), real_size);
		}
		TEST_METHOD(Pop_Back_for_Empty)
		{
			Empty.pop_back();
			Assert::AreEqual(Empty.isEmpty(), true);
		}
		TEST_METHOD(Pop_Front_for_NotEmpty)
		{
			size_t real_size = NotEmpty.get_size() - 1;
			NotEmpty.pop_front();
			Assert::AreEqual(NotEmpty.get_size(), real_size);
		}
		TEST_METHOD(insert_correct_index)
		{
			NotEmpty.insert(4, 1);
			Assert::AreEqual(NotEmpty.at(2), 4);
		}
		TEST_METHOD(insert_incorrect_index)
		{
			try
			{
				Empty.insert(2, 0);
			}
			catch (const char* error)
			{
				Assert::AreEqual("Incorrect index.", error);
			}
		}
		TEST_METHOD(remove_incorrect_index)
		{
			try
			{
				Empty.remove(2);
			}
			catch (const char* error)
			{
				Assert::AreEqual("Incorrect index.", error);
			}
		}
		TEST_METHOD(reverse_for_NotEmpty)
		{
			int last_inf = NotEmpty.at(NotEmpty.get_size());
			NotEmpty.reverse();
			Assert::AreEqual(NotEmpty.at(1), last_inf);
		}
		TEST_METHOD(Pop_Front_for_Empty)
		{
			Empty.pop_front();
			Assert::AreEqual(Empty.isEmpty(), true);
		}
		TEST_METHOD(set_correct_index)
		{
			NotEmpty.set(2, 3);
			Assert::AreEqual(NotEmpty.at(2), 3);
		}
		TEST_METHOD(set_incorrect_index)
		{
			try
			{
				NotEmpty.set(10000000, 2);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Incorrect index.");
			}
		}
		TEST_METHOD(Test_Clear_NotEmpty)
		{
			NotEmpty.clear();
			size_t real_size = 0;
			Assert::AreEqual(NotEmpty.get_size(), real_size);
		}
		TEST_METHOD(Test_Clear_Empty)
		{
			Empty.clear();
			size_t real_size = 0;
			Assert::AreEqual(Empty.get_size(), real_size);
		}
		TEST_METHOD(Push_Back_Empty)
		{
			Empty.push_back(5);
			Assert::AreEqual(Empty.at(1), 5);
			Empty.pop_back();
		}
		TEST_METHOD(Push_Front_Empty)
		{
			Empty.push_front(0);
			Assert::AreEqual(Empty.at(1), 0);
		}
	};
}

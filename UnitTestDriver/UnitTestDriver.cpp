#include "pch.h"
#include "CppUnitTest.h"
#include "../Task_Manager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDriver
{
	TEST_CLASS(UnitTestDriver)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Task t = create_task(1, "Test Task", priority_1);
			Assert::AreEqual(1, t.id);
			Assert::AreEqual("Test Task", t.description);
			Assert::AreEqual((int)priority_1, (int)t.priority);
			Assert::AreEqual((int)status_not_started, (int)t.status);

		}
		TEST_METHOD(TestMethod2)
		{
			Task tasks[max_tasks];
			int count = 0;
			Task t = create_task(1, "Task 1", priority_2);

			int result = add_task(tasks, &count, t);

			Assert::AreEqual(0, result);
			Assert::AreEqual(1, count);
			Assert::AreEqual(1, tasks[0].id);
			Assert::AreEqual("Task 1", tasks[0].description);
			Assert::AreEqual((int)priority_2, (int)tasks[0].priority);
		}
		TEST_METHOD(TestMethod3)
		{
			Task tasks[max_tasks];
			int count = 0;

			add_task(tasks, &count, create_task(1, "P1", priority_1));
			add_task(tasks, &count, create_task(2, "P2", priority_2));
			add_task(tasks, &count, create_task(3, "P3", priority_3));

			int deleted = delete_tasks(tasks, &count, priority_1);

			Assert::AreEqual(2, deleted);
			Assert::AreEqual(1, count);
			Assert::AreEqual(2, tasks[0].id);

		}
		
		TEST_METHOD(TestMethod4) 
		{
			Task tasks[max_tasks];
			int count = 0;

			add_task(tasks, &count, create_task(1, "do something", priority_3));
			int updated = mark_task_complete(tasks, count, 1);

			Assert::AreEqual(1, updated);
			Assert::AreEqual((int)status_completed, (int)tasks[0].status);
		}

		TEST_METHOD(TestMethod5) 
		{
			Task tasks[max_tasks];
			int count = 0;

			add_task(tasks, &count, create_task(1, "do it", priority_3));

			int updated = mark_task_complete(tasks, count, 99);
			Assert::AreEqual(0, updated);
			Assert::AreEqual((int)status_not_started, (int)tasks[0].status);
		}
	};
}

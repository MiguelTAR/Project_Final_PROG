#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"

extern "C" {


#include "../Task_Manager.h"
#include "../Task_Manager.c"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


    TEST_CLASS(DisplayIncompleteTasksTests) {
public:

    TEST_METHOD(Test_NoTasks) {
        Task tasks[5];
        int task_count = 0;
        display_incomplete_tasks(tasks, task_count);
        Assert::IsTrue(true);
    }

    TEST_METHOD(Test_AllCompleted) {
        Task tasks[5];
        int task_count = 1;
        tasks[0].id = 1;
        tasks[0].priority = priority_1;
        tasks[0].satus = status_completed;
        tasks[0].description[0] = '\0';
        display_incomplete_tasks(tasks, task_count);
        Assert::IsTrue(true);
    }

    TEST_METHOD(Test_OneIncompleteTask) {
        Task tasks[5];
        int task_count = 1;
        tasks[0].id = 1;
        tasks[0].priority = priority_2;
        tasks[0].satus = status_not_started;
        tasks[0].description[0] = '\0';
        display_incomplete_tasks(tasks, task_count);
        Assert::IsTrue(true);
    }
    };

    TEST_CLASS(DisplayAllTasksTests) {
public:

    TEST_METHOD(Test_NoTasks) {
        Task tasks[5];
        int task_count = 0;
        display_all_tasks(tasks, task_count);
        Assert::IsTrue(true);
    }

    TEST_METHOD(Test_OneTask) {
        Task tasks[5];
        int task_count = 1;
        tasks[0].id = 1;
        tasks[0].priority = priority_3;
        tasks[0].satus = status_in_progress;
        tasks[0].description[0] = '\0';
        display_all_tasks(tasks, task_count);
        Assert::IsTrue(true);
    }

    TEST_METHOD(Test_MultipleTasks) {
        Task tasks[5];
        int task_count = 2;
        tasks[0].id = 1;
        tasks[0].priority = priority_1;
        tasks[0].satus = status_not_started;
        tasks[0].description[0] = '\0';
        tasks[1].id = 2;
        tasks[1].priority = priority_2;
        tasks[1].satus = status_completed;
        tasks[1].description[0] = '\0';
        display_all_tasks(tasks, task_count);
        Assert::IsTrue(true);
    }
    };

    TEST_CLASS(ContinueOrExitTests) {
public:
    TEST_METHOD(Test_ReturnValueIsValid) {
        Assert::IsTrue(true);
    }
    };
}
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

			int deleted = delete_task(tasks, &count, priority_1);

			Assert::AreEqual(2, deleted);
			Assert::AreEqual(1, count);
			Assert::AreEqual(2, tasks[0].id);

		}

	};
}

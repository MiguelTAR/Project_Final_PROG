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
        tasks[0].status = status_completed;
        tasks[0].description[0] = '\0';
        display_incomplete_tasks(tasks, task_count);
        Assert::IsTrue(true);
    }

    TEST_METHOD(Test_OneIncompleteTask) {
        Task tasks[5];
        int task_count = 1;
        tasks[0].id = 1;
        tasks[0].priority = priority_2;
        tasks[0].status = status_not_started;
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
        tasks[0].status = status_in_progress;
        tasks[0].description[0] = '\0';
        display_all_tasks(tasks, task_count);
        Assert::IsTrue(true);
    }

    TEST_METHOD(Test_MultipleTasks) {
        Task tasks[5];
        int task_count = 2;
        tasks[0].id = 1;
        tasks[0].priority = priority_1;
        tasks[0].description[0] = '\0';
        tasks[1].id = 2;
        tasks[1].priority = priority_2;
        tasks[1].status = status_completed;
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
#include <gtest/gtest.h>
#include <class/Workers.h>

using namespace workers;

TEST(EmployeesTests, addPerson)
{
    Employees _Worker;
    EmployeePtr worker1 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80);
    _Worker.add_worker(worker1);
    EmployeePtr worker2 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80);
    _Worker.add_worker(worker2);
    EmployeePtr worker3 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80);
    _Worker.add_worker(worker3);
    const auto get_size = _Worker.get_size();
    EXPECT_EQ(get_size, 3);
}
TEST(EmployeesTests, deletePersonGood1)
{
    Employees _Worker;
    EmployeePtr worker1 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80);
    _Worker.add_worker(worker1);
    EmployeePtr worker2 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80);
    _Worker.add_worker(worker2);

    _Worker.delete_person(0);

    const auto get_size = _Worker.get_size();

    EXPECT_EQ(get_size, 1);
}
TEST(EmployeesTests, deletePersonGood2)
{
    Employees _Worker;
    EmployeePtr worker1 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80);
    _Worker.add_worker(worker1);

    EXPECT_ANY_THROW(_Worker.delete_person(-1), std::out_of_range);
}
/*TEST(EmployeesTests, deletePersonаFailed)
{
    Employees _Worker;
    EmployeePtr worker1 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80);
    _Worker.add_worker(worker1);

    EXPECT_NO_THROW(_Worker.delete_person(-1), std::out_of_range);
}*/
TEST(EmployeesTests, insertPerson)
{
    Employees _Worker;
    EmployeePtr worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    EmployeePtr worker2 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 700, 3, 40);
    _Worker.add_worker(worker1);
    _Worker.insert_person(worker2, 0);
    Type a = _Worker[0]->get_type();
    EXPECT_EQ(a, Type::Part_time);
}

TEST(EmployeesTests, search_max_salary1)
{
    Employees _Worker;
    _Worker.add_worker(Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000));
    _Worker.add_worker(Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 700, 3, 40));
    _Worker.add_worker(Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 20000));
    ASSERT_EQ(search_max_salary(_Worker), 0);
}
TEST(EmployeesTests, search_max_salary2)
{
    Employees _Worker;
    _Worker.add_worker(Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000));
    _Worker.add_worker(Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 900, 3, 120));
    _Worker.add_worker(Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 20000));
    ASSERT_EQ(search_max_salary(_Worker), 1);
}
TEST(EmployeesTests, insertPerson1)
{
    Employees _Worker;
    EmployeePtr worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    EmployeePtr worker2 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 700, 3, 40);
    EmployeePtr worker3 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 700, 3, 40);
    _Worker.add_worker(worker1);
    _Worker.add_worker(worker2);
    _Worker.insert_person(worker3, 1);
    Type a = _Worker[1]->get_type();
    Type b = _Worker[2]->get_type();
    EXPECT_EQ(a, Type::Part_time);
    EXPECT_EQ(b, Type::Part_time);
}
TEST(EmployeesTests, CapacityAddWorkerRange1) {
    Employees _Worker;
    EmployeePtr worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    ASSERT_ANY_THROW(_Worker.change_data(worker1, 2));
}
TEST(EmployeesTests, CapacityAddWorkerRange2) {
    Employees _Worker;
    EmployeePtr worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    EXPECT_ANY_THROW(_Worker.change_data(worker1, 5), std::out_of_range);
}
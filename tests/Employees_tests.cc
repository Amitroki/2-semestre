#include <gtest/gtest.h>
#include <class/Workers.h>

using namespace workers;

TEST(EmployeesTests, CapacityCheck) {
    Employees _Worker;
    Employee worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    for (int i = 0; i < Employees::CAPACITY; i++) {
        _Worker.add1(worker1);
    }
    ASSERT_ANY_THROW(_Worker.add1(worker1));
}
TEST(EmployeesTests, deletePerson)
{
    Employees _Worker;
    Employee worker1 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80);
    _Worker.add1(worker1);
    _Worker.add1(worker1);
    _Worker.add1(worker1);

    _Worker.delete_person(1);

    Type a = _Worker[1].get_type();

    EXPECT_EQ(a, Type::Part_time);
}
TEST(EmployeesTests, insertPerson)
{
    Employees _Worker;
    Employee worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    Employee worker2 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 700, 3, 40);
    _Worker.add1(worker1);
    _Worker.insert_person(worker2, 0);
    Type a = _Worker[0].get_type();
    EXPECT_EQ(a, Type::Part_time);

}
TEST(EmployeesTests, search_max_salary)
{
    Employees _Worker;
    _Worker.add1(Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000));
    _Worker.add1(Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 700, 3, 40));
    _Worker.add1(Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 20000));
    ASSERT_EQ(search_max_salary(_Worker), 0);

}
TEST(EmployeesTests, search_max_salary1)
{
    Employees _Worker;
    _Worker.add1(Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000));
    _Worker.add1(Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 900, 3, 120));
    _Worker.add1(Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 20000));
    ASSERT_EQ(search_max_salary(_Worker), 1);

}
TEST(EmployeesTests, deletePerson2)
{
    Employees _Worker;
    Employee worker1 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80);
    _Worker.add1(worker1);

    EXPECT_ANY_THROW(_Worker.delete_person(-1), out_of_range);
}
/*TEST(EmployeesTests, deletePerson1)
{
    Employees _Worker;
    Employee worker1 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 400, 5, 80);

    EXPECT_NO_THROW(_Worker.delete_person(-1), out_of_range);
}
TEST(EmployeesTests, insertPerson1)
{
    Employees _Worker;
    Employee worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    Employee worker2 = Employee::create_part_time("Иван", "Иванов", "Иванович", 13, 12, 2013, 700, 3, 40);
    _Worker.add1(worker1);
    _Worker.insert_person(worker2, -1);
    Type a = _Worker[0].get_type();
    EXPECT_EQ(a, Type::Part_time);

}
TEST(EmployeesTests, CapacityCheck1) {
    Employees _Worker;
    Employee worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    for (int i = 0; i < Employees::CAPACITY + 2; i++) {
        _Worker.add1(worker1);
    }
    ASSERT_ANY_THROW(_Worker.add1(worker1));

}*/
TEST(EmployeesTests, CapacityAdd1Runtime1) {
    Employees _Worker;
    Employee worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    ASSERT_NO_THROW(_Worker.add2(worker1, 2), std::runtime_error);
}
TEST(EmployeesTests, CapacityAdd1Runtime2) {
    Employees _Worker;
    Employee worker1 = Employee::create_full_time("Иван", "Иванов", "Иванович", 13, 12, 2003, 54000);
    ASSERT_NO_THROW(_Worker.add2(worker1, 3), std::runtime_error);
    EXPECT_NO_THROW(_Worker.add2(worker1, 5), std::runtime_error);
}
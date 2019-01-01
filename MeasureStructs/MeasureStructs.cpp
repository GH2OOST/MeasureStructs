#include "pch.h"
#include "Person.h"
#include "BigFieldsPerson.h"

using namespace std;

#define ITERATIONS_COUNT 100000

void function_that_takes_pointer(Person*);
void function_that_takes_value(Person);
int measure_function(const function<void()>);
int measure_person_pointer();
int measure_person_value();
void function_that_takes_big_fields_pointer(BigFieldsPerson* person);
void function_that_takes_big_fields_value(BigFieldsPerson person);
int measure_big_fields_person_pointer();
int measure_big_fields_person_value();

int main()
{
	auto time_for_pointer = measure_person_pointer();
	auto time_for_value = measure_person_value();
	cout << "when small passed as pointer: " << time_for_pointer << " ms" << endl;
	cout << "when small passed as value: " << time_for_value << " ms" << endl;
	time_for_pointer = measure_big_fields_person_pointer();
	time_for_value = measure_big_fields_person_value();
	cout << "when big passed as pointer: " << time_for_pointer << " ms" << endl;
	cout << "when big passed as value: " << time_for_value << " ms" << endl;
	system("pause");
	return 0;
}

int measure_big_fields_person_pointer()
{
	auto person = new BigFieldsPerson();
	auto time = measure_function([person]() { function_that_takes_big_fields_pointer(person); });
	delete person;
	return time;
}

int measure_big_fields_person_value()
{
	BigFieldsPerson person;
	auto time = measure_function([person]() { function_that_takes_big_fields_value(person); });
	return time;
}

int measure_person_pointer()
{
	auto person = new Person();
	auto time = measure_function([person]() { function_that_takes_pointer(person); });
	delete person;
	return time;
}

int measure_person_value()
{
	Person person;
	auto time = measure_function([person]() { function_that_takes_value(person); });
	return time;
}

int measure_function(const function<void()> func)
{
	func();
	auto begin = clock();
	for (size_t i = 0; i < ITERATIONS_COUNT; i++)
		func();
	auto elapsed = (double)(clock() - begin);
	return elapsed;
}

void function_that_takes_pointer(Person* person)
{
	return;
}

void function_that_takes_value(Person person)
{
	return;
}

void function_that_takes_big_fields_pointer(BigFieldsPerson* person)
{
	return;
}

void function_that_takes_big_fields_value(BigFieldsPerson person)
{
	return;
}
#pragma once

#include <string_view>

class Car
{
public:
	virtual ~Car() = default;  // �׻� ���� �Ҹ��ڷ� �����Ѵ�.
	virtual std::string_view info() const = 0;
};

class Ford : public Car
{
public:
	virtual std::string_view info() const override { return "Ford"; }
};

class Toyota : public Car
{
public:
	virtual std::string_view info() const override { return "Toyota"; }
};

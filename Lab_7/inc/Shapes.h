#pragma once

enum class Color
{
    WHITE,
    BLUE,
    GREEN
};

struct Point
{
    double m_x = 0;
    double m_y = 0;
};

class Shape
{
protected:
    Point m_p;
    Color m_color;
    double m_width = 0;
    double m_height = 0;
public:
    Shape(Point p, double width, double height) : m_p(p), m_width(width),
        m_height(height)
    {}

    virtual ~Shape() = default;

    void setColor(Color color)
    {
        m_color = color;
    }

    virtual double Square()
    {
        return m_width * m_height;
    }
};

class Triangle : public Shape
{
public:
    Triangle(Point p, double width, double height) : Shape(p, width, height) {}

    ~Triangle() override = default;

    double Square() override
    {
        return (m_width * m_height * 0.5);
    }
};

class Circle : public Shape
{
private:
    double& m_radius = m_width;
public:
    Circle(Point p, double radius) : Shape(p, radius, 0) {}

    ~Circle() override = default;

    double Square() override
    {
        return (pow(m_radius, 2) * acos(-1));
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(Point p, double width, double height) : Shape(p, width, height) {}

    ~Rectangle() override = default;
};
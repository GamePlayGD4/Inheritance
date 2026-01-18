#define _USE_MATH_DEFINES
#include<Windows.h>
#include<iostream>
#include<math.h> // for PI
using namespace std;

enum Color
{
	Red = 0x000000FF,
	Green = 0x0000FF00,
	Blue = 0x00FF0000,
	Yellow = 0x0000FFFF,
	Purple = 0x00800080,
	White = 0x00FFFFFF,
	Black = 0x00000000,
};

#define SHAPE_TAKE_PARAMETERS int start_x, int start_y, int line_width, Color color
#define SHAPE_GIVE_PARAMETERS start_x, start_y, line_width, color

class Shape
{
	static const int MIN_START_X = 100;
	static const int MIN_START_Y = 100;
	static const int MAX_START_X = 1000;
	static const int MAX_START_Y = 700;
	static const int MIN_LINE_WIDTH = 1;
	static const int MAX_LINE_WIDTH = 32;
protected:
	Color color;
	int start_x;
	int start_y;
	int line_width;
public:
	int get_start_x()const
	{
		return start_x;
	}
	int get_start_y()const
	{
		return start_y;
	}
	int get_line_width()const
	{
		return line_width;
	}
	void set_start_x(int start_x)
	{
		if (start_x < MIN_START_X)start_x = MIN_START_X;
		if (start_x > MAX_START_X)start_x = MAX_START_X;
		this->start_x = start_x;
	}
	void set_start_y(int start_y)
	{
		if (start_y < MIN_START_Y)start_y = MIN_START_Y;
		if (start_y > MAX_START_Y)start_y = MAX_START_Y;
		this->start_y = start_y;
	}
	void set_line_width(int line_width)
	{
		if (line_width < MIN_LINE_WIDTH) line_width = MIN_LINE_WIDTH;
		if (line_width > MAX_LINE_WIDTH) line_width = MAX_LINE_WIDTH;
		this->line_width = line_width;
	}
	double filter_size(double size)
	{
		if (size < 20)size = 20;
		if (size > 800)size = 500;
		return size;
	}
	Shape(SHAPE_TAKE_PARAMETERS) :color(color)
	{
		set_start_x(start_x);
		set_start_y(start_y);
		set_line_width(line_width);
	}
	virtual ~Shape() {}
	virtual double get_area() const = 0;
	virtual double get_perimeter() const = 0;
	virtual void draw() const = 0;
	virtual void info()const
	{
		cout << "Площадь фигуры: " << get_area() << endl;
		cout << "Переметр фигуры: " << get_perimeter() << endl;
		draw();
	}
};

class Square :public Shape
{
	double side;
public:
	Square(double side, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
	{
		set_side(side);
	}
	~Square() {}
	void set_side(double side)
	{
		this->side = filter_size(side);
	}
	double get_side()const
	{
		return side;
	}
	double get_area()const override
	{
		return side * side;
	}
	double get_perimeter()const override
	{
		return side * 4;
	}
	void draw()const override
	{
		/*for (int i = 0; i < side; i++)
		{
			for (int i = 0; i < side; i++)
			{
				cout << "* ";
			}
			cout << endl;
		}*/
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		Rectangle(hdc, start_x, start_y, start_x + side, start_y + side);

		DeleteObject(hBrush);
		DeleteObject(hPen);

		ReleaseDC(hwnd, hdc);
	}
	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Длина стороны: " << get_side() << endl;
		Shape::info();
	}
};

class Circle: public Shape
{
	double radius;
public:
	Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
	{
		set_radius(radius);
	}
	~Circle() {}
	void set_radius(double radius)
	{
		this->radius = radius;
	}
	double get_radius()const
	{
		return radius;
	}
	double get_area() const 
	{
		return M_PI * radius * radius;
	}
	//длина окружности
	double get_perimeter ()const 
	{
		return 2 * M_PI * radius;
	}
	void info()
	{
		cout << "Радиус круга: " << radius << endl;
		cout << "Площадь круга: " << get_area() << endl;
		cout << "Длина окружности: " << get_perimeter() << endl;
		draw();

	}
	void draw()const override
	{
		HWND hwnd = GetConsoleWindow();
		HDC hdc = GetDC(hwnd);

		HPEN hPen = CreatePen(PS_SOLID, line_width, color);
		HBRUSH hBrush = CreateSolidBrush(color);

		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);

		Ellipse(hdc, start_x, start_y, start_x + radius, start_y + radius);

		DeleteObject(hBrush);
		DeleteObject(hPen);

		ReleaseDC(hwnd, hdc);
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape = Color::Red;
	Square square(50000, -300, -300, 1, Color::White);
	//square.info();
	Circle circle(100, -300, -300, 1, Color::White);
	circle.info();
}
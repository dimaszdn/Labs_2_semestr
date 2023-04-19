#include <iostream>
#include<Shapes.h>
#include<vector>

int main()
{
    Shape* circ = new Circle({3, 5}, 30);
    Shape* rect = new Rectangle({10, 30}, 40, 70);
    Shape* triang = new Triangle({100, 100}, 12, 5);

    std::vector<Shape*> shapes;
    shapes.push_back(circ);
    shapes.push_back(rect);
    shapes.push_back(triang);

    for (Shape* shape : shapes)
        std::cout << shape->Square() << "\n";

    for (int i = 0; i < shapes.size(); ++i)
        delete shapes[i];
    return 0;
}

# d) Area of a given shape (rectangle, triangle and circle) reading shape and 
# appropriate values from standard input.
import math
print("Choose shape tp calculate area:")
print("1. Rectangle")
print("2. Triangle")
print("3. Circle")
choice = input("Enter choice(1/2/3):")
if choice == '1':
    length = float(input("Enter length of Rectangle:"))
    width = float(input("Enter width of Rectangle:"))
    area = length * width
    print("Area of Rectangle={:.2f}".format(area))
elif choice == '2':
    base = float(input("Enter base of Triangle:"))
    height = float(input("Enter height of Triangle:"))
    area = 0.5 * base * height
    print("Area of Triangle={:.2f}".format(area))
elif choice == '3':
    radius = float(input("Enter radius of Circle:"))
    area = math.pi * radius * radius
    print("Area of Circle = {:.2f}".format(area))

import math

class Circle:
    def __init__(self, radius):
        self._radius = radius
    
    def get_circumference(self):
        return 2 * math.pi * self._radius

    def get_area(self):
        return math.pi * self._radius ** 2
    
    def get_radius(self):
        return self._radius
    
    def set_radius(self, value):
        self._radius = value

    def prinf_all(self):
        print(f"원의 둘레 {self.get_circumference()}")
        print(f"원의 넓이 {self.get_area()}")
    

def main():
    a_circle = Circle(10)

    a_circle.prinf_all()

    print(a_circle.get_radius())

    a_circle.set_radius(20)
    a_circle.prinf_all()

if __name__ == "__main__":
    main()

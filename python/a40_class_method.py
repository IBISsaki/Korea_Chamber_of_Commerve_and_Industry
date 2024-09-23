class Student:
    def __init__(self, name, korean, math, english, science):
        self.name = name
        self.korean = korean
        self.math = math
        self.english = english
        self.science = science

    def get_sum(self):
        return self.korean + self. math + self. english + self.science
    
    def get_average(self):
        self.sum = self.get_sum()
        return self.sum / 4

    def to_string(self):
        return f"{self.name}\t{self.get_sum()}\t{self.get_average():.2f}"
    
    # def __repr__(self) -> str:
    #     return f"{self.name}\t{self.get_sum()}\t{self.get_average():.2f}"
    
    def __str__(self) -> str:
        return f"{self.name}\t{self.get_sum()}\t{self.get_average():.2f}"

def main():
    students = [
        Student("윤인성", 87, 98, 88, 95),
        Student("연하진", 92, 98, 96, 98),
        Student("구지연", 76, 96, 94, 90),
        Student("나선주", 98, 92, 96, 92),
        Student("윤아린", 95, 98, 98, 98),
        Student("윤명월", 64, 88, 92, 92),
    ]

    print("이름\t총점\t평균")

    for student in students:
        print(student.to_string())
        print(student)

if __name__ == "__main__":
    main()


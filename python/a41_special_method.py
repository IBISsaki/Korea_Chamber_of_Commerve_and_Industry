class Student:
    def __init__(self, name, korean, math, english, science):
        self.name = name
        self.korean = korean
        self.math = math
        self.english = english
        self.science = science
        self.sum = self.get_sum()
        self.average = self.get_average()

    def get_sum(self):
        return self.korean + self. math + self. english + self.science
    
    def get_average(self):
        return self.sum / 4

    def to_string(self):
        return f"{self.name}\t{self.get_sum()}\t{self.get_average():.2f}"
    
    # def __repr__(self) -> str:
    #     return f"{self.name}\t{self.get_sum()}\t{self.get_average():.2f}"
    
    def __str__(self) -> str:
        return f"{self.name}\t{self.get_sum()}\t{self.get_average():.2f}"

    def __eq__(self, value):
        return self.sum == value.sum
    
    def __ne__(self, value):
        return self.sum != value.sum
    
    def __gt__(self, value):
        return self.sum > value.sum

    def __ge__(self, value):
        return self.sum >= value.sum

    def __lt__(self, value):
        if isinstance(value, Student):
            return self.sum < value.sum
        elif isinstance(value, int):
            return self.sum < value


    def __le__(self, value):
        return self.sum <= value.sum
    
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

    student_a = Student("윤인성", 87, 98, 88, 95)
    student_b = Student("연하진", 84, 98, 96, 90)
    print(f"student_a == student_b : {student_a == student_b}")
    print(f"student_a is student_B : {student_a is student_b}")
    print(f"student_a != student_b : {student_a != student_b}")
    print(f"student_a > student_b : {student_a > student_b}")
    print(f"student_a >= student_b : {student_a >= student_b}")
    print(f"student_a < student_b : {student_a < student_b}")
    print(f"student_a <= student_b : {student_a <= student_b}")

    print(student_a < 350 )

if __name__ == "__main__":
    main()

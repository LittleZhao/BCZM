# -*- coding: utf-8 -*-
#I think actually I use three variables, one instance and two properties.
class Chessman:
    def __init__(self):
        self.__a = 1
        self.__b = 1

    def change_a(self, val):
        self.__a += val
    def change_b(self, val):
        self.__b += val
    def set_b(self, val):
        self.__b = val

    def get_a(self):
        return self.__a
    def get_b(self):
        return self.__b

if __name__ == "__main__":
    i = Chessman()
    while i.get_a() <= 9:
        i.set_b(1)
        while i.get_b() <= 9:
            if (i.get_a()%3 != i.get_b()%3):
                print("A=%d, B=%d\n" %(i.get_a(), i.get_b()))
            i.change_b(1)
        i.change_a(1)



"""
Link: https://realpython.com/primer-on-python-decorators/

High-Order Function is a function wich use or return another function.

Functions in python are First class object, they can be passed as argumenst,
stored in data structures, etc.

Inner function, a function inside a fucntion.

"""


def part1():
    def my_decorator(func):

        def wrapper():
            print("Something is happening before the function is called.")
            func()
            print("Something is happening after the function is called.")
        return wrapper

    def say_whee():
        print("Whee!")

    say_whee = my_decorator(say_whee)

    say_whee()


def part2():
    def my_decorator(func):

        def wrapper():
            print("Something is happening before the function is called.")
            func()
            print("Something is happening after the function is called.")
        return wrapper

    @my_decorator
    def say_whee():
        print("Whee!")

    say_whee()


def part3():
    def do_twice(func):
        def wrapper_do_twice(*args, **kwargs):
            func(*args, **kwargs)
            return func(*args, **kwargs)
        return wrapper_do_twice

    @do_twice
    def return_greeting(name):
        print("Creating greeting")
        return f"Hi {name}"

    name = return_greeting("Sank")
    print(name)


def part4():
    def double_sum10(func):
        def wrapper(number):
            return func(number) * 2 + 10

        return wrapper

    @double_sum10
    def give_me_number(x):
        return x

    print(give_me_number(11))

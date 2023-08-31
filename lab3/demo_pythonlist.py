# Methods: append, clear, copy, count, extend, index, insert, pop, remove, reverse, sort

def append_test(l: list):
    return l.append("<- This is True")

def clear_test(l: list):
    return l.clear()

def copy_test(l: list):
    x = l.copy()
    x.append("<- False")
    print(x)
    return l

def count_test(l: list):
    total = l.count("Pizza")
    return "Counted " + str(total) + " Pizzas!"

def extend_test(l: list, v2: list):
    l.extend(v2)
    return "Extended with " + str(v2)

def index_test(l: list, i: str):
    return l.index(i)

def insert_test(l: list):
    return l.insert("Hello from the other side")

def pop_test(l: list):
    return l.pop(0)

def remove_test(l: list):
    return l.remove(l[0])

def reverse_test(l: list):
    return l.reverse()

def sort_test(l: list):
    return l.sort()


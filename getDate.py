"""
return date, same result as linux command date
"""
import time


def get_date():
    """
    return date
    """
    my_str = ''
    my_str += time.strftime('%a')
    my_str += ', '
    my_str += time.strftime('%b')
    my_str += ' '
    my_str += time.strftime('%d')
    my_str += ', '
    my_str += time.strftime('%Y')
    my_str += ' '
    my_str += time.strftime('%I:%M:%S')
    my_str += ' '
    my_str += time.strftime('%p')
    return my_str

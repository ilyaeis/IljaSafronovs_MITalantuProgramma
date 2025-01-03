try:
    try:
        raise ZeroDivisionError 
    except ZeroDivisionError:
        raise ValueError
except ValueError as e:
    raise RuntimeError from e
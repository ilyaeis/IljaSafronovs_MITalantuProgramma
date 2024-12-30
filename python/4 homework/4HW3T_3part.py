try:
    try:
        1 / 0 
    except ZeroDivisionError:
        raise ValueError
except ValueError as e:
    raise RuntimeError from e
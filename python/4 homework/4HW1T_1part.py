# https://stackoverflow.com/questions/3702675/catch-and-print-full-python-exception-traceback-without-halting-exiting-the-prog
import traceback

try:
    1 / 0 
except ZeroDivisionError:
    try:
        raise ValueError 
    except ValueError:
        traceback.print_exc()
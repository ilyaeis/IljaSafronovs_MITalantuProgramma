# https://stackoverflow.com/questions/3702675/catch-and-print-full-python-exception-traceback-without-halting-exiting-the-prog
import traceback

try:
   raise ZeroDivisionError 
except ZeroDivisionError as e:
    print("ZeroDivisionError")
    try:
        raise ValueError from e
    except ValueError:
        print("The above exception was the direct cause of the following exception:", end=" ")
        print("ValueError")
        print()
        
        traceback.print_exc()
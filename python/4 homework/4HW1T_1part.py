# https://stackoverflow.com/questions/3702675/catch-and-print-full-python-exception-traceback-without-halting-exiting-the-prog
import traceback

try:
    raise ZeroDivisionError
except ZeroDivisionError:
    print("ZeroDivisionError")
    try:
        raise ValueError 
    except ValueError:
        print("During handling of the above exception, another exception occurred:", end=" ")	
        print("ValueError")
        print()
        
        traceback.print_exc()
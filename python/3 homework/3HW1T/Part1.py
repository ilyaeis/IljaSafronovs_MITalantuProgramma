import Part2

# Faili lai atbildet uz 1. uzdevumu: 
#   ja importet Part2 is printets "P2: Part2.py" pirms visa cita, 
#       jo nav izmantota idioma 'if __name__ == "__main__":'

def Part1_function():
    print(f"P1: code from {__name__}")

if __name__ == "__main__":
    print("P1: Part1.py")
    Part2.Part2_function()
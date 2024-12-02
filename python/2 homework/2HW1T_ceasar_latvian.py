latvian_alphabet = [
    'a', 'ā', 'b', 'c', 'č', 'd', 'e', 
    'ē', 'f', 'g', 'ģ', 'h', 'i', 'ī', 
    'j', 'ķ', 'k', 'ļ', 'l', 'm', 'n', 
    'ņ', 'o', 'p', 'q', 'r', 's', 'š', 
    't', 'u', 'ū', 'v', 'w', 'x', 'y', 
    'z', 'ž'
]

def cipher(text, shift):
    alphabet = latvian_alphabet * 2

    output_text = ""
    for letter in text:
        if letter not in alphabet: 
            output_text += letter
            continue

        position = alphabet.index(letter)
        new_position = position + shift 
        new_letter = alphabet[new_position]
        output_text += new_letter

    print(f"'{text}' now is '{output_text}'")

def start_loop():
    while True:
        choice = input("Type 'encode' to encrypt, type 'decode' to decrypt, type 'Exit program' to stop the loop:\n")
        
        if choice == "Exit program": break
        elif choice != "encode" and choice != "decode":
            print("Wrong command, please input valid command next time")
            continue

        text = input("Type your message:\n").lower()

        try: shift = int(input("Type the shift number:\n")) 
        except: 
            print("Wrong input, not a num")
            continue

        formmated_shift = shift % len(latvian_alphabet)
        if choice == "decode":
            formmated_shift *= -1

        cipher(text, formmated_shift)

    print("Bye! Have a nice day!")

if __name__ == "__main__":
    start_loop()
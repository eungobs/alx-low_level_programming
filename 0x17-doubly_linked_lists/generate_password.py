import random

def generate_password(input_arg):
    codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk"
    password = []

    tmp = (len(input_arg) ^ 59) & 63
    password.append(codex[tmp])

    tmp = 0
    for char in input_arg:
        tmp += ord(char)
    password.append(codex[(tmp ^ 79) & 63])

    tmp = 1
    for char in input_arg:
        tmp *= ord(char)
    password.append(codex[(tmp ^ 85) & 63])

    tmp = 0
    for char in input_arg:
        if ord(char) > tmp:
            tmp = ord(char)
    random.seed(tmp ^ 14)
    password.append(codex[random.randint(0, 63)])

    tmp = 0
    for char in input_arg:
        tmp += (ord(char) * ord(char))
    password.append(codex[(tmp ^ 239) & 63])

    for _ in range(ord(input_arg[0])):
        tmp = random.randint(0, 63)
    password.append(codex[(tmp ^ 229) & 63])

    return ''.join(password)

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 2:
        print("Usage: python script_name.py input_argument")
        sys.exit(1)
    input_arg = sys.argv[1]
    password = generate_password(input_arg)
    print(password)


with open("program_fib.txt", "a") as f:
    print("BEGIN", file=f)

    print("PUSH 1", file=f)
    print("PUSH 1", file=f)

    print("POPR A1", file=f)
    print("POPR A2", file=f)

    for i in range(38):
        print(f"PUSHR A{i+1}", file=f)
        print(f"PUSHR A{i+2}", file=f)
        print("ADD", file=f)
        print(f"POPR A{i+3}", file=f)
        

    for i in range(1, 41):
        print(f"PUSHR A{i}", file=f)
        print(f"OUT", file=f)
    
    print("END\n", file=f)

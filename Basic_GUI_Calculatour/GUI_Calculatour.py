import tkinter as tk

def click(event):
    global expression
    expression += event.widget.cget("text")
    input_text.set(expression)

def clear():
    global expression
    expression = ""
    input_text.set("")

def equal():
    global expression
    try:
        result = str(eval(expression))
        input_text.set(result)
        expression = result
    except:
        input_text.set("Error")
        expression = ""

# Main window
root = tk.Tk()
root.title("Simple Calculator")

expression = ""
input_text = tk.StringVar()

# Entry field
entry = tk.Entry(root, textvariable=input_text, font="Arial 20", bd=10, relief="ridge", justify="right")
entry.grid(row=0, column=0, columnspan=4)

# Button layout
buttons = [
    '7', '8', '9', '+',
    '4', '5', '6', '-',
    '1', '2', '3', '*',
    'C', '0', '=', '/'
]

row = 1
col = 0
for button in buttons:
    if button == 'C':
        b = tk.Button(root, text=button, font="Arial 18", width=5, height=2, command=clear)
    elif button == '=':
        b = tk.Button(root, text=button, font="Arial 18", width=5, height=2, command=equal)
    else:
        b = tk.Button(root, text=button, font="Arial 18", width=5, height=2)
        b.bind("<Button-1>", click)
    b.grid(row=row, column=col, padx=5, pady=5)
    col += 1
    if col == 4:
        row += 1
        col = 0

root.mainloop()

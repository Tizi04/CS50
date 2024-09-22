def grade(text):
    letter = countLetter(text)
    word = countWord(text)
    sentence = countSentence(text)

    l = (letter / word) * 100
    s = (sentence / word) * 100

    coleman_index = 0.0588 * l - 0.296 * s - 15.8

    if coleman_index < 1:
        print("Before Grade 1")
    elif coleman_index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {int(round(coleman_index))}")

def countLetter(text):
    ct = 0

    for c in text:
        if c.isalpha():
            ct += 1

    return ct

def countWord(text):
    ct = 1
    for c in text:
        if c == " ":
            ct += 1

    return ct

def countSentence(text):
    ct = 0

    for c in text:
        if c in [".", "?", "!"]:
            ct += 1
    return ct

text = input("Ingrese un texto: ")

grade(text)

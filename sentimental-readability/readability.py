from cs50 import get_string


# Determins reading grade level of input text, using Colemann index formula


def main():
    text = get_string("Text: ")
    grade = grade_level(text)

    if grade > 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")


def grade_level(text):
    characters = 0
    sentences = 0
    words = 1

    for i in range(len(text)):
        if ((text[i] >= "A" and text[i] <= "Z") or (text[i] >= "a" and text[i] <= "z")):
            characters += 1
        elif((text[i] == "?") or (text[i] == ".") or (text[i] == "!")):
            sentences += 1
        elif(text[i] == " "):
            words += 1

    l = characters / words * 100
    s = sentences / words * 100
    grade = round(0.0588 * l - 0.296 * s - 15.8)
    return grade


main()
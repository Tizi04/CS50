from cs50 import get_int

credit_card = get_int("Introduce el número de tarjeta: ")
credit_card_str = str(credit_card)

def algorithm(creditCard):
    sum = 0

    # Duplicar cada segundo dígito empezando desde el final
    for i in range(len(creditCard) - 2, -1, -2):
        double = int(creditCard[i]) * 2
        if double > 9:
            sum += double - 9
        else:
            sum += double

    # Añadir los otros dígitos que no se duplicaron
    for i in range(len(creditCard) - 1, -1, -2):
        sum += int(creditCard[i])

    if sum % 10 == 0:
        return True
    else:
        return False

def card(creditCard):
    amex = ["34", "37"]
    masterCard = ["51", "52", "53", "54", "55"]
    visa = ["4"]

    validator = algorithm(creditCard)

    # Convertir el número a cadena para facilitar la comparación de prefijos
    creditCardStr = str(creditCard)

    print(f"Tarjeta: {creditCardStr}, Validador: {validator}")

    # Verificar MasterCard
    if creditCardStr[:2] in masterCard and validator:
        print("MASTERCARD")

    # Verificar AMEX
    elif creditCardStr[:2] in amex and validator:
         print("AMEX")

    # Verificar VISA con 13 o 16 dígitos
    elif creditCardStr[0] in visa and validator:
        if len(creditCardStr) == 13 or len(creditCardStr) == 16:
            print("VISA")

    else:
        print("INVALID")

card(credit_card_str)

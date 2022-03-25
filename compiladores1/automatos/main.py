# Automatos
#
st = "a"
estado = 1
transicoes = {
    (1,"a") : 2,
    (1,"b") : 4,
    (2,"b") : 3,
    (3,"a") : 2,
    (4,"a") : 3,
    (3,"b") : 4,
}
validos = {3}

for c in st:
    estado = transicoes[(estado,c)]

if estado in validos:
    print("Valido")
else:
    print("Invalido")

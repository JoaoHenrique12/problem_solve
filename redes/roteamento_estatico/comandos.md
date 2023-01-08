# Trabalho

- Desativar wifi e NetworkManager

- Adicionando ip estático.

sudo ifconfig enp4s0 10.0.0.1 netmask 255.0.0.0 broadcast 10.255.255.255

- Adicionando gateway na tabela de rotas.

sudo ip route add 10.0.0.0/24 via 10.0.0.1

- Habilitando passagem de pacotes por este host

sudo echo 1 > /proc/sys/net/ipv4/ip\_forward

- Listando tabela de rotas

route -n

netstat -rn

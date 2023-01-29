# Configuração inicial

sudo apt install isc-dhcp-server -y
sudo apt install apache2

sudo systemctl stop NetworkManager
sudo ifconfig \<nome_interface\> 192.168.1.1/24 broadcast 192.168.1.255


# DHCP

- [arquiovo1](etc_default_isc-dhcp-server), inserir todas as linhas.

- [arquivo2](etc_dhcp_dhcpd.conf)

```
option broadcast-address 192.168.1.255;
option routers 192.168.1.254; # Perguntar
option domain-name "PESCARIA.org"; # Perguntar
option domain-name-servers 192.168.1.1, 192.168.1.2; # Se houver outro dhcp com as mesmas configuracoes e ele etiver em 192.168.1.2

authoritative; # Diz que esta maquina eh o dhcp

# Adicionando range de ips possiveis.
subnet 192.168.1.0 netmask 255.255.255.0 {
  range 192.168.1.10 192.168.1.100;
}
```

systemctl start isc-dhcp-server

# Apache2

adicionar paginas web em /var/www/html/ 

systemctl start apache2

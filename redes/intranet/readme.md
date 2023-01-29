# DNS

Servidor primário : mantêm os registros.

Servidor secundário : redundância, se atualiza com os primários 
através de zone transfer.

Servidor secundário, caching only: mantêm cache, não sincroniza arquivo de dados.

## DNS Records

https://www.techopedia.com/definition/5349/dns-record#:~:text=A%20DNS%20record%20is%20a,to%20the%20specific%20Web%20server.

- Name Server (NS) Record: Describes a name server for the domain that permits DNS lookups within several zones. Every primary as well as secondary name server must be reported via this record.

- Mail Exchange (MX) Record: Permits mail to be sent to the right mail servers located in the domain. Other than IP addresses, MX records include fully-qualified domain names.

- Address (A) Record: Used to map a host name to an IP address. Generally, A records are IP addresses. If a computer consists of multiple IP addresses, adapter cards, or both, it must possess multiple address records.

- Canonical Name (CNAME) Record: Can be used to set an alias for the host name

- Text (TXT) Record: Permits the insertion of arbitrary text into a DNS record. These records add SPF records into a domain.

- Time-to-Live (TTL) Record: Sets the period of data, which is ideal when a recursive DNS server queries the domain name information

- Start of Authority (SOA) Record: Declares the most authoritative host for the zone. Every zone file should include an SOA record, which is generated automatically when the user adds a zone.

- Pointer (PTR) Record: Creates a pointer, which maps an IP address to the host name in order to do reverse lookups.

## DNS Reverso

https://www.cloudflare.com/pt-br/learning/dns/glossary/reverse-dns/

DNS : Me de o IP do NOME.
DNS Reverso: Me de o nome do IP.

Uma consulta de DNS reversa é uma consulta de DNS para o nome de domínio associado a um determinado endereço de IP.
Nesse caso se faz o oposto da pesquisa de DNS de encaminhamento mais comumente usada, em que se consulta o sistema de DNS para que este retorne um endereço de IP.

### Para que são usadas pesquisas em DNS reversos

Pesquisas reversas são comumente usadas por servidores de e-mail. Os servidores de e-mail verificam se uma mensagem de e-mail foi enviada por um servidor válido antes de colocá-la em sua rede.
Muitos servidores de e-mail rejeitarão mensagens de qualquer servidor que não ofereça suporte a pesquisas reversas ou de um servidor que provavelmente não seja legítimo.
Os spammers costumam usar endereços de IP de máquinas sequestradas, o que significa que não haverá registro PTR.
Ou podem usar endereços de IP atribuídos dinamicamente que levam a domínios de servidor com nomes altamente genéricos.


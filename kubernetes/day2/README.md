# Day 2

## Init

O que eh um pod ?
Menor unidade do kubernetes, compartilhar recursos entre esses containers;

```bash
k describe pods nome-do-pod
```

```bash
# Caso a configuracao ja exista, ele atualiza
k apply -f pod.yaml

# Caso a configuracao ja exista, ele retorna erro
k create -f pod.yaml
```

```bash
k logs -f giropops
```

## attach and exec

### Attach

```bash
# conectar a um container que está rodando dentro de um Pod,
# e não para executar comandos dentro do container.
k attach giropops -c strigus
```

### Exec

```bash
k exec giropops -c strigus -- ls

k exec giropops -c strigus -it -- sh
```

## pods limitados

Mi -> mebibytes
Gi -> gibibytes

m -> 1/1000; milicpu

CPU:
500m -> 50 %
750m -> 75 %

## stress

```bash
sudo apt install stress
stress --vm 1 --vm-bytes 100M
```

## EmptyDir

- é um volume temporário;
- mesmo ciclo de vida de um pod;
- compartilhar informações entre containers;


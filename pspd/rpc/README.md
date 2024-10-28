# RPC

```bash
sudo apt install rpcbind
# validate if it is working
rpcinfo -p 
```

## sample

Add file [calcula.x](./calcula/calcula.x)

```bash
rpcgen -a calcula.x
```

Edit only files: 
  - [calcula_client.c](./calcula/calcula_client.c) 
  - [calcula_server.c](./calcula/calcula_server.c)

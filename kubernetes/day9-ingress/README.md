# Ingress

Tell how to expose your application to the world.

It have

- routing rules;
- default backend;
- load balancing;
- SSL/TLS termination;
- anex resources: enable additional resources, like configmaps, secrets, controll access list;

## Key components

- Ingress controller: is the engine behind ingress (nginx, traefik, haproxy ingress);
- Ingress resources: yaml files to apply the configs defined;
- Annotations and customizations: personalize ingress behave, like force redirect http to https;

## Running the sample

```bash
k apply -f app-deployment.yaml
k apply -f app-service.yaml

k apply -f redis-deployment.yaml
k apply -f redis-service.yaml

minikube tunnel

k apply -f ingress-1.yaml
k apply -f ingress-2.yaml

k get ingress
curl <ip-found>/giropops-senhas

k delete ingress --all

# here the app should works
k apply -f ingress-3-work-ok.yaml

# create nginx with ingress.

k run nginx --image=nginx --port=80
k expose pod nginx
k apply -f ingress-4.yaml

```

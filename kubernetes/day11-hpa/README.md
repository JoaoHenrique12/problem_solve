# Horizontal Pod Autoscaler (HPA)

- O HPA precisa de um  Metrics Server (CPU e memória)
```bash
minikube addons enable metrics-server
# kubectl get pods -n kube-system | grep metrics-server
# it may take some time until get up
k top nodes
k top pods
```
- teste prático:
```bash
k apply -f deploy.yaml
k expose deployment nginx-deployment --port=80 --target-port=80
k apply -f hpa.yaml
# assim que ambos estiverem prontos
k run -i --tty load-generator --image=busybox /bin/sh

# once inside the pod
# while true; do wget -q -O- http://nginx-deployment.default.svc.cluster.local; done
```
- Métricas [ContainerResource](hpa-cr.yaml) permitem especificar métricas para um contêiner específico dentro de um Pod.
Isso pode ser útil em cenários onde você tem múltiplos contêineres em um Pod, mas quer escalar com base na
utilização de recursos de um contêiner específico.
- Fórmula de scale de pods baseado nas métricas:
```
desiredReplicas = ceil[ currentReplicas * ( currentMetricValue / desiredMetricValue ) ]
```
Se um Pod não tiver métricas disponíveis ou não estiver pronto, ele pode ser excluído do cálculo de média, evitando decisões
de escalonamento baseadas em dados incompletos.
- Podemos usar métricas do Prometheus para informar nossas decisões de autoscaling. Usar adaptador de métricas personalizadas,
como o k8s-prometheus-adapter

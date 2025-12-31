# Services

[Kubernete Services explained](https://www.youtube.com/watch?v=T4Z7visMM4E)

- [ClusterIP](../day7/clusterip.yaml); only accessible inside the cluster;
- [Headless](../day7/nginx-headless-service.yaml); connect via dns lookup instead direct ip;
- [NodePort](../day7/nodeport.yaml); they're not too safe; a ClusterIP is automatically created; external traffic has access to fixed port on each worker node;
- [LoadBalancer](../day7/loadbalancer.yaml); your cloud provider may handle it;

LoadBalancer is an extension of NodePort; NodePort is an extension of ClusterIP.

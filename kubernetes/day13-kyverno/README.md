# Kyverno

- Kyverno é uma ferramenta de gerenciamento de políticas para Kubernetes.

```bash
helm repo add kyverno https://kyverno.github.io/kyverno/
helm repo update
helm install kyverno kyverno/kyverno --namespace kyverno --create-namespace
```

- Policies:
  - ClusterPolicy (default): Quando você define uma política como ClusterPolicy, ela é aplicada a todos os namespaces no cluster;
  - Policy: Se você deseja aplicar políticas a um namespace específico, você usaria o tipo Policy;
- [Política: Limites de Recursos com excecao de um ns](limit-cpu-policy.yaml): Garantir que todos os containers em um Pod tenham limites de CPU e memória definidos;
- [Politica: Adicionar label aos namespaces](label-namespace.yaml);
- [Politica: Proibir usuario root](forbbid-root.yaml);
- [Política: Gerar ConfigMap para Namespace](generate-cm-ns.yaml);
- [Política: Permitir Apenas Repositórios Confiáveis](trustable-repositories.yaml)
- [Política: Require Probes](require-probes.yaml)

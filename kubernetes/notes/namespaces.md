# Namespaces

A namespace can get stuck in the Terminating state if certain resources have Finalizers that prevent their deletion.
The most common culprit is a PVC that is still in use by a Pod or a PV that cannot be cleanly deleted.

## Create/Delete

```bash
k create/delete namespace <namespace-name>
```

```bash
# delete all pods on namespace default
k delete --all pods -n default
```

```yaml
apiVersion: v1
kind: Namespace
metadata:
  name: <namespace-name>
```

## List

```bash
k get namespaces
```

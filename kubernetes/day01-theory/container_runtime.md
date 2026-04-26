# knowledge dump on container runtimes

WARNING: I just copy that from another github page.

KataContainers
- image coupled with kernel 
- light vm layer
- can run in nested virturalization environments if hardware supports and you can enable it in bios (ex. only bare metal EC2 instances, limits many cloud providers)
- slower startup time
- OCI compliant
- previously known as ClearContainers by Intel

gvisor (runsc)
- kernel implemented in userspace
- layer between container and kernel, intercepts syscalls 
- quicker to cover kernel vulnerabilities as soon they discovered 
- 211 of the 319 x86-64 system calls implemented, using only 64 system calls in the host system 
- limited syscall implementations (relying on community)
- faster startup time than kata
- OCI compliant
- By google, used in production for a few years

runc
- usually the default container runtime
- relies on seccomp, selinux, or apparmor for security policies (syscall filtering, difficult to get it right)
- first runtime to be OCI compliant
- docker built an abstraction layer over `lxc` called `libcontainer` which now it’s called `runc`

rkt (rocket)
- a layer on top runc (more user-friendly)
- non OCI compliant
- by CoreOS

NablaContainers 
- competitor to gvisor
- Uses only 9 syscalls (blocks all others with seccomp policy)
- uses the solo5 project which implements syscall functionality
- can't run linux containers out of the box
- claims to be more secure than gvisor
- by IBM 

containerd (container daemon)
- container runtime that manages container lifecycle (image transfer/pull/push, supervision, networking, etc)
- default to runc runtime
- runs OCI compliant images

cri-o (Container Runtime Interface)
- runtime created specifically for kubernetes (like containerd)
- defaults to runc runtime
- runs OCI compliant images

cri-containerd
- containerd daemon which implemented the cri-o interface (can use containerd with kubernetes)

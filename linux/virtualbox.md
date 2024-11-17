# VirtualBox

[original stack overflow](https://stackoverflow.com/questions/61248315/sign-virtual-box-modules-vboxdrv-vboxnetflt-vboxnetadp-vboxpci-centos-8)

```bash
sudo apt install mokutil

sudo -i
mkdir /root/signed-modules
cd /root/signed-modules
openssl req -new -x509 -newkey rsa:2048 -keyout MOK.priv -outform DER -out MOK.der -nodes -days 36500 -subj "/CN=VirtualBox/"
chmod 600 MOK.priv

```

```bash
# add password
sudo mokutil --import MOK.der
```

Reboot your system and a blue screen appear, select
- Enroll MOK 
- Continue 
- put the previous password and your system will start.


Execute it to sign VirtualBox
```bash
#!/bin/bash

for modfile in $(dirname $(modinfo -n vboxdrv))/*.ko; do
  echo "Signing $modfile"
  /usr/src/kernels/$(uname -r)/scripts/sign-file sha256 \
                                /root/signed-modules/MOK.priv \
                                /root/signed-modules/MOK.der "$modfile"
done
```

Or this, remember to make necessary changes

```bash

#!/bin/sh

readonly hash_algo='sha256'
readonly key='/root/module-signing/MOK.priv'
readonly x509='/root/module-signing/MOK.der'

readonly name="$(basename $0)"
readonly esc='\\e'
readonly reset="${esc}[0m"

green() { local string="${1}"; echo "${esc}[32m${string}${reset}"; }
blue() { local string="${1}"; echo "${esc}[34m${string}${reset}"; }
log() { local string="${1}"; echo "[$(blue $name)] ${string}"; }

# The exact location of `sign-file` might vary depending on your platform.
alias sign-file="/usr/src/kernels/$(uname -r)/scripts/sign-file"

[ -z "${KBUILD_SIGN_PIN}" ] && read -p "Passphrase for ${key}: " KBUILD_SIGN_PIN
export KBUILD_SIGN_PIN

for module in $(dirname $(modinfo -n vboxdrv))/*.ko; do
  log "Signing $(green ${module})..."
  sign-file "${hash_algo}" "${key}" "${x509}" "${module}"
done

```

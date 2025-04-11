package main

import (
  "fmt"
	"crypto/sha256"
)

func main()  {
  hash := sha256.New()
  baite := []byte{}
  // baite = append(baite, byte('2'))
  // baite = append(baite, byte('5'))
  baite = append(baite, byte(25))
  hash.Write(baite)
  hashed := hash.Sum(nil)
  fmt.Printf("%v\n", hashed)
}

// Python Twin
//
// from cryptography.hazmat.primitives import hashes
// digest = hashes.Hash(hashes.SHA256())
// # digest.update(b"25")
// digest.update(bytes([25]))
// lst = list(digest.finalize())
// print(lst)

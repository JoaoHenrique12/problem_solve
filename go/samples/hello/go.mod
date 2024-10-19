// Identifica de forma única o seu projeto dentro do ecossistema Go.
module github.com/example/my-app

// Versão do GO requerida
go 1.19

// Pacotes usados por usa aplicacao
require (
        github.com/gin-gonic/gin v1.9.1
        github.com/stretchr/testify/assert v1.7.0
)

// Permite substituir uma dependência por uma versão local ou por outra fonte. Isso é útil para desenvolvimento ou quando você precisa de uma versão modificada de um pacote.
replace (
        github.com/internal/my-package => ../my-package
)

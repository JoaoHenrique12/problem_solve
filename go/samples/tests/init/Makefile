.PHONY: coverage
coverage:
	go test ./... -coverprofile=coverage.out

.PHONY: coverage-inspect-html
coverage-inspect-html: coverage
	go tool cover -html=coverage.out -o coverage.html

.PHONY: coverage-inspect-text
coverage-inspect-text: coverage
	go tool cover -func=coverage.out

.PHONY: test-cpu
test-cpu:
	go test ./... -bench=.

.PHONY: test-memory
test-memory:
	go test ./... -bench=. -benchmem

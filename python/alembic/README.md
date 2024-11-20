# Tutorial

## Install && init
alembic==1.14

```bash
alembic init folder_name
```

```bash
alembic list_templates
alembic init --template template_name folder_name 
```

## Creating new revision

```bash
# create a normal revision, without auto generate
alembic revision -m "create account table"

# using auto generate
alembic revision --autogenerate -m "create account table"

```

## Moving along migrations

```bash
alembic upgrade head
```

```bash
alembic downgrade head-1
```

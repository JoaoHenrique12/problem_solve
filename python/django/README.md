# Django

```bash
# UV
python3 -m venv env
source env/bin/activate
pip3 install uv
uv init myproject
uv add django ruff psycopg2-binary dj-database-url
```

```python
# setup postgres
# default env var is DATABASE_URL
DATABASES = {
    'default': dj_database_url.config(conn_max_age=60)
}
```

```bash
uv run django-admin startproject myproject .
uv run python3 src/manage.py migrate
uv run python3 src/manage.py runserver
```

// Install Heroku
sudo snap install heroku --classic
heroku login
// Dentro de um repositorio git
heroku create

heroku git:clone -a csgo-connections

git push heroku master
//-------------
heroku ps:scale web=1
heroku open

heroku logs --tail

heroku local // Roda o app localmente.
heroku run python manage.py shell

.env // -> pasta de variaveis de ambiente.

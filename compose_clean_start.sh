docker-compose down -v --rmi all
docker system prune
docker-compose up -d --force-recreate --build

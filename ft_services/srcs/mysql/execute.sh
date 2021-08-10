# Instalas Mysql
/usr/bin/mysql_install_db --datadir=/var/lib/mysql
# Inicializas MYSQL en el background
/usr/bin/mysqld --user=root --init_file=/init_file & sleep 3
/usr/bin/mysqld_safe --datadir='/var/lib/mysql'
# Exportas e inicializas la BD
mysql wordpress -u root < wordpress.sql
# Mantienes el contenedor corriendo
tail -f /dev/null
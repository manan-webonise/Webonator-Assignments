USER=postgres
DBNAME=dvdrental    
DATE=`date +"%d%m%Y"`
SQLFILE=$DBNAME-${DATE}.sql
echo "Creating backup. Please wait..."
pg_dump -d $DBNAME -U $USER > $SQLFILE
gzip $SQLFILE
echo "Backup file created: $SQLFILE.gz"
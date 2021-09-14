DBNAME=employees
DATE=`date +"%d%m%Y"`
SQLFILE=$DBNAME-${DATE}.sql
echo "Creating backup. Please wait..."
mysqldump --opt --user=root $DBNAME > $SQLFILE
gzip $SQLFILE
echo "Backup file created: $SQLFILE.gz"
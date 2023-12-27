#Do not modify or add to this code. It is essential to backup your work!


#Zip the folder, name is "backup", and place it inside the root project folder
cd /home/coder/project
zip  -FSr ./backup.zip * -x \*backup.zip\* 

#confirm operation
echo "Backup succesfully executed!"
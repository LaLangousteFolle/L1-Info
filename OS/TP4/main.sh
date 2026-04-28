function is_integer(i) {
  if [[ $i =~ ^-?[0-9]*$ ]]
  then
      echo 1
  else
    echo 0
  fi
  }

  function get_number_i(nom) {
      if [[ $nom =~ ^([a-z])*.([0-9])*.tar.gz$ ]]
      then
      valeur=`echo $nom | grep -o -E [0-9]*`
      echo $valeur
      
      else
        exit -1
      fi
    }

  function get_max_number_i(logFile) {
      maxi=-1
      for file in `ls`
        do
          if [[ $file =~ log_file.([0-9])*.tar.gz$ ]]
            then
              temp=get_number_i($file)
              if [ $temp -ge $maxi ]
                do
                  $maxi=$temp
                fi 
            fi
        done

      echo $maxi
  
    }

function rotation_log(logFile) {
n=get_max_number_i(logFile)
for()(i=n;i>1;i=i-1))
  do 
    buff=(($i - 1))
    `mv log_file.$buff.tar.gz log_file.$i.tar.gz`
  done
  `tar -czf log_file.0.tar.gz $logFile`
  }

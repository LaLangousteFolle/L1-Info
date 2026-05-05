function get_name() {
  name=$(basename $1 .mp3 | cut -f 4 -d"-")
  echo $name
}

function get_genre() {
  name=$(basename $1 .mp3 | cut -f 2 -d"-")
  echo $name
}
function get_year() {
  name=$(basename $1 .mp3 | cut -f 1 -d"-")
  echo $name
}
function get_album() {
  name=$(basename $1 .mp3 | cut -f 3 -d"-")
  echo $name
}

function scrap_mechanic() {

  for file in $(find $1 -name "*.mp3"); do
    annee=$(get_year $file)
    album=$(get_album $file)
    genre=$(get_genre $file)
    name=$(get_name $file)
    $(mkdir -p $2/$annee/$genre/$album)
    $(cp $file $2/$annee/$genre/$album/$name.mp3)
  done
}
if [ $# -ne 2 ]; then
  exit -1
fi
$(scrap_mechanic $1 $2)

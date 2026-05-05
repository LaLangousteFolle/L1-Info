if [ $# -gt 1 ]; then
  $(echo "trop d'args")
  $(exit)
fi
$(chmod -R 777 *)

for img in $(find $1 | grep .jpg); do

  new=$(basename $img)
  new=$(echo "$new" | iconv -f utf-8 -t ascii//TRANSLIT)

  name=$(basename $img)

  $(convert $1/$new -resize 128x128 $1/converted/$new)

done

echo "<HTML>"
echo "<body>"
for img in $(find $1/converted -name "*.jpg" -exec basename "{}" \;); do
  echo "<img src='$1/converted/$img'>"
done
echo "</body>"
echo "</HTML>"

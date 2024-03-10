cat /etc/passwd | sed '/^#/d' | awk -F ':' 'NR % 2 == 0 {print $1}' | rev | sort -rfn | awk "NR <= $FT_LINE2 && NR >= $FT_LINE1 {print}" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./'

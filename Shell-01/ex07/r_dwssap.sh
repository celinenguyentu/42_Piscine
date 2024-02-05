cat /etc/passwd | grep -v '^#' | awk -F : 'NR == 1 || NR % 2 == 0 {print $1}' | rev | sort -fnr | sed -n "$FT_LINE1,$FT_LINE2 p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' 


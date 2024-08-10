PS=$(ps | grep fdf | sed "s/^[ ]*\([0-9]*\).*/\1/g" | tr '\n' ' ')
kill ${PS}
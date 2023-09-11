/*
b) A função abaixo promete encontrar o valor de um elemento máximo de v[0..n-1]. A função
cumpre a promessa?
int maxi (int n, int v[]) {
 int m = v[0];
 for (int j = 1; j < n; ++j)
 if (v[j-1] < v[j])
	 	 m = v[j];
 return m;
}
*/

//Resposta: A lógica está correta, porém não vai funcionar pois faltou {} na declaração da repetição for

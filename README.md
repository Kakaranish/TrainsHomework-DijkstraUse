Treść polecenia:Jesteś podróżnikiem przemieszczającym się po pewnym regionie Europy. Twoim środkiem transportu jest kolej. W regionie, który chcesz zwiedzić znajduje się n  miast, a m par miast jest połączonych koleją. Każda linia kolejowa pomiędzy dwoma miastami jest zarządzana przez firmę t_i. Wyprawę rozpoczynasz z miasta s i zastanawiasz się jaki byłby najniższy koszt dotarcia z miasta s do innych miast. Z każdą linią kolejową związany jest koszt skorzystania z niej, czyli c_i. Innymi słowy, trzeba zapłacić kwotę c_i za przejazd daną linią. Dodatkowo jeśli ostatnia użyta przez Ciebie linia kolejowa była zarządzana przez firmę i, a teraz planujesz skorzystać z linii zarządzanej przez firmę j, to być może musisz uwzględnić dodatkowy koszt p_{ij}. Koszt ten nie będzie doliczany jeśli linia, którą aktualnie chcesz podróżować nie była wcześniej przez Ciebie wykorzystana (nie podróżowałeś tą linią).

Opis wejścia
W pierwszej linii znajdują się 4 liczby całkowite oddzielone znakiem spacji: n,m,k,s oznaczające kolejno liczbę miast, liczbę połączeń kolejowych, liczbę firm oraz miast, z którego wyruszasz. Następne k linii zawiera k liczb całkowitych oddzielonych znakiem spacji. j-ta liczba całkowita w i-tym rzędzie to p_{ij}, czyli dodatkowy koszt związany z użyciem linii kolejowej obsługiwanej przez firmę j po uprzednim skorzystaniu z linii kolejowej obsługiwanej przez firmę i.Dalej następuje m linii. Każda linia opisuje linię kolejową i zawiera 4 liczby całkowite u_i, v_i, c_i, t_i, a więc kolejno mowa o połączeniu kolejowym pomiędzy miastem u_i a v_i, koszcie połączenia równym c_i oraz zarządcy tejże linii, czyli firmie t_ii.

Opis wyjścia
n liczb całkowitych oddzielonych znakiem spacji. i-ta liczba to najmniejszy koszt podróży z miasta s do miasta i. Jeśli zadana podróż jest niewykonalna, wówczas koszt to -1.

Zakresy używanych wartości
•1 ≤ n, m ≤ 100000
•1 ≤ k ≤ 10
•1 ≤ ci ≤ 10000
•1 ≤ ui, vi ≤ n
•1 ≤ ti ≤ k

Przykład wejścia:
5 4 2 3
12 4
3 1
1 4 5 1
1 2 4 2
3 2 3 1
2 4 10 1


Przykład wyjścia:
11 3 0 19 -1
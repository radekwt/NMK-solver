# Game Board Solver

## Opis Projektu

Ten projekt jest implementacją rozwiązania problemów na planszy w grze podobnej do "kółko i krzyżyk" lub "Connect 4", z możliwością generowania wszystkich możliwych ruchów oraz oceny stanu gry. Kod pozwala na określenie, czy dany gracz wygrał, oraz na obliczenie najlepszego możliwego ruchu w danym stanie gry.

## Funkcje

- **GEN_ALL_POS_MOV:** Generuje wszystkie możliwe ruchy dla danego stanu gry i wyświetla planszę po każdym możliwym ruchu.
- **GEN_ALL_POS_MOV_CUT_IF_GAME_OVER:** Generuje wszystkie możliwe ruchy, ale przerywa, jeśli gra została zakończona (czyli jeden z graczy wygrał).
- **SOLVE_GAME_STATE:** Rozwiązuje aktualny stan gry, określając, który gracz wygra lub czy gra zakończy się remisem.
- **evaluateNextMove:** Ocena następnego ruchu gracza na podstawie aktualnego stanu gry.
- **hasAnybodyWon:** Sprawdza, czy któryś z graczy osiągnął wymagane warunki zwycięstwa.

## Jak uruchomić

1. Skompiluj kod przy użyciu kompilatora C++ (np. `g++`).
2. Uruchom program, podając odpowiednie funkcje i dane wejściowe przez konsolę.

## Przykład Uruchomienia

Aby wygenerować wszystkie możliwe ruchy dla planszy 3x3, gdzie wymagane są 3 w jednej linii do wygrania:


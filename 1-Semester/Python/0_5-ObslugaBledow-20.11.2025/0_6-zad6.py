# ----------------------------
# Zadanie 6 (rozszerzenie zadania 4)

import csv
import datetime

def getCurrTime():
    currentTime = datetime.datetime.now()
    formattedTime = currentTime.strftime( "%H:%M:%S" )
    return formattedTime 

rows = []
with open( "0_6-zad6-errors.log", 'a' ) as errLog: 

    try: 
        with open( "0_4-zad4.csv", "r", encoding="utf-8" ) as f:
            reader = csv.reader( f )

            i = 0
            for row in reader:
                i += 1
                try:
                    wiek = int( row[ 1 ] )
                    rows.append( row )

                except ValueError:
                    err = f"BLAD W WIERSZU { i }: Wiek nie jest liczba"
                    print( err )
                    errLog.write( f"[{ getCurrTime() }]: { err }\n")

                except Exception as e:
                    err = f"BLAD: { e }"
                    print( err )
                    errLog.write( f"[{ getCurrTime() }]: { err }\n")

    except FileNotFoundError:
        err = "BLAD: Nie znaleziono pliku"
        print( err )
        errLog.write( f"[{ getCurrTime() }]: { err }\n")

    finally:
        print( "Wynik:", rows )

# ----------------------------
# W tym zadaniu nauczylem sie, jak tworzy sie logi z aktualnymi bledami.
# Przy okazji nauczylem sie jak korzystac z biblioteki datetime w celu wpisywania aktualnej godziny
# ----------------------------
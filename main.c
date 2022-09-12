/********************************************************************************
* main.c: Demonstration av olika datamedlemmar i C.
* 
*         Datamedlemmar utgörs av objekt som lagrar data på en given adress.
*         Varje datamedlem innehar en datatyp, vilket indikerar vilken typ
*         av data som lagras, exempelvis heltal, flyttal, text med mera.
* 
*         Datamedlemmar kan vara variabla eller konstanta, vilket indikerar
*         ifall innehållet som de lagrar kan ändras.
* 
*         För variabla datamedlemmar, även kallas variabler, kan innehållet
*         ändras under programmet. För konstanta datamedlemmar kan innehållet
*         inte ändras efter initiering (tilldelning av startvärde).
* 
*         Variabler deklareras och initieras enligt nedan:
*         datatyp namn = startvärde;
* 
*         Konstanter är samma, förutom att nyckelordet const (constant) läggs
*         till framför eller bakom datatypen, normalt framför:
*         const datatyp namn = startvärde;
* 
*         Som en tumregel så bör alla datamedlemmar vars innehåll inte skall
*         ändras i ett givet block sättas till konstanter. Detta gäller också 
*         ingående argument / funktionsparametrar till funktioner.
* 
*         För heltal används primärt datatypen int, vilket står för integer
*         (heltal på svenska). Normalt upptar en int 4 byte (32-bitar) minne,
*         vilket möjliggör heltal mellan -2.1 miljarder - +2.1 miljarder.
* 
*         För flyttal används primärt datatyper float och double. Float står
*         för floating point number (flyttal/decimaltal) och möjliggör flyttal
*         med upp till 7 decimalsiffror precision. En float upptar normalt sett
*         4 byte (32-bitar minne). Double står för att denna datatyp möjliggör
*         ungefär dubbelt så hög precision jämfört float (15 decimalsiffror
*         i stället för 7). Därmed möjliggör double mer ackurata matematiska
*         beräkningar och är därmed vanligare. Double upptar normalt dubbelt 
*         så mycket minne jämfört med en float (8 byte/ 64 bitar i stället för
*         4 byte / 32 bitar). Decimalpunkten i flyttal består av en punkt.
*         För flyttal av datatypen float används bokstaven f som avslut på
*         flyttalet för att indikera att flyttalet skall lagras som en double,
*         annars tolkas det som default (automatiskt) som en double.
* 
*         För tecken används datatypen char, vilket står för character (tecken).
*         En datamedlem av datatypen char kan enbart lagra ett enda tecken,
*         som upptar en byte (8 bitar) minne. Runt tecknet skrivs apostrofer
*         '' för att indikera att det just rör sig om ett tecken. Alla tecken
*         utgör för datorn ett heltal, som kan hittas genom att kolla i den
*         så kallade ASCII-tabellen. Exempelvis ett utropstecken ! utgör heltal
*         33 i denna tabell, citattecken "" utgör heltal 34, A utgör heltal 65
*         och B utgör heltal 66.
* 
*         För text (multipla tecken) används också char, men i form av så kallade
*         strängar (string), vilket i praktiken är fält/arrayer/listor med
*         konsekutiva tecken. En följt av tecken kallas också en sträng med
*         tecken, vilket därmed ger upphov till nyckelordet string. Cittattecken
*         "" används för att indikera för kompilatorn att det rör sig om ett
*         textstycke (multipla tecken), vilket vi därmed placerar runt stycket.
*         
*         Ett givet textstycke i en sträng avslutas i C med ett nolltecken \0, 
*         vilket indikerar för kompilatorn var textstycket avslutas. Strängar 
*         i C sägs därför vara nullterminerade. Som exempel, om vi tilldelar
*         "Kalle Anka" till en sträng så lagras detta enligt nedan: 
*         'K', 'a', 'l', 'l', 'e', ' ', 'A', 'n', 'k', 'a', '\0'
* 
*          Vi kan ange storlek på en sträng (antalet tecken den rymmer) genom
*          att skriva detta i hakparentesen, exempelvis en sträng som deklareras
*          enligt nedan rymmer 100 tecken, även fast vi tilldelas namnet "Bo":
* 
*          char s2[100] = "Bo";
* 
*          Innehållet blir då 'B', 'o', '\0' samt 97 tommar adresser som kan
*          fyllas vid behov. Det viktiga är alltid att nolltecknet skall
*          avsluta textstycket. Se till att alltid initiera initiera strängar
*          med ett nolltecken vid start. Om nolltecknet är längst fram i 
*          strängen så är strängen tom (sett till textinnehåll). Detta kan
*          antingen göras direkt genom att skriva följande:
* 
*          char s1[100] = { '\0' };
* 
*          eller följande (index 0 utgör första elementet i fältet, då 
*          kompilatorn räknar positioner/index från 0, inte 1):
*          
*          char s1[100]; // Deklarerar strängen.
*          s1[0] = '\0'; // Initierar strängen till tom vid start.
* 
*          För sant eller falskt används datatypen bool. Denna datatyp är inte
*          standard i C, till skillnad mot många andra programspråk, men kan
*          implementeras via biblioteket stdbool.h sedan C99:
*          #include <stdbool.h>
* 
*          Om ni använder en äldre C-version kan datatypen bool implementeras 
*          via en så kallad enumeration:
*          typedef enum { false, true } bool;
* 
*          I C gäller att false = 0, true = 1.          
* 
*          I C kan datamedlemmar, funktioner, makron och dylikt enbart döpas
*          med bokstäver, siffror och understreck _. Dock kan siffror inte
*          börja namnet. Därmed är följande namn ok:
* 
*          add_number
*          num1
*          _num1
*          num_1
* 
*          Följande namn är inte ok:
* 
*          1num  // Kan inte börja med siffra.
*          num-1 // Kan inte innehålla bindestreck.
*          num!  // Kan inte innehålla utropstecken.
*          num 1 // Kan inte innehålla blanksteg.
* 
*          Både små och stora bokstäver är okej, men generellt används enbart
*          små bokstäver i C för datamedlemmar, funktioner med mera. Stora
*          bokstäver används för så kallade makron och så kallade enumeratorer.
* 
*          Den vanligaste namnkonventionen i C är snake_case, vilket består av
*          att vi använder understreck för att separera ord. Detta understreck
*          sägs likna en orm, varav namnet. Alla bokstäver skall vara små för
*          datamedlemmar, funktioner med mera, medan för makron och enumeratorer
*          används stora bokstäver. På detta sätt undviks namnkrockar. 

*          Exempel på snake_case:
*          int num_of_elements = 0;
*          const int size_of_string = 100;
* 
*          Ibland används också camelCase, som primärt är vanligt i Java,
*          Javascript, Rust med mera. Här används inte understreck för att
*          separera ord, utan man sätter ihop dem med stor första bokstav på
*          på varje nytt ord. Namnet beror på att första bokstaven i varje nytt 
*          ord utgörs av en stor bokstav, vilket liknar en puckel. Den första
*          bokstaven på det första ordet är dock liten.
* 
*          Exempel på camelCase:
*          int numOfElements = 0;
*          const int sizeOfString = 100;
* 
*          En variant på camelCase är PascalCase, som främst används i Pascal 
*          samt i C#. PascalCase är samma som camelCase, med skillnaden att
*          den första bokstaven i namnet utgörs av en stor bokstav, medan det
*          i camelCase består av en liten bokstav.
* 
*          Exempel på PascalCase:
*          int NumOfElements = 0;
*          const int SizeOfString = 100;
********************************************************************************/
#include <stdio.h>
#include <stdbool.h>

/* Makrodefinitioner: */
#define SIZE 100 /* Storlek på strängar. */

int main(void)
{
   /* För heltal används primärt datatypen int: */
   int x = 3;
   int const y = 7;

   /* För flyttal används primärt datatyper float och double: */
   float f1 = 3.4f;
   const double d1 = 8.65;

   /* För tecken används primärt datatypen char: */
   char c1 = '!';
   const char c2 = '3';

   /* För text (multipla tecken) används strängar, vilket p praktiken är charfält: */
   char name[SIZE] = { '\0' }; /* Tom sträng, rymmer 100 tecken. */
   const char s1[] = "Kalle Anka"; /* Sträng där storleken sätts efter antalet tecken. */
   const char* s2 = "Kajsa Anka"; /* Pekare till icke döpt sträng. */

   /* För sant eller falskt används datatypen bool: */
   const bool c_programming_is_fun = true; 
   bool python_is_more_fun_than_c = false;

   /* Ovanstående namnkonvention kallas snake_case, vilket är vanligast i C.
    * Dock är det okej att använda nedanstående namnkonventioner också. */

   /* camelCase (vanligast i Java): */
   const bool cProgrammingIsFun = true;
   bool pythonIsMoreFunThanC = false;

   /* PascalCase (vanligast i C#): */
   const bool CProgrammingIsFun = true;
   bool PythonIsMoreFunThanC = false;

   return 0;
}
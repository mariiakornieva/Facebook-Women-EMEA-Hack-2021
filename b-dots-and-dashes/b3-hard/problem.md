# Problem
__Dots and Dashes__ is a text encoding, similar to (but not the same as!) [other formats](https://www.wikiwand.com/en/Morse_code) used in electric telegraphy.  Like those other formats, it uses sequences of dots “.” and dashes “-” to encode characters, but unlike those other formats, it uses the following translation table:
```
+----------+----------+----------+----------+----------+----------+
| A  .     | B  ...   | C  ..-   | D  .-.   | E  -     | F  .--   |
| G  -..   | H  -.-   | I  ..    | J  --.   | K  ---   | L  ....  |
| M  ...-  | N  ..-.  | O  .-    | P  ..--  | Q  .-..  | R  .-.-  |
| S  .--.  | T  .---  | U  -.    | V  -...  | W  -..-  | X  -.-.  |
| Y  --    | Z  -.--  | .  ..... | ,  ....- | !  ...-. | ?  ...-- |
| '  ..-.. | "  ..-.- | ;  ..--. | :  ..--- | (  .-... | )  .-..- |
| [  .-.-. | ]  .-.-- | {  .--.. | }  .--.- | 0  --..  | 1  --.-  |
| 2  ---.  | 3  ----  | 4  --... | 5  --..- | 6  --.-. | 7  --.-- |
| 8  ---.. | 9  ---.- | +  ----. | -  ----- | *  -.--. | /  -.--- |
| %  -.-.- |          |          |          |          |          |
+----------+----------+----------+----------+----------+----------+
```
As an optional aid, a copy of the translation table can be found in `encoding.txt`, with each translation on its own line.

Your telegraph machine is connected to a service describing open source projects using the dots and dashes protocol.  Your task is to **decode these descriptions**.

You must be having a really bad day, because your telegraph’s tape printer stopped working too!  All your machine can do is emit a tone from a buzzer when the signal is high, and stay silent when it’s not, the timing constraints are the same as before.  Your input is a link to an audio recording of your device containing N separate messages, separated by pauses.

## Constraints
1 ≤ N ≤ 20

## Input
Your input is an audio file containing a recording of N transmissions, each from a different telegraph operator.  There will be a 5 second pause between the end of one transmission (the end of the last high signal) and the start of the next (the start of its first high signal).

## Output
Your output should be a file containing N lines, with the i-th line containing the decoded version of the i-th encoded message in the input, **in all-caps**.

## Explanation of Sample
The sample contains two messages, sent by two different operators, separated by a 5 second pause.

## Sample Input
```
Listen to https://www.dropbox.com/s/6cuq1g9sr2wfey6/hard.ex.flac?dl=1
```

## Sample Output
```
FB HACK!
LINUX KERNEL CONTROL GROUPS.
```

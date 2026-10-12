/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x694620; label: FUN_00694620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_00694620(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  cVar1 = *param_1;
  pcVar3 = (char *)0x0;
  pcVar2 = param_1;
  if (cVar1 != '\0') {
    do {
      if ((cVar1 == '\\') || (cVar1 == '/')) {
        pcVar3 = pcVar2;
      }
      cVar1 = pcVar2[1];
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (pcVar3 != (char *)0x0) {
      param_1 = pcVar3 + 1;
    }
  }
  return param_1;
}


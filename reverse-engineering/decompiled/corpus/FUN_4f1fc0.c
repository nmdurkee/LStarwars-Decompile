/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f1fc0; label: FUN_004f1fc0
 */

char * FUN_004f1fc0(char *param_1,char param_2)

{
  char *pcVar1;
  
  pcVar1 = param_1;
  if (*param_1 != '\0') {
    do {
      pcVar1 = pcVar1 + 1;
    } while (*pcVar1 != '\0');
    if (pcVar1 < param_1) {
      return (char *)0x0;
    }
  }
  do {
    if (*pcVar1 == param_2) {
      return pcVar1;
    }
    pcVar1 = pcVar1 + -1;
  } while (param_1 <= pcVar1);
  return (char *)0x0;
}


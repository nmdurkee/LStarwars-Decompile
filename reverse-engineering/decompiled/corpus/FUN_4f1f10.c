/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f1f10; label: FUN_004f1f10
 */

int FUN_004f1f10(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  if (param_2 != (char *)0x0) {
    cVar1 = *param_2;
    while (cVar1 != '\0') {
      param_2 = param_2 + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
      cVar1 = *param_2;
    }
  }
  *pcVar2 = '\0';
  return (int)pcVar2 - (int)param_1;
}


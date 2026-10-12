/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f20a0; label: FUN_004f20a0
 */

char * FUN_004f20a0(char *param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  
  if (*param_1 != '\0') {
    iVar2 = (int)param_1 - (int)param_2;
    do {
      pcVar1 = param_2;
      if (*param_2 != '\0') {
        while ((pcVar1[iVar2] != '\0' && (pcVar1[iVar2] == *pcVar1))) {
          pcVar1 = pcVar1 + 1;
          if (*pcVar1 == '\0') {
            return param_1;
          }
        }
      }
      if (*pcVar1 == '\0') {
        return param_1;
      }
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
    } while (*param_1 != '\0');
  }
  return (char *)0x0;
}


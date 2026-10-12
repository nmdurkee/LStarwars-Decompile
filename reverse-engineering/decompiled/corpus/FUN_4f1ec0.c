/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f1ec0; label: FUN_004f1ec0
 */

int FUN_004f1ec0(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  iVar2 = 0;
  if (param_2 != (char *)0x0) {
    do {
      if (param_3 == 0) {
        return iVar2;
      }
      *param_1 = *param_2;
      cVar1 = *param_2;
      param_1 = param_1 + 1;
      iVar2 = iVar2 + 1;
      param_3 = param_3 + -1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
  }
  return iVar2;
}


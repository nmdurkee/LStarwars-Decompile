/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f1f40; label: FUN_004f1f40
 */

int FUN_004f1f40(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (param_2 == (char *)0x0) {
    *param_1 = '\0';
    return 0;
  }
  do {
    iVar3 = iVar2;
    param_3 = param_3 + -1;
    if (param_3 < 1) {
      *param_1 = '\0';
      return iVar3;
    }
    *param_1 = *param_2;
    cVar1 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar2 = iVar3 + 1;
  } while (cVar1 != '\0');
  return iVar3;
}


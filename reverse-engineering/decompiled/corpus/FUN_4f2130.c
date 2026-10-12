/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f2130; label: FUN_004f2130
 */

undefined4 FUN_004f2130(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_2 == (char *)0x0) {
    return 1;
  }
  if (param_3 != 0) {
    pcVar3 = param_1;
    if ((param_3 == -1) || (pcVar3 = param_2, param_3 == -2)) {
      param_3 = FUN_004f1ff0(pcVar3);
    }
    do {
      cVar1 = *param_1;
      cVar2 = *param_2;
      if (cVar2 < cVar1) {
        return 1;
      }
      if (cVar1 < cVar2) {
        return 0xffffffff;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (((cVar1 != '\0') && (cVar2 != '\0')) && (param_3 != 0));
  }
  return 0;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x7158bd; label: FUN_007158bd
 */

undefined4 FUN_007158bd(short *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = param_2;
  if (param_2 != 0) {
    do {
      if (*param_1 == 0) break;
      param_1 = param_1 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (iVar1 != 0) {
      if (param_3 == (int *)0x0) {
        return 0;
      }
      *param_3 = param_2 - iVar1;
      return 0;
    }
  }
  return 0x80070057;
}


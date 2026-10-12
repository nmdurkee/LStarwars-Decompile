/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x594250; label: FUN_00594250
 */

int FUN_00594250(int param_1,short *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  DAT_00955884 = (short *)0x0;
  if ((param_2 == (short *)0x0) &&
     (param_2 = DAT_0095587c, param_3 = DAT_00955878, DAT_0095587c == (short *)0x0)) {
    return param_1;
  }
  if (0 < param_3) {
    do {
      if (*param_2 == param_1) {
        DAT_00955884 = param_2;
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      param_2 = param_2 + 0xe;
    } while (iVar1 < param_3);
  }
  return -1;
}


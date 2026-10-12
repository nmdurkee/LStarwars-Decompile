/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x594250; label: FUN_00594250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00594250(int param_1,short *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  DAT_00955884 = (short *)0x0;
  if ((param_2 == (short *)0x0) &&
     (param_2 = DAT_0095587c, param_3 = _DAT_00955878, DAT_0095587c == (short *)0x0)) {
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


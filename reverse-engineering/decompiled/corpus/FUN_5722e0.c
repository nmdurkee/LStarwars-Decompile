/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x5722e0; label: FUN_005722e0
 */

int FUN_005722e0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar3 = 0;
  iVar2 = DAT_0291f664;
  if (0 < DAT_0081020c) {
    do {
      if ((*(byte *)(iVar2 + 0x144) & 1) != 0) {
        iVar1 = FUN_005d0450(iVar2 + 0x148,param_1);
        if (iVar1 != 0) {
          return iVar2;
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x220;
    } while (iVar3 < DAT_0081020c);
  }
  return 0;
}


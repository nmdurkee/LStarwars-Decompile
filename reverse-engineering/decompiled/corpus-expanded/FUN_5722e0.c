/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x5722e0; label: FUN_005722e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


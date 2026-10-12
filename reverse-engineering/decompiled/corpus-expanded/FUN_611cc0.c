/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611cc0; label: FUN_00611cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00611cc0(byte *param_1)

{
  bool bVar1;
  byte *in_ECX;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0x10;
  do {
    if (*(int *)in_ECX != *(int *)param_1) goto LAB_00611ce8;
    uVar2 = uVar2 - 4;
    param_1 = param_1 + 4;
    in_ECX = in_ECX + 4;
  } while (3 < uVar2);
  if (uVar2 == 0) {
LAB_00611d4d:
    bVar1 = false;
  }
  else {
LAB_00611ce8:
    iVar3 = (uint)*in_ECX - (uint)*param_1;
    if (iVar3 == 0) {
      if (uVar2 == 1) goto LAB_00611d4d;
      iVar3 = (uint)in_ECX[1] - (uint)param_1[1];
      if (iVar3 == 0) {
        if (uVar2 == 2) goto LAB_00611d4d;
        iVar3 = (uint)in_ECX[2] - (uint)param_1[2];
        if (iVar3 == 0) {
          if ((uVar2 == 3) || (iVar3 = (uint)in_ECX[3] - (uint)param_1[3], iVar3 == 0))
          goto LAB_00611d4d;
        }
      }
    }
    bVar1 = true;
    if (iVar3 < 1) {
      return 0xffffff00;
    }
  }
  return (uint)!bVar1;
}


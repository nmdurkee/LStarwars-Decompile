/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50f0d0; label: FUN_0050f0d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050f0d0(int param_1)

{
  char cVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x68) != 0) {
    FUN_0050ef10();
    return;
  }
  switch(*(undefined2 *)(param_1 + 10)) {
  case 0:
    if ((*(int *)(param_1 + 0x60) == 0) && (*(int *)(param_1 + 0x5c) == 0)) {
      return;
    }
    if (DAT_008264c7 == '\0') {
      cVar1 = FUN_00509320();
      if (cVar1 != '\0') {
        DAT_00800940 = DAT_00800950;
        if (*(int *)(param_1 + 0x5c) == 0) {
          iVar2 = DAT_02976c30 + 1;
        }
        else {
          iVar2 = DAT_02976c30 + -1;
        }
        if (iVar2 < 0) {
          iVar2 = 4;
        }
        else if (4 < iVar2) {
          iVar2 = 0;
        }
        cVar1 = FUN_005090b0(iVar2);
        while (cVar1 == '\0') {
          iVar2 = iVar2 + 1;
          if (4 < iVar2) {
            iVar2 = 0;
          }
          cVar1 = FUN_005090b0(iVar2);
        }
        DAT_02976c30 = iVar2;
        return;
      }
      DAT_00800940 = DAT_0080095c;
      return;
    }
    goto LAB_0050f106;
  case 1:
    if (((*(int *)(param_1 + 0x60) == 0) && (*(int *)(param_1 + 0x5c) == 0)) &&
       (*(int *)(param_1 + 100) == 0)) {
      return;
    }
    cVar1 = FUN_00509360();
    if (cVar1 != '\0') {
      DAT_00800940 = DAT_00800950;
      DAT_00921d08 = 1 - DAT_00921d08;
      return;
    }
LAB_0050f106:
    DAT_00800940 = DAT_0080095c;
    break;
  case 2:
    if (((*(int *)(param_1 + 0x60) != 0) || (*(int *)(param_1 + 0x5c) != 0)) ||
       (*(int *)(param_1 + 100) != 0)) {
      DAT_00800940 = DAT_00800950;
      DAT_00921d0c = 1 - DAT_00921d0c;
      return;
    }
    break;
  case 3:
    if (((*(int *)(param_1 + 0x60) != 0) || (*(int *)(param_1 + 0x5c) != 0)) ||
       (*(int *)(param_1 + 100) != 0)) {
      DAT_00800940 = DAT_00800950;
      DAT_00921d10 = 1 - DAT_00921d10;
      return;
    }
    break;
  case 4:
    if (*(int *)(param_1 + 100) != 0) {
      FUN_0050ee70();
      return;
    }
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_27b4776215878f137ff0909fe422d2d71d1f91aa156c4f9d6b43512fc3378c0f
 * Entry: 0x5c64b0; label: FUN_005c64b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c64b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int local_10;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  local_8 = FUN_005c6470(param_1);
  iVar4 = 0;
  if (local_8 == 0) {
    return 0;
  }
  if ((DAT_0297dc00 <= *(int *)(local_8 + 0x20)) || (DAT_00806b88 == 0)) {
    return 1;
  }
  uVar5 = 0;
  local_10 = 0;
  local_c = -1;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      iVar3 = *(int *)(param_1 + 8);
      piVar6 = (int *)0x0;
      if (iVar3 != 0) {
        piVar2 = *(int **)(param_1 + 0x10);
        do {
          if (*piVar2 == *(int *)(*(int *)(param_1 + 0xc) + iVar4)) {
            piVar6 = piVar2;
          }
          piVar2 = piVar2 + 7;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
        if (piVar6 != (int *)0x0) {
          if ((DAT_00806b84 == 1) && (*piVar6 != local_c)) {
            cVar1 = FUN_00606d20(piVar6,param_2,param_3);
            if (cVar1 == '\0') {
              return 0;
            }
            local_c = *piVar6;
          }
          if ((DAT_00806b88 == 1) &&
             (cVar1 = FUN_005fbd80(local_8,*(int *)(param_1 + 0xc) + iVar4,&local_10), cVar1 == '\0'
             )) {
            return 0;
          }
        }
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x78;
    } while (uVar5 < *(uint *)(param_1 + 4));
  }
  iVar4 = local_8;
  local_10 = *(int *)(local_8 + 4);
  iVar3 = FUN_005fc430(DAT_00973860,*(undefined4 *)(local_8 + 0xc),local_10);
  if ((iVar3 != 0) &&
     (iVar3 = FUN_005fc690(*(undefined4 *)(iVar4 + 0xc),DAT_00973860,0,local_10 + -1), iVar3 != 0))
  {
    local_4 = 0;
    iVar3 = FUN_005fbcf0(iVar4,&local_4);
    if ((iVar3 != 0) &&
       ((iVar3 = FUN_005fc860(iVar4,local_4,local_10), iVar3 != 0 &&
        (iVar3 = FUN_005fbd20(iVar4), iVar3 != 0)))) {
      *(int *)(iVar4 + 0x20) = DAT_0297dc00;
      return 1;
    }
  }
  return 0;
}


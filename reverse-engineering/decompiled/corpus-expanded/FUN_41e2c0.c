/* Ghidra pseudocode, not original source.
 * ev_12b000564e8cba1f3519ff70f1088df218803466ba65b3333f742de5377565cf
 * Entry: 0x41e2c0; label: FUN_0041e2c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0041e2c0(int param_1,undefined4 param_2)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_58;
  undefined4 local_50 [12];
  char local_1f;
  short local_1c;
  
  if ((*(int *)(param_1 + 0xcbc) == 0) || ((*(byte *)(*(int *)(param_1 + 0xcbc) + 0xc) & 2) == 0)) {
    if (*(short *)(param_1 + 0x1064) == DAT_007f17c0) {
      puVar4 = (undefined4 *)(param_1 + 8);
      iVar3 = FUN_0062f150(puVar4,0x51,1,1);
      if ((((iVar3 != 0) || (iVar3 = FUN_0062f150(puVar4,0x55,1,1), iVar3 != 0)) ||
          (iVar3 = FUN_0062f150(puVar4,0x56,1,1), iVar3 != 0)) ||
         (iVar3 = FUN_0062f150(puVar4,0x94,1,1), iVar3 != 0)) {
        local_58 = (int)DAT_007f17c4;
        puVar5 = local_50;
        for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
        if (((local_1f != '\0') && (local_1c != 0x51)) &&
           ((local_1c != 0x55 && ((local_1c != 0x56 && (local_1c != 0x94)))))) {
          return;
        }
        goto LAB_0041e45b;
      }
    }
    sVar2 = *(short *)(param_1 + 0x1064);
    if (sVar2 == DAT_007f17c8) {
      local_58 = (int)DAT_007f17cc;
      FUN_0062efb0(param_1 + 2000,local_50);
    }
    else {
      if ((sVar2 != DAT_007f17d0) && (sVar2 != DAT_007f17d4)) {
        return;
      }
      iVar3 = FUN_0062f280((undefined4 *)(param_1 + 8),(int)sVar2,(int)DAT_007f17c4);
      if (iVar3 == 0) {
        return;
      }
      local_58 = (int)DAT_007f17c4;
      puVar4 = (undefined4 *)(param_1 + 8);
      puVar5 = local_50;
      for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
  }
  else {
    if (*(short *)(param_1 + 0x1064) != DAT_007f17b8) {
      return;
    }
    local_58 = (int)DAT_007f17bc;
    FUN_0062efb0(param_1 + 2000,local_50);
  }
LAB_0041e45b:
  if (local_58 != -1) {
    iVar3 = FUN_0062f1a0(param_1 + 8);
    piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x50) + 8) + iVar3 * 4);
    if ((*piVar1 == 0) || ((*(byte *)(*piVar1 + 0x48) & 8) == 0)) {
      FUN_0041e1c0(param_1,local_58,param_2,local_50);
    }
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b4ac0; label: FUN_006b4ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b4ac0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *local_10;
  int local_c;
  int local_8;
  int local_4;
  
  piVar1 = param_1;
  iVar2 = param_1[0xd2];
  local_c = 0;
  local_10 = (int *)0xffffffff;
  FUN_006a3570(param_2,*param_1,5);
  if (0 < *param_1) {
    iVar6 = 0;
    piVar5 = param_1;
    do {
      piVar5 = piVar5 + 1;
      FUN_006a3570(param_2,*piVar5,4);
      if ((int)local_10 < *piVar5) {
        local_10 = (int *)*piVar5;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *param_1);
  }
  local_8 = (int)local_10 + 1;
  if (0 < local_8) {
    local_10 = param_1 + 0x50;
    piVar5 = param_1 + 0x30;
    do {
      FUN_006a3570(param_2,piVar5[-0x10] + -1,3);
      FUN_006a3570(param_2,*piVar5,2);
      if (*piVar5 != 0) {
        FUN_006a3570(param_2,piVar5[0x10],8);
      }
      iVar6 = 0;
      piVar4 = local_10;
      if (0 < 1 << ((byte)*piVar5 & 0x1f)) {
        do {
          FUN_006a3570(param_2,*piVar4 + 1,8);
          iVar6 = iVar6 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar6 < 1 << ((byte)*piVar5 & 0x1f));
      }
      local_10 = local_10 + 8;
      piVar5 = piVar5 + 1;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  FUN_006a3570(param_2,param_1[0xd0] + -1,2);
  iVar6 = 0;
  if (iVar2 != 0) {
    for (uVar3 = iVar2 - 1; uVar3 != 0; uVar3 = uVar3 >> 1) {
      iVar6 = iVar6 + 1;
    }
  }
  FUN_006a3570(param_2,iVar6,4);
  local_4 = 0;
  if (iVar2 != 0) {
    local_4 = 0;
    for (uVar3 = iVar2 - 1; uVar3 != 0; uVar3 = uVar3 >> 1) {
      local_4 = local_4 + 1;
    }
  }
  iVar2 = 0;
  local_8 = 0;
  if (0 < *param_1) {
    do {
      param_1 = param_1 + 1;
      local_c = local_c + piVar1[*param_1 + 0x20];
      if (iVar2 < local_c) {
        iVar6 = local_c - iVar2;
        piVar5 = piVar1 + iVar2 + 0xd3;
        iVar2 = iVar2 + iVar6;
        do {
          FUN_006a3570(param_2,*piVar5,local_4);
          piVar5 = piVar5 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      local_8 = local_8 + 1;
    } while (local_8 < *piVar1);
  }
  return;
}


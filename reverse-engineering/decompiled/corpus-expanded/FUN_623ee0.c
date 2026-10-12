/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x623ee0; label: FUN_00623ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00623ee0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_70;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_4c;
  undefined4 local_40 [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = *param_1;
  puVar4 = &DAT_00806680;
  puVar5 = local_40;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  local_c = param_1[1];
  local_8 = param_1[2];
  local_88 = param_2;
  local_84 = 0;
  local_80 = 0;
  local_70 = param_3;
  local_4c = param_3;
  uVar2 = (undefined4)(0x10000 / (longlong)param_4);
  local_10 = uVar1;
  FUN_005b3620(&local_64,&local_88,uVar2);
  if (0 < param_4) {
    do {
      FUN_00623d40(&local_88);
      local_88 = local_64;
      local_84 = local_60;
      local_80 = local_5c;
      FUN_005b3620(&local_64,&local_64,uVar2);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}


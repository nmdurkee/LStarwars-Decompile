/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4ea4a0; label: FUN_004ea4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ea4a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float10 fVar4;
  undefined4 local_90;
  undefined4 local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 local_6c [4];
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  local_8c = 0;
  local_90 = 0;
  local_4c = DAT_0093b0cc;
  local_48 = DAT_0093b0d0;
  local_44 = DAT_0093b0d4;
  if (DAT_0093b328 == 0) {
    puVar2 = &DAT_0088a570;
    puVar3 = local_6c;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    while (0.0 < local_50) {
      FUN_005b44e0(local_40);
      FUN_00550a20(DAT_0087aa94,local_50,&local_4c,&local_8c,&local_90,0);
      FUN_0055e340(&local_84,0);
      local_78 = local_84 - local_5c;
      local_74 = local_80 - local_58;
      local_70 = local_7c - local_54;
      fVar4 = (float10)FUN_005b3b00(&local_78);
      local_88 = (float)fVar4;
      if (local_88 < (float)_DAT_008002c4) {
        FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + 0x974),&local_5c,0x21
                     ,_DAT_00925018,local_90,local_8c,0);
      }
      FUN_005518a0(local_6c,0xc2200000);
    }
    puVar2 = &DAT_0088a650;
    puVar3 = local_6c;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    if (local_50 < _DAT_0088a58c) {
      do {
        FUN_005b44e0(local_40);
        FUN_00550a20(DAT_0087aa94,local_50,&local_4c,&local_8c,&local_90,0);
        FUN_0055e340(&local_84,0);
        local_78 = local_84 - local_5c;
        local_74 = local_80 - local_58;
        local_70 = local_7c - local_54;
        fVar4 = (float10)FUN_005b3b00(&local_78);
        local_88 = (float)fVar4;
        if (local_88 < (float)_DAT_008002c4) {
          FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + 0x974),&local_5c,
                       0x43,_DAT_00925018,local_90,local_8c,0);
        }
        FUN_005518a0(local_6c,0x42200000);
      } while (local_50 < _DAT_0088a58c);
    }
    puVar2 = &DAT_0088a650;
    puVar3 = local_6c;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    while (0.0 < local_50) {
      FUN_005b44e0(local_40);
      FUN_00550a20(DAT_0087aa94,local_50,&local_4c,&local_8c,&local_90,0);
      FUN_0055e340(&local_84,0);
      local_78 = local_84 - local_5c;
      local_74 = local_80 - local_58;
      local_70 = local_7c - local_54;
      fVar4 = (float10)FUN_005b3b00(&local_78);
      local_88 = (float)fVar4;
      if (local_88 < (float)_DAT_008002c4) {
        FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + 0x974),&local_5c,0x21
                     ,_DAT_00925018,local_90,local_8c,0);
      }
      FUN_005518a0(local_6c,0xc2200000);
    }
  }
  return;
}


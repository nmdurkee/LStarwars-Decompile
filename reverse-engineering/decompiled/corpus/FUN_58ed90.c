/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x58ed90; label: FUN_0058ed90
 */

void FUN_0058ed90(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float10 extraout_ST0;
  float10 extraout_ST1;
  undefined1 local_f0 [16];
  undefined1 local_e0 [16];
  undefined1 local_d0 [16];
  undefined4 local_c0 [12];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_80 [12];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_40 [12];
  float local_10;
  float local_c;
  float local_8;
  
  iVar1 = *(int *)(param_2 + 0x24);
  fVar4 = 1.0 - *(float *)(param_1 + 0x44) / *(float *)(param_1 + 0x48);
  puVar5 = (undefined4 *)FUN_005d0330(param_2 + 4);
  if (0.0 < fVar4) {
    puVar7 = puVar5;
    puVar8 = local_c0;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    local_88 = 0;
    local_8c = 0;
    local_90 = 0;
    puVar7 = (undefined4 *)(iVar1 + 0x40);
    puVar8 = local_80;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    local_48 = 0;
    local_4c = 0;
    local_50 = 0;
    FUN_005b7ea0(local_c0,local_e0);
    FUN_005b7ea0(local_80,local_f0);
    FUN_005b87a0(local_d0,local_e0,local_f0,fVar4);
    FUN_005b8040(local_d0,local_40);
    fVar2 = (float)puVar5[0xe];
    fVar3 = *(float *)(iVar1 + 0x78);
    local_10 = fVar4 * (*(float *)(iVar1 + 0x70) - (float)puVar5[0xc]) + (float)puVar5[0xc];
    iVar6 = FUN_006e6b90();
    local_c = (float)((float10)(float)(&DAT_029899a0)[iVar6 >> 1 & 0x7fff] *
                      (float10)0.10000000149011612 + extraout_ST0);
    local_8 = (float)((float10)fVar2 + ((float10)fVar3 - (float10)fVar2) * extraout_ST1);
    puVar7 = local_40;
    puVar8 = puVar5;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  if (*(int *)(param_1 + 0x18) == 0) {
    FUN_005ea570(param_2 + 4,puVar5);
    return;
  }
  puVar7 = (undefined4 *)(iVar1 + 0x80);
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  return;
}


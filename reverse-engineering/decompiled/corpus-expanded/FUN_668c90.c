/* Ghidra pseudocode, not original source.
 * ev_649900f3c82336bf94a875d1c19b8123e0c4482fbb0765088d6a26c91e5b98b7
 * Entry: 0x668c90; label: FUN_00668c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00668c90(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if (DAT_029231a8 == -1) {
    return;
  }
  if ((&DAT_02924b60)[DAT_029231a8 * 0x16] == -1) {
    return;
  }
  iVar2 = *(int *)(DAT_0296209c +
                  *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4) *
                  4);
  if (DAT_0292fd74 == 0) {
    DAT_0292fd74 = FUN_00619250(0x46,0x46,0xb4,300,DAT_02912e80,0,"Texture Select");
    if (DAT_0292fd74 == 0) {
      return;
    }
    uVar4 = FUN_00624f20(0,&local_10,FUN_00668bd0,"Texture Select");
    FUN_00618e10(DAT_0292fd74,uVar4);
    iVar3 = DAT_02900c84;
    iVar5 = FUN_005e4d00(1);
    *(int *)(iVar3 + 0x60) = iVar5;
    *(undefined2 *)(iVar5 + 0x74) = *(undefined2 *)(DAT_0292fd50 + 0x74);
    puVar1 = (uint *)(*(int *)(iVar3 + 0x60) + 0x40);
    *puVar1 = *puVar1 ^ (*(uint *)(DAT_0292fd50 + 0x40) ^ *(uint *)(*(int *)(iVar3 + 0x60) + 0x40))
                        & 0x300;
    puVar1 = (uint *)(*(int *)(iVar3 + 0x60) + 0x40);
    *puVar1 = *puVar1 ^ (*(uint *)(DAT_0292fd50 + 0x40) ^ *(uint *)(*(int *)(iVar3 + 0x60) + 0x40))
                        & 0xc00;
    *(undefined4 *)(*(int *)(iVar3 + 0x60) + 0x54) = *(undefined4 *)(DAT_0292fd50 + 0x54);
    *(undefined4 *)(*(int *)(iVar3 + 0x60) + 0x58) = *(undefined4 *)(DAT_0292fd50 + 0x58);
    *(undefined4 *)(*(int *)(iVar3 + 0x60) + 0x5c) = *(undefined4 *)(DAT_0292fd50 + 0x5c);
    *(undefined4 *)(*(int *)(iVar3 + 0x60) + 0x70) = *(undefined4 *)(DAT_0292fd50 + 0x70);
    puVar1 = (uint *)(*(int *)(iVar3 + 0x60) + 0x40);
    *puVar1 = *puVar1 ^ (*(uint *)(DAT_0292fd50 + 0x40) ^ *(uint *)(*(int *)(iVar3 + 0x60) + 0x40))
                        & 0x30000;
    puVar1 = (uint *)(*(int *)(iVar3 + 0x60) + 0x40);
    *puVar1 = *puVar1 ^ (*(uint *)(DAT_0292fd50 + 0x40) ^ *(uint *)(*(int *)(iVar3 + 0x60) + 0x40))
                        & 0xf;
    puVar1 = (uint *)(*(int *)(iVar3 + 0x60) + 0x40);
    *puVar1 = *puVar1 ^ (*(uint *)(DAT_0292fd50 + 0x40) ^ *(uint *)(*(int *)(iVar3 + 0x60) + 0x40))
                        & 0xc000;
    puVar1 = (uint *)(*(int *)(iVar3 + 0x60) + 0x40);
    *puVar1 = *puVar1 ^ (*(uint *)(DAT_0292fd50 + 0x40) ^ *(uint *)(*(int *)(iVar3 + 0x60) + 0x40))
                        & 0xc0;
    FUN_005e4b00(*(undefined4 *)(iVar3 + 0x60));
    *(float *)(iVar3 + 0x4c) = (*(float *)(iVar2 + 0x298) - 524288.0) * 0.00390625;
    *(float *)(iVar3 + 0x54) = (*(float *)(iVar2 + 0x29c) - 524288.0) * 0.00390625;
    *(float *)(iVar3 + 0x50) = (*(float *)(iVar2 + 0x2a0) - 524288.0) * 0.00390625;
    *(float *)(iVar3 + 0x58) = (*(float *)(iVar2 + 0x2a4) - 524288.0) * 0.00390625;
    if (DAT_0292fd74 == 0) {
      return;
    }
  }
  FUN_006279b0(param_1,DAT_0292fd74);
  *(int *)(DAT_0292fd74 + 0x14) = *(int *)(param_1 + 0x14) + 10;
  *(int *)(DAT_0292fd74 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x58ef70; label: FUN_0058ef70
 */

void FUN_0058ef70(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float10 extraout_ST0;
  float10 extraout_ST1;
  undefined4 local_170 [12];
  float local_140;
  float local_138;
  undefined1 local_130 [16];
  undefined1 local_120 [16];
  undefined1 local_110 [16];
  undefined4 local_100 [12];
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c0 [12];
  float local_90;
  float local_8c;
  float local_88;
  undefined4 local_80 [12];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_40 [64];
  
  iVar5 = *(int *)(param_1 + 0x798);
  if ((((iVar5 != 0) && (*(char *)(iVar5 + 0x6e) != '\0')) && (*(char *)(iVar5 + 0x6d) == '\0')) &&
     (*(char *)(iVar5 + 0x6c) != '\0')) {
    fVar1 = *(float *)(iVar5 + 0x44);
    fVar2 = *(float *)(iVar5 + 0x48);
    iVar3 = *(int *)(*(int *)(iVar5 + 0x14) + (uint)*(byte *)(iVar5 + 0x6f) * 4);
    puVar8 = *(undefined4 **)(iVar3 + 0x24);
    puVar6 = puVar8;
    puVar7 = local_170;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    fVar1 = 1.0 - fVar1 / fVar2;
    if (0.0 < fVar1) {
      puVar6 = local_170;
      puVar7 = local_100;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      local_c8 = 0;
      local_cc = 0;
      local_d0 = 0;
      puVar6 = puVar8 + 0x10;
      puVar7 = local_80;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      local_48 = 0;
      local_4c = 0;
      local_50 = 0;
      FUN_005b7ea0(local_100,local_110);
      FUN_005b7ea0(local_80,local_120);
      FUN_005b87a0(local_130,local_110,local_120,fVar1);
      FUN_005b8040(local_130,local_c0);
      fVar2 = (float)puVar8[0x1e];
      local_90 = fVar1 * ((float)puVar8[0x1c] - local_140) + local_140;
      iVar4 = FUN_006e6b90();
      local_8c = (float)((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] *
                         (float10)0.10000000149011612 + extraout_ST0);
      local_88 = (float)((float10)local_138 + ((float10)fVar2 - (float10)local_138) * extraout_ST1);
      puVar6 = local_c0;
      puVar7 = local_170;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    if (*(int *)(iVar5 + 0x18) != 0) {
      puVar6 = local_170;
      puVar8 = puVar8 + 0x20;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      return;
    }
    iVar3 = iVar3 + 4;
    FUN_005f33b0(iVar3,local_170);
    if ((param_2 != 0) &&
       (iVar5 = FUN_00550490(local_170,*(undefined1 *)(param_1 + 0x107b),
                             *(undefined4 *)(param_1 + 0x1014),
                             *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),local_40),
       iVar5 != 0)) {
      FUN_005d4690(0);
      FUN_005f33b0(iVar3,local_40);
      FUN_005d46b0();
    }
  }
  return;
}


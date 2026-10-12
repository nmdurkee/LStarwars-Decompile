/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4db740; label: FUN_004db740
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004db740(int param_1,int param_2)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  int local_94;
  float local_88;
  undefined4 local_84;
  float local_80;
  undefined4 local_7c;
  float local_78;
  undefined4 local_74;
  float local_70;
  undefined4 local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c [6];
  float local_24 [6];
  undefined1 local_c [12];
  
  if ((*(float *)(param_2 + 0x21c) != 2e+06) &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + 500) != -1)) {
    iVar7 = 0x10;
    local_94 = 0;
    pfVar8 = local_3c + 1;
    do {
      iVar5 = *(int *)(&DAT_007ffd48 + iVar7);
      pfVar9 = pfVar8;
      if ((*(char *)(param_2 + 0x28c) != '\0') &&
         (*(int *)(*(int *)(param_2 + 0x50) + 0x14 + iVar5 * 4) != 0)) {
        local_94 = local_94 + 1;
        iVar6 = iVar5 * 0x40 + param_2;
        pfVar8[-1] = *(float *)(iVar5 * 0x40 + 0x834 + param_2);
        pfVar9 = pfVar8 + 3;
        bVar1 = *(byte *)(param_2 + 0x1fc);
        *pfVar8 = *(float *)(param_2 + 0x21c) + 0.1;
        pfVar8[1] = *(float *)(iVar6 + 0x83c);
        if ((bVar1 & 0x80) != 0) {
          if (param_2 == DAT_0093d7f0) {
            iVar10 = iVar7 + -0x10;
          }
          else {
            iVar10 = iVar7;
            if (param_2 != DAT_0093d7f4) goto LAB_004db9dc;
          }
          local_88 = *(float *)(iVar6 + 0x804);
          local_84 = *(undefined4 *)(iVar6 + 0x808);
          local_80 = *(float *)(iVar6 + 0x80c);
          local_7c = *(undefined4 *)(iVar6 + 0x810);
          local_78 = *(float *)(iVar6 + 0x824);
          local_74 = *(undefined4 *)(iVar6 + 0x828);
          local_70 = *(float *)(iVar6 + 0x82c);
          local_6c = *(undefined4 *)(iVar6 + 0x830);
          local_68 = -*(float *)(iVar6 + 0x814);
          local_64 = -*(float *)(iVar6 + 0x818);
          local_60 = -*(float *)(iVar6 + 0x81c);
          local_5c = -*(float *)(iVar6 + 0x820);
          local_58 = *(undefined4 *)(iVar6 + 0x834);
          local_54 = *(float *)(iVar6 + 0x838);
          local_50 = *(undefined4 *)(iVar6 + 0x83c);
          local_4c = *(undefined4 *)((iVar5 + 0x21) * 0x40 + param_2);
          iVar5 = *(int *)(&DAT_007ffd68 + iVar10);
          if (iVar5 == -1) {
            FUN_00684ee0(&DAT_007ffd68 + iVar10,
                         *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + 0x424),0,0,0);
          }
          else {
            FUN_00655a40(iVar5,&local_88);
          }
          if (*(int *)(&DAT_007ffd70 + iVar10) == -1) {
            FUN_00684ee0(&DAT_007ffd70 + iVar10,
                         *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + 0x438),0,0,0);
          }
          else {
            local_88 = -(float)(&DAT_029899a0)
                               [(int)(*(ushort *)(param_2 + 0x27a) + 0x4000) >> 1 & 0x7fff];
            local_84 = 0;
            local_80 = (float)(&DAT_029899a0)[*(ushort *)(param_2 + 0x27a) >> 1];
            local_78 = -local_80;
            local_74 = 0;
            local_68 = 0.0;
            local_64 = 1.0;
            local_60 = 0.0;
            local_54 = *(float *)(param_2 + 0x21c) + 0.1;
            local_70 = local_88;
            FUN_00655a40(*(int *)(&DAT_007ffd70 + iVar10),&local_88);
          }
        }
      }
LAB_004db9dc:
      iVar7 = iVar7 + 4;
      pfVar8 = pfVar9;
    } while (iVar7 < 0x18);
    if (local_94 == 0) {
      local_3c[0] = *(float *)(param_2 + 0x80);
      local_94 = 1;
      local_3c[1] = *(float *)(param_2 + 0x21c);
      local_3c[2] = *(float *)(param_2 + 0x88);
    }
    FUN_005b3800(local_c,param_2 + 0x8c,param_2 + 0x5c);
    fVar3 = (*(float *)(param_2 + 0x17c) - *(float *)(param_2 + 0x21c)) / _DAT_007ffd64;
    fVar4 = _DAT_0087b888 * _DAT_007ffd60;
    if (0 < local_94) {
      iVar7 = 0;
      do {
        pfVar8 = (float *)((int)local_24 + iVar7);
        FUN_005b37d0(pfVar8,(float *)((int)local_3c + iVar7),local_c);
        for (iVar5 = FUN_0062c350(fVar4 * (1.0 - fVar3),_DAT_00925018); 0 < iVar5;
            iVar5 = iVar5 + -1) {
          iVar6 = FUN_0054fa60();
          fVar2 = (float)iVar6 * 1.5259022e-05;
          local_48 = *pfVar8 + fVar2 * (*(float *)((int)local_3c + iVar7) - *pfVar8);
          local_44 = (*(float *)((int)local_3c + iVar7 + 4) - *(float *)((int)local_24 + iVar7 + 4))
                     * fVar2 + *(float *)((int)local_24 + iVar7 + 4);
          local_40 = (*(float *)((int)local_3c + iVar7 + 8) - *(float *)((int)local_24 + iVar7 + 8))
                     * fVar2 + *(float *)((int)local_24 + iVar7 + 8);
          FUN_00684c90(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + 500),&local_48,1,0,
                       0);
        }
        iVar7 = iVar7 + 0xc;
        local_94 = local_94 + -1;
      } while (local_94 != 0);
    }
  }
  return;
}


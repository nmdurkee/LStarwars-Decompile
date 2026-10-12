/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x45a630; label: FUN_0045a630
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045a630(int param_1,undefined4 param_2,int param_3)

{
  float10 fVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  float10 fVar6;
  float10 extraout_ST0;
  float10 fVar7;
  float10 extraout_ST1;
  float10 fVar8;
  float local_c;
  int local_8;
  
  if (param_3 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x14) < 1) {
    return;
  }
  bVar3 = true;
  fVar1 = (float10)0;
  local_c = *(float *)(param_1 + 0x18);
  if (0.5 <= *(float *)(param_1 + 0x18)) {
    if (local_c < 3.5) {
      local_c = 1.0;
      goto LAB_0045a83b;
    }
    fVar8 = (float10)1;
    if (*(float *)(param_1 + 0x18) < 4.0) {
      fVar2 = *(float *)(param_1 + 0x18) - 3.5;
      fVar6 = (float10)(fVar2 + fVar2);
      local_c = (float)(fVar8 - fVar6);
LAB_0045a738:
      if (fVar6 <= fVar1) goto LAB_0045a82d;
      if (bVar3) goto LAB_0045a6e0;
      fVar7 = (float10)0;
      fVar8 = fVar1;
    }
    else {
      local_c = (float)fVar1;
      if (6.0 <= *(float *)(param_1 + 0x18)) {
        if (6.5 <= *(float *)(param_1 + 0x18)) {
          return;
        }
        bVar3 = false;
        fVar6 = (float10)*(float *)(param_1 + 0x18) - (float10)6.0;
        fVar6 = (float10)(float)(fVar8 - (fVar6 + fVar6));
        goto LAB_0045a738;
      }
LAB_0045a6e0:
      iVar4 = FUN_006e6b90();
      fVar7 = (extraout_ST1 - (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff]) * (float10)-0.5;
      fVar6 = extraout_ST0;
    }
    FUN_0055b830((int)DAT_007f195c,(float)fVar8,(float)(fVar7 + (float10)0.22499999403953552),
                 (float)fVar8,0x3ecccccd,0xa7,(float)fVar6,(float)fVar6,1,0);
    uVar5 = FUN_006e6b90();
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + *(int *)(DAT_007f195c * 0x4c + DAT_0093b274) * 4),0,
                 0xbdcccccd,0x3f800000,_DAT_007f823c,_DAT_007f823c,_DAT_007f823c,0,
                 (byte)DAT_007fa4c8,(byte)DAT_007fa4cc,(byte)DAT_0087a774,0x3fd9999a,1,0,0,uVar5);
  }
  else {
    local_c = local_c + local_c;
  }
LAB_0045a82d:
  if (local_c <= 0.0) {
    return;
  }
LAB_0045a83b:
  local_8 = (int)(longlong)ROUND(local_c * 255.0);
  FUN_00482f40(*(undefined4 *)(DAT_00926c20 + DAT_00880720 * 4),(undefined2)DAT_00876db4,0,
               0x3e666666,_DAT_007f8278,
               ((local_8 << 8 | (uint)(byte)DAT_0087a774) << 8 | (uint)(byte)DAT_007fa4cc) << 8 |
               (uint)(byte)DAT_007fa4c8,0);
  return;
}


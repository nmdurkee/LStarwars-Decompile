/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x4629f0; label: FUN_004629f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004629f0(int param_1,int param_2,int param_3)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  float10 extraout_ST0;
  float10 extraout_ST1;
  
  if (param_3 == 0) {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar1 < 1) goto LAB_00462b01;
  if (*(char *)(param_2 + 0xbb) != '\0') {
    if (0.5 <= *(float *)(param_1 + 0x18)) {
      if (3.5 <= *(float *)(param_1 + 0x18)) {
        fVar2 = 1.0 - (*(float *)(param_1 + 0x18) - 3.5) * 2.0;
        goto LAB_00462a63;
      }
    }
    else {
      fVar2 = *(float *)(param_1 + 0x18) * 2.0;
LAB_00462a63:
      if (fVar2 <= 0.0) goto LAB_00462afd;
    }
    uVar3 = FUN_006e6b90();
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880708 * 4),(float)extraout_ST1,_DAT_007f85f4,
                 (float)extraout_ST0,_DAT_007f85f8,_DAT_007f85f8,_DAT_007f85f8,0,DAT_007fa4c8,
                 DAT_007fa4cc,DAT_0087a774,0x3fd9999a,1,0,0,uVar3);
  }
LAB_00462afd:
  iVar1 = *(int *)(param_1 + 0x14);
LAB_00462b01:
  if (iVar1 != 0) {
    if (*(char *)(param_2 + 0xbb) == '\0') {
      _DAT_0087a1d0 = *(float *)(param_1 + 0x18) / *(float *)(param_1 + 0x1c);
      return;
    }
    fVar2 = *(float *)(param_1 + 0x1c) - 0.5;
    if (fVar2 <= *(float *)(param_1 + 0x18)) {
      _DAT_0087a1d0 = (*(float *)(param_1 + 0x18) - fVar2) * 2.0;
      return;
    }
  }
  _DAT_0087a1d0 = 0.0;
  return;
}


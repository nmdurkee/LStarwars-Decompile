/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58d6a0; label: FUN_0058d6a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058d6a0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar6;
  float *pfVar4;
  undefined4 uVar5;
  float10 fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  if (DAT_00802868 == -1) {
    return;
  }
  if (*(char *)(param_1 + 0x7b5) != DAT_00802868) {
    return;
  }
  if ((0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28)) &&
     ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x1000) == 0)) {
    if ((*(float *)(param_1 + 0xd3c) == 0.0) && (*(char *)(param_1 + 0xe33) != '\x01')) {
      if (*(char *)(param_1 + 0x7b5) != -1) {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      }
      *(undefined1 *)(param_1 + 0xe33) = 1;
      *(undefined4 *)(param_1 + 0xd40) = 0x40a00000;
    }
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    return;
  }
  if (*(char *)(param_1 + 0x39) == '\0') {
LAB_0058d744:
    if (*(short *)(param_1 + 0x3e) != *(short *)(param_1 + 0x7aa)) {
LAB_0058d751:
      *(undefined4 *)(param_1 + 0xd3c) = 0;
      return;
    }
  }
  else {
    if (*(short *)(param_1 + 0x3c) != *(short *)(param_1 + 0x7aa)) goto LAB_0058d751;
    if (*(char *)(param_1 + 0x39) == '\0') goto LAB_0058d744;
  }
  fVar7 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa),0);
  fVar1 = (float)fVar7;
  fVar3 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
  *(float *)(param_1 + 0x77c) = fVar3;
  fVar2 = *(float *)(param_1 + 0xd3c);
  bVar6 = (byte)((ushort)((ushort)NAN(fVar2) << 10) >> 8) |
          (byte)((ushort)((ushort)(fVar2 == 0.0) << 0xe) >> 8);
  if (0.0 < fVar3) {
    if (fVar2 != 0.0) {
      return;
    }
    if (*(char *)(param_1 + 0xe33) == '\x01') {
      return;
    }
    if (*(short *)(param_1 + 0x42) != *(short *)(param_1 + 0x7aa)) {
      return;
    }
    pfVar4 = (float *)(param_1 + 0x1c);
    if (*(char *)(param_1 + 0x39) == '\0') {
      pfVar4 = (float *)(param_1 + 8);
    }
    bVar6 = fVar1 < *pfVar4 | (byte)((ushort)((ushort)(fVar1 == *pfVar4) << 0xe) >> 8);
  }
  else {
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
  if ((POPCOUNT(bVar6) & 1U) == 0) {
    return;
  }
  fVar7 = (float10)FUN_0062f1f0(*(undefined4 *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa),1);
  *(undefined1 *)(param_1 + 0xe33) = 1;
  fVar7 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)*(short *)(param_1 + 0x7aa),
                                fVar1,(float)fVar7,0);
  *(float *)(param_1 + 0xd40) = (float)((float10)1 / fVar7);
  if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 8) == 0) {
    uVar9 = 1;
    uVar5 = 0;
    uVar8 = 0x43;
  }
  else {
    if ((*(char *)(param_1 + 0x280) == -1) && (DAT_00955594 != 0)) goto LAB_0058d897;
    uVar9 = 1;
    uVar5 = FUN_00547820(param_1,1);
    uVar8 = 0x3e;
  }
  FUN_00547930(uVar8,param_1 + 0x80,uVar5,uVar9);
LAB_0058d897:
  uVar5 = FUN_00415050(param_1);
  FUN_004150d0(param_1,1,uVar5);
  return;
}


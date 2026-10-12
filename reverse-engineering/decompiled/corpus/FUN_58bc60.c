/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58bc60; label: FUN_0058bc60
 */

void FUN_0058bc60(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  
  if (((*(char *)(param_1 + 0x39) != '\0') || (iVar6 = (int)*(short *)(param_1 + 0x3e), iVar6 == -1)
      ) || (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar6 * 4) == 0)) {
    return;
  }
  iVar6 = *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 8) + iVar6 * 4);
  if ((*(uint *)(iVar6 + 4) & 0x100) == 0) {
    return;
  }
  fVar1 = *(float *)(param_1 + 0xc);
  fVar2 = *(float *)(param_1 + 8);
  if (fVar1 == fVar2) {
    return;
  }
  bVar5 = false;
  bVar4 = false;
  if ((*(byte *)(param_1 + 0x38) & 2) == 0) {
    if (fVar1 < fVar2) goto LAB_0058bce7;
  }
  else if (fVar2 < fVar1) {
LAB_0058bce7:
    bVar4 = true;
  }
  uVar7 = *(uint *)(iVar6 + 4) & 0x10000;
  if (((uVar7 != 0) && (fVar3 = *(float *)(iVar6 + 0x28), 1.0 <= fVar3)) && (bVar4)) {
    if (fVar3 < fVar2 == (fVar3 == fVar2)) {
      if (fVar2 < fVar1) goto LAB_0058be1c;
    }
    else if (fVar1 <= fVar2) {
LAB_0058be1c:
      if (fVar1 < fVar3) {
        bVar5 = true;
      }
    }
    else {
      bVar5 = true;
    }
  }
  if (((uVar7 != 0) && (fVar3 = *(float *)(iVar6 + 0x2c), 1.0 <= fVar3)) && (bVar4)) {
    if (fVar3 < fVar2 == (fVar3 == fVar2)) {
      if (fVar2 < fVar1) goto LAB_0058be45;
    }
    else if (fVar1 <= fVar2) {
LAB_0058be45:
      if (fVar1 < fVar3) {
        bVar5 = true;
      }
    }
    else {
      bVar5 = true;
    }
  }
  fVar3 = *(float *)(iVar6 + 0x30);
  if ((1.0 <= fVar3) && (bVar4)) {
    if (fVar3 < fVar2 == (fVar3 == fVar2)) {
      if (fVar2 < fVar1) goto LAB_0058be6e;
    }
    else if (fVar1 <= fVar2) {
LAB_0058be6e:
      if (fVar1 < fVar3) {
        bVar5 = true;
      }
    }
    else {
      bVar5 = true;
    }
  }
  fVar3 = *(float *)(iVar6 + 0x34);
  if ((1.0 <= fVar3) && (bVar4)) {
    if (fVar3 < fVar2 == (fVar3 == fVar2)) {
      if (fVar2 >= fVar1) goto LAB_0058bea8;
    }
    else if (fVar2 < fVar1) goto LAB_0058bebe;
    if (fVar1 < fVar3) {
LAB_0058bebe:
      FUN_00548160(param_1);
      return;
    }
  }
LAB_0058bea8:
  if (!bVar5) {
    return;
  }
  FUN_00548160(param_1);
  return;
}


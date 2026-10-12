/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40ebf0; label: FUN_0040ebf0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040ebf0(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  uint *in_EDX;
  float *pfVar7;
  int iVar8;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  if ((in_EDX != (uint *)0x0) && (in_EDX[1] != 0)) {
    if ((DAT_0093d7f0 == 0) || ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0)) {
      bVar5 = false;
    }
    else {
      local_30 = *(float *)(DAT_0093d7f0 + 0xe8);
      bVar5 = true;
      local_2c = *(float *)(DAT_0093d7f0 + 0xec);
      local_28 = *(float *)(DAT_0093d7f0 + 0xf0);
    }
    if ((DAT_0093d7f4 == 0) || ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0)) {
      bVar4 = false;
    }
    else {
      local_20 = *(float *)(DAT_0093d7f4 + 0xe8);
      bVar4 = true;
      local_1c = *(float *)(DAT_0093d7f4 + 0xec);
      local_18 = *(float *)(DAT_0093d7f4 + 0xf0);
    }
    uVar1 = *in_EDX;
    uVar6 = in_EDX[1] * 0x60 + uVar1;
    if (uVar1 < uVar6) {
      pfVar7 = (float *)(uVar1 + 0x34);
      iVar8 = ((uVar6 - uVar1) - 1) / 0x60 + 1;
      do {
        if (pfVar7[7] != 0.0) {
          fVar2 = pfVar7[4] * _DAT_00925018;
          fVar3 = _DAT_00925018 * pfVar7[5];
          pfVar7[-1] = pfVar7[-1] + _DAT_00925018 * pfVar7[3];
          *pfVar7 = fVar2 + *pfVar7;
          pfVar7[1] = pfVar7[1] + fVar3;
          if (((DAT_0093d7f0 != 0) && (bVar5)) &&
             ((pfVar7[1] - local_28) * (pfVar7[1] - local_28) +
              (pfVar7[-1] - local_30) * (pfVar7[-1] - local_30) +
              (*pfVar7 - local_2c) * (*pfVar7 - local_2c) < 1.0)) {
            pfVar7[7] = 0.0;
            FUN_00438230(0,DAT_0093d7f0,1,0,0,1);
          }
          if (((bVar4) && (DAT_0093d7f4 != 0)) &&
             ((pfVar7[1] - local_18) * (pfVar7[1] - local_18) +
              (pfVar7[-1] - local_20) * (pfVar7[-1] - local_20) +
              (*pfVar7 - local_1c) * (*pfVar7 - local_1c) < 1.0)) {
            pfVar7[7] = 0.0;
            FUN_00438230(0,DAT_0093d7f4,1,0,0,1);
          }
          fVar2 = pfVar7[7] - _DAT_00925018;
          pfVar7[7] = fVar2;
          if (fVar2 < 0.0) {
            pfVar7[7] = 0.0;
          }
        }
        pfVar7 = pfVar7 + 0x18;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
  }
  return;
}


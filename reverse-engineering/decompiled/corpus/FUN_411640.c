/* Ghidra analysis pseudocode, not original source.
 * ev_67a1dd79f1152a4a8dc944803f9da200f64b6e45b6a6754633c37085e261482d
 * Entry: 0x411640; label: FUN_00411640
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00411640(undefined4 param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int unaff_ESI;
  int iVar6;
  uint local_28;
  
  local_28 = 0;
  if (*(int *)(unaff_ESI + 0x668) != 0) {
    if (*(uint *)(unaff_ESI + 0x66c) < 2) {
      if (*(uint *)(unaff_ESI + 0x66c) == 0) {
        pfVar1 = (float *)(unaff_ESI + 0x630);
        FUN_005b3800(pfVar1,PTR_DAT_008021b4 + 0xe8,unaff_ESI + 0x30);
        *(undefined4 *)(unaff_ESI + 0x63c) = 0x3f800000;
        FUN_005b3b30(pfVar1,pfVar1);
        *(undefined4 *)(unaff_ESI + 0x63c) = 0x3f800000;
        fVar2 = *(float *)(unaff_ESI + 0x67c);
        *pfVar1 = fVar2 * *pfVar1;
        *(float *)(unaff_ESI + 0x634) = *(float *)(unaff_ESI + 0x634) * fVar2;
        *(float *)(unaff_ESI + 0x638) = fVar2 * *(float *)(unaff_ESI + 0x638);
      }
      pfVar1 = (float *)(unaff_ESI + 0x30);
      fVar2 = *(float *)(unaff_ESI + 0x634) * _DAT_00925018;
      fVar3 = _DAT_00925018 * *(float *)(unaff_ESI + 0x638);
      *pfVar1 = *pfVar1 + _DAT_00925018 * *(float *)(unaff_ESI + 0x630);
      *(float *)(unaff_ESI + 0x34) = *(float *)(unaff_ESI + 0x34) + fVar2;
      *(float *)(unaff_ESI + 0x38) = *(float *)(unaff_ESI + 0x38) + fVar3;
      FUN_005b33c0(unaff_ESI + 0x640,pfVar1,PTR_DAT_008021b4 + 0xb8);
      fVar2 = *(float *)(unaff_ESI + 0x678) - _DAT_00925018;
      *(float *)(unaff_ESI + 0x678) = fVar2;
      if (((fVar2 < 0.0) ||
          ((800.0 < *(float *)(unaff_ESI + 0x648) && (*(int *)(unaff_ESI + 0x66c) == 1)))) ||
         ((*(float *)(unaff_ESI + 0x648) < 0.0 && (*(int *)(unaff_ESI + 0x66c) == 0)))) {
        *(undefined4 *)(unaff_ESI + 0x668) = 0;
      }
    }
    iVar6 = unaff_ESI + 0x40;
    iVar5 = 5;
    do {
      if (*(int *)(iVar6 + 0x110) != 0) {
        uVar4 = FUN_00410a10(iVar6,param_1);
        local_28 = local_28 | uVar4;
      }
      iVar6 = iVar6 + 0x130;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if (local_28 == 0) {
      *(undefined4 *)(unaff_ESI + 0x674) = 1;
    }
    if (*(int *)(unaff_ESI + 0x674) != 0) {
      fVar2 = *(float *)(unaff_ESI + 0x634) * _DAT_00925018;
      fVar3 = _DAT_00925018 * *(float *)(unaff_ESI + 0x638);
      *(float *)(unaff_ESI + 0x650) =
           *(float *)(unaff_ESI + 0x30) + _DAT_00925018 * *(float *)(unaff_ESI + 0x630);
      *(float *)(unaff_ESI + 0x654) = *(float *)(unaff_ESI + 0x34) + fVar2;
      *(float *)(unaff_ESI + 0x658) = *(float *)(unaff_ESI + 0x38) + fVar3;
    }
  }
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_67a1dd79f1152a4a8dc944803f9da200f64b6e45b6a6754633c37085e261482d
 * Entry: 0x411470; label: FUN_00411470
 */

void FUN_00411470(float *param_1)

{
  short sVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float local_50 [4];
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  
  sVar1 = *(short *)((int)param_1 + 0xfe);
  if (sVar1 < 0) {
    if ((((sVar1 == -0x129) || (sVar1 == -299)) || (sVar1 == -0x12a)) || (sVar1 == -0x133)) {
      pfVar4 = param_1;
      pfVar5 = local_50;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar5 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar5 = pfVar5 + 1;
      }
      local_50[0] = local_50[0] * 1.15;
      local_50[1] = local_50[1] * 1.15;
      local_50[2] = local_50[2] * 1.15;
      pfVar4 = local_50;
      local_40 = local_40 * 1.15;
      local_3c = local_3c * 1.15;
      local_38 = local_38 * 1.15;
      local_30 = local_30 * 1.15;
      local_2c = local_2c * 1.15;
      local_28 = local_28 * 1.15;
      iVar3 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + sVar1 * -0x10;
    }
    else {
      iVar3 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + sVar1 * -0x10;
      pfVar4 = param_1;
    }
    FUN_005f33b0(iVar3,pfVar4);
    if (*(short *)((int)param_1 + 0xfe) == -0x133) {
      FUN_00684c90(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x3d4),
                   param_1 + 0xc,1,0,0);
    }
  }
  else {
    FUN_0040e9a0((int)*(short *)(param_1 + 0x3f),param_1[0x3c]);
  }
  if ((((DAT_00855e74 != 0) && (0 < (int)param_1[0x43])) &&
      ((param_1[0x34] == 0.0 && ((DAT_00855e70 != 0 && (fVar2 = param_1[0x35], fVar2 != 0.0)))))) &&
     (*(int *)((int)fVar2 + 0x400) != 0)) {
    FUN_0040fac0(fVar2,3);
  }
  return;
}


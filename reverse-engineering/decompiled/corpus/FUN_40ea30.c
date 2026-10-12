/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40ea30; label: FUN_0040ea30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040ea30(void)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  pfVar3 = (float *)(DAT_00855e6c + 0x108);
  iVar2 = 0xc;
  iVar4 = DAT_00855e6c;
  do {
    if (*(char *)(pfVar3 + 0xc) != '\0') {
      fVar1 = pfVar3[9] - pfVar3[10] * _DAT_00925018;
      pfVar3[9] = fVar1;
      if (fVar1 <= pfVar3[8]) {
        pfVar3[9] = pfVar3[8];
      }
      local_18 = pfVar3[9];
      local_20 = local_18 * pfVar3[-2];
      local_1c = pfVar3[-1] * local_18;
      local_18 = local_18 * *pfVar3;
      FUN_005b30a0(&local_30,&local_20,pfVar3 + -0x22);
      pfVar3[-0x36] = local_30;
      pfVar3[-0x35] = local_2c;
      pfVar3[-0x34] = local_28;
      pfVar3[-0x33] = 1.0;
      FUN_005ea570(pfVar3 + 2,iVar4);
      if (*(short *)((int)pfVar3 + 0x32) != 0) {
        FUN_005b30a0(&local_30,&local_20,pfVar3 + -0x12);
        pfVar3[-0x26] = local_30;
        pfVar3[-0x25] = local_2c;
        pfVar3[-0x24] = local_28;
        pfVar3[-0x23] = 1.0;
        FUN_005ea570(pfVar3 + 5,pfVar3 + -0x32);
      }
    }
    iVar4 = iVar4 + 0x140;
    pfVar3 = pfVar3 + 0x50;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56ee80; label: FUN_0056ee80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056ee80(void)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  
  pfVar2 = (float *)&DAT_00950db4;
  iVar3 = 8;
  do {
    if (*pfVar2 < pfVar2[1]) {
      fVar1 = _DAT_00925018 + *pfVar2;
      *pfVar2 = fVar1;
      if (pfVar2[1] < fVar1 == (pfVar2[1] == fVar1)) {
        if ((pfVar2[-5] != 0.0) && ((*(byte *)((int)pfVar2[-5] + 0x1fc) & 1) == 0)) {
          pfVar2[-5] = 0.0;
        }
        FUN_0056e710(pfVar2 + -7);
      }
      else {
        *pfVar2 = pfVar2[1];
      }
    }
    pfVar2 = pfVar2 + 0xe;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


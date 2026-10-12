/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x528b30; label: FUN_00528b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00528b30(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float fStack_20;
  float local_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined1 auStack_c [12];
  
  iVar4 = 0;
  local_1c = 3.4028235e+38;
  if (DAT_009238a4 == (code *)0x0) {
    return 0;
  }
  iVar2 = FUN_004f1440(DAT_009238e4 + 0x371a4);
  if (iVar2 == 0) {
    return 0;
  }
  do {
    if ((((DAT_00921f50 & 0x400) == 0) || (*(int *)(DAT_009238e4 + 0x371b0) == 0)) ||
       (iVar3 = iVar4, fVar1 = local_1c,
       *(char *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x5a) == *(char *)(iVar2 + 0x5a))) {
      iVar3 = (*DAT_009238a4)((int)*(short *)(iVar2 + 0x58));
      if (iVar3 == 0) {
        fStack_14 = 0.4;
        fStack_18 = 0.0;
        fStack_10 = 0.4;
      }
      else {
        fStack_14 = *(float *)(iVar3 + 0x1cc);
        fStack_18 = *(float *)(iVar3 + 0x1c4);
        fStack_10 = *(float *)(iVar3 + 0x1c8);
      }
      fVar5 = (float10)FUN_005b3cf0(DAT_009238e4 + 0x28,iVar2 + 0x28,auStack_c);
      fVar1 = (float)fVar5;
      if (local_1c <= fVar1) {
LAB_00528cbf:
        iVar3 = iVar4;
        fVar1 = local_1c;
      }
      else {
        iVar3 = iVar2;
        if (param_1 != 0) {
          fStack_20 = fStack_18 + *(float *)(iVar2 + 0x2c);
          if (*(float *)(iVar2 + 0x2c) < fStack_20) {
            fStack_10 = (fStack_20 - *(float *)(iVar2 + 0x2c)) + fStack_10;
            fStack_20 = *(float *)(iVar2 + 0x2c);
          }
          if (((fStack_14 * fStack_14 <= fVar1) ||
              (*(float *)(DAT_009238e4 + 0x2c) < fStack_20 - _DAT_00801ce0)) ||
             (fStack_10 + fStack_20 + _DAT_00801ce0 < *(float *)(DAT_009238e4 + 0x2c)))
          goto LAB_00528cbf;
        }
      }
    }
    local_1c = fVar1;
    iVar2 = FUN_004f1460(DAT_009238e4 + 0x371a4,iVar2);
    iVar4 = iVar3;
    if (iVar2 == 0) {
      return iVar3;
    }
  } while( true );
}


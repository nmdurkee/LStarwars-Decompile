/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x413aa0; label: FUN_00413aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00413aa0(undefined4 param_1)

{
  FUN_004118d0();
  FUN_00412210(param_1,&DAT_007f1648);
  FUN_00413890();
  if ((((DAT_00951224 == 0) && (DAT_0087aa20 == '\0')) && (DAT_0087af84 != 0)) &&
     (((&DAT_0086e0f5)[(uint)*(byte *)(DAT_0087af84 + 0x7c) * 0xc] == '\0' &&
      (3.0 < _DAT_00924fdc != (_DAT_00924fdc == 3.0))))) {
    DAT_0087aa20 = '\x01';
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x642b50; label: FUN_00642b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00642b50(void)

{
  int *piVar1;
  int iVar2;
  float local_c;
  float local_8;
  float local_4;
  
  DAT_02920984 = 0;
  iVar2 = 0;
  piVar1 = &DAT_0291f7f0;
  do {
    if ((((*piVar1 != -1) && (*piVar1 != 99999)) &&
        (FUN_005b3800(&local_c,&DAT_0291f714,piVar1 + -0x12), ABS(local_c) <= _DAT_00810198)) &&
       ((ABS(local_8) < _DAT_00810198 != (ABS(local_8) == _DAT_00810198) &&
        (ABS(local_4) < _DAT_00810198 != (ABS(local_4) == _DAT_00810198))))) {
      (&DAT_0291f754)[DAT_02920984] = iVar2;
      DAT_02920984 = DAT_02920984 + 1;
      if (DAT_02920984 == 8) {
        _DAT_0291f744 = DAT_0291f714;
        _DAT_0291f748 = DAT_0291f718;
        _DAT_0291f74c = DAT_0291f71c;
        DAT_02920a64 = 0;
        return;
      }
    }
    piVar1 = piVar1 + 0x1b;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x292cff0);
  _DAT_0291f744 = DAT_0291f714;
  _DAT_0291f748 = DAT_0291f718;
  _DAT_0291f74c = DAT_0291f71c;
  DAT_02920a64 = 0;
  return;
}


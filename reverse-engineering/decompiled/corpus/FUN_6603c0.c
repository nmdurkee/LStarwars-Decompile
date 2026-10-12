/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x6603c0; label: FUN_006603c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006603c0(void)

{
  int *piVar1;
  int iVar2;
  float local_c;
  float local_8;
  float local_4;
  
  DAT_02962a38 = 0;
  iVar2 = 0;
  piVar1 = &DAT_02924b60;
  do {
    if ((((*piVar1 != -1) && (*piVar1 != 99999)) &&
        (FUN_005b3800(&local_c,&DAT_02920abc,piVar1 + -4), ABS(local_c) <= _DAT_00810adc)) &&
       ((ABS(local_8) < _DAT_00810adc != (ABS(local_8) == _DAT_00810adc) &&
        (ABS(local_4) < _DAT_00810adc != (ABS(local_4) == _DAT_00810adc))))) {
      (&DAT_02924acc)[DAT_02962a38] = iVar2;
      DAT_02962a38 = DAT_02962a38 + 1;
      if (DAT_02962a38 == 8) {
        _DAT_02947b3c = DAT_02920abc;
        _DAT_02947b40 = DAT_02920ac0;
        _DAT_02947b44 = DAT_02920ac4;
        DAT_02962acc = 0;
        return;
      }
    }
    piVar1 = piVar1 + 0x16;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x292fb60);
  _DAT_02947b3c = DAT_02920abc;
  _DAT_02947b40 = DAT_02920ac0;
  _DAT_02947b44 = DAT_02920ac4;
  DAT_02962acc = 0;
  return;
}


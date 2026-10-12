/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x607c60; label: FUN_00607c60
 */

void FUN_00607c60(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  DAT_02854cfc = DAT_0080e268 / 0x18;
  iVar1 = DAT_02854cfc * 0x18;
  piVar2 = &DAT_02854b8c;
  DAT_02854cf8 = iVar1;
  do {
    *piVar2 = *param_1;
    *param_1 = *param_1 + iVar1;
    piVar2 = piVar2 + 1;
  } while (piVar2 != (int *)&DAT_02854bac);
  FUN_005ffba0();
  return;
}


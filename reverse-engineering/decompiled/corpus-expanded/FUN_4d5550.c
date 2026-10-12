/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d5550; label: FUN_004d5550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d5550(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004d54c0(param_1);
  if (iVar1 == 0) {
    FUN_004d5210(param_1 + 0x4c,*(float *)(param_1 + 0xa8) * 1.4,0x3ecccccd);
  }
  return;
}


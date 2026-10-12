/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x745fd0; label: FUN_00745fd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00745fd0(byte param_1)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  *in_ECX = &PTR_FUN_007e9340;
  puVar1 = in_ECX + 0x1e461;
  iVar2 = 399;
  do {
    puVar1 = puVar1 + -0x136;
    thunk_FUN_00742650(puVar1);
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}


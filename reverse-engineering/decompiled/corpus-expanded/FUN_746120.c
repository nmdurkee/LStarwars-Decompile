/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x746120; label: FUN_00746120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00746120(void)

{
  undefined4 *in_ECX;
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  *in_ECX = &PTR_FUN_007e93a4;
  piVar2 = in_ECX + 1;
  iVar1 = 400;
  do {
    if (-1 < *piVar2) {
      FUN_00744010(piVar2);
    }
    piVar2 = piVar2 + 0x136;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00748490();
  FUN_00748490();
  *in_ECX = &PTR_FUN_007e9340;
  puVar3 = in_ECX + 0x1e461;
  iVar1 = 399;
  do {
    puVar3 = puVar3 + -0x136;
    thunk_FUN_00742650(puVar3);
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  return;
}


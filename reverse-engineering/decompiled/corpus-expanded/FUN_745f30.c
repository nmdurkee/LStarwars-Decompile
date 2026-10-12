/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x745f30; label: FUN_00745f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00745f30(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = in_ECX + 1;
  *in_ECX = &PTR_FUN_007e9340;
  iVar1 = 399;
  do {
    FUN_00743c50(puVar2);
    puVar2 = puVar2 + 0x136;
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  in_ECX[0x1e462] = 0;
  in_ECX[0x1e461] = 0xffffffff;
  in_ECX[2] = in_ECX[2] + 1;
  return;
}


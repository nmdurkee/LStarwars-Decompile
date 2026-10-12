/* Ghidra pseudocode, not original source.
 * ev_c3150083e60ed90ca20604204fc0dced3d604859cc3d628705d1178f01c6f096
 * Entry: 0x74ff60; label: FUN_0074ff60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074ff60(void)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = &DAT_02855358;
  iVar2 = 0x1f;
  do {
    _vector_constructor_iterator_(puVar1,0x1c,5,FUN_006069a0);
    puVar1 = puVar1 + 0xa4;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  _atexit(FUN_00750490);
  return;
}


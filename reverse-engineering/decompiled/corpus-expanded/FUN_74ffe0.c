/* Ghidra pseudocode, not original source.
 * ev_fc799924ac0d13a88507923ed5f33b35cabc605b080a1e6fd3b30e9e6a6e393b
 * Entry: 0x74ffe0; label: FUN_0074ffe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074ffe0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0x1ff;
  puVar1 = &DAT_02868890;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x12d;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  _atexit(FUN_00750590);
  return;
}


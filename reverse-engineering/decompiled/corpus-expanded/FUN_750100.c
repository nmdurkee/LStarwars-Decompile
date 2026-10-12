/* Ghidra pseudocode, not original source.
 * ev_fc799924ac0d13a88507923ed5f33b35cabc605b080a1e6fd3b30e9e6a6e393b
 * Entry: 0x750100; label: FUN_00750100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00750100(void)

{
  if (DAT_02972c08 == 0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_02962b90);
    DAT_02972c08 = 1;
  }
  _atexit(FUN_007505f0);
  return;
}


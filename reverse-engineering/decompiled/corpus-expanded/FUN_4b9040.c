/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b9040; label: FUN_004b9040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004b9040(void)

{
  int iVar1;
  
  FUN_005b7d30(_DAT_00925064,0x3f000000);
  iVar1 = FUN_006e6b90();
  return (float10)((float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] * 0.2 + 0.5);
}


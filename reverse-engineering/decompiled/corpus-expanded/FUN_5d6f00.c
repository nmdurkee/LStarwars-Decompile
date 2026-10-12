/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d6f00; label: FUN_005d6f00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005d6f00(void)

{
  int iVar1;
  int iVar2;
  float10 extraout_ST0;
  
  iVar1 = FUN_006e6b90();
  iVar2 = iVar1 + -1;
  if ((float10)iVar1 <= extraout_ST0) {
    iVar2 = iVar1;
  }
  return iVar2;
}


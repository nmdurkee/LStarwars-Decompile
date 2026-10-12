/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6b0470; label: FUN_006b0470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006b0470(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x40) + 0x68) + 0x50);
  if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
    return 1;
  }
  return 0;
}


/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b09c0; label: FUN_005b09c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b09c0(int *param_1)

{
  int iVar1;
  
  if (((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) && (*(int *)(iVar1 + 0x14) != 0))
  {
    return *(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x20);
  }
  return 0;
}


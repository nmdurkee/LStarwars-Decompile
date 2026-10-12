/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b0920; label: FUN_005b0920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_005b0920(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    if (param_2 == 0) {
      if (DAT_00855de0 == 0) {
        return *(undefined1 *)(iVar1 + 0x18);
      }
    }
    else if (param_2 == 1) {
      return *(undefined1 *)(iVar1 + 0x18);
    }
  }
  return 0;
}


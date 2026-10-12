/* Ghidra pseudocode, not original source.
 * ev_2dc15e7d3c3d1805147447414f3f14c0abe3c311ca5fc4e615c2e0419915bb96
 * Entry: 0x5c5420; label: FUN_005c5420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c5420(int *param_1,int *param_2)

{
  if ((*param_1 != -1) &&
     ((*param_2 == -1 ||
      (*(float *)(*param_1 * 0xa0 + 0x94 + *DAT_0080bd34) <
       *(float *)(*param_2 * 0xa0 + 0x94 + *DAT_0080bd34))))) {
    return 0xffffffff;
  }
  return 1;
}


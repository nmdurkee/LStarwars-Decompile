/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x575a10; label: FUN_00575a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_00575a10(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0x101);
  }
  return 0;
}


/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cd7d0; label: FUN_004cd7d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004cd7d0(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return *param_1 + 0x10;
  }
  return 0;
}


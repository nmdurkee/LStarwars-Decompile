/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cd5c0; label: FUN_004cd5c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_004cd5c0(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xec);
  }
  return 0;
}


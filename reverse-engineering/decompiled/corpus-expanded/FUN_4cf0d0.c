/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cf0d0; label: FUN_004cf0d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_004cf0d0(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0x102);
  }
  return 0;
}


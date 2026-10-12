/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4c08e0; label: FUN_004c08e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_004c08e0(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xf1);
  }
  return 0;
}


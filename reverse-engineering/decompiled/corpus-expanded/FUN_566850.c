/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566850; label: FUN_00566850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined2 FUN_00566850(int param_1)

{
  if (param_1 != 0) {
    return *(undefined2 *)(*(int *)(param_1 + 0x128) + 0xda);
  }
  return 0;
}


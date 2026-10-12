/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c82c0; label: FUN_004c82c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_004c82c0(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xea);
  }
  return 0;
}


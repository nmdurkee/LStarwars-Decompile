/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c8360; label: FUN_004c8360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004c8360(int *param_1)

{
  if (((*(byte *)(*param_1 + 0x6a) & 1) != 0) && ((*(byte *)(*param_1 + 0x6a) & 2) != 0)) {
    return 1;
  }
  return 0;
}


/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74ea80; label: FUN_0074ea80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0074ea80(int param_1)

{
  Sleep(1);
  FUN_00631c30(param_1 + 0x14);
  return *(int *)(param_1 + 0x24) == 0;
}


/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a3450; label: FUN_005a3450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a3450(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != 0) {
    if (*(short *)(param_1 + 10) != -1) {
      FUN_00548640((int)*(short *)(param_1 + 10),param_2,param_3,param_4);
    }
    if (*(short *)(param_1 + 0xc) != -1) {
      FUN_00548640((int)*(short *)(param_1 + 0xc),param_2,param_3,param_4);
    }
    if (*(short *)(param_1 + 6) != -1) {
      FUN_00548640((int)*(short *)(param_1 + 6),param_2,param_3,param_4);
    }
    if (*(short *)(param_1 + 8) != -1) {
      FUN_00548640((int)*(short *)(param_1 + 8),param_2,param_3,param_4);
    }
    if (*(short *)(param_1 + 0xe) != -1) {
      FUN_00548640((int)*(short *)(param_1 + 0xe),param_2,param_3,param_4);
    }
  }
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a3450; label: FUN_005a3450
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


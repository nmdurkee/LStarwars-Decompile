/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e4220; label: FUN_004e4220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e4220(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((DAT_00951b50 == 0) && (DAT_008895d8 == 0)) {
    FUN_004e3c90();
  }
  if (param_2 != 0) {
    iVar1 = FUN_004f8b10(param_2,"door_control");
    if (iVar1 == 0) {
      *(undefined1 *)(param_2 + 0xf7) = 1;
    }
  }
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c3640; label: FUN_005c3640
 */

void FUN_005c3640(undefined4 param_1)

{
  int *piVar1;
  
  if (DAT_009737e4 != 0) {
    piVar1 = (int *)(DAT_009737e4 + 0x54);
    *(undefined4 *)(DAT_009737e4 + 0x58 + *(int *)(DAT_009737e4 + 0x54) * 4) = param_1;
    *piVar1 = *piVar1 + 1;
  }
  return;
}


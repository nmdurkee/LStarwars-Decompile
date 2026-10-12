/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c36b0; label: FUN_005c36b0
 */

void FUN_005c36b0(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = DAT_009737e4;
  if (DAT_009737e4 != 0) {
    *(undefined4 *)(DAT_009737e4 + 0x44) = *param_1;
    *(undefined4 *)(iVar1 + 0x48) = param_1[1];
    *(undefined4 *)(iVar1 + 0x4c) = param_1[2];
    *(undefined4 *)(iVar1 + 0x50) = param_1[3];
  }
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_f77d0ac966a5398976b96c42189a5c308704a96dca5e44da054727b198f01d57
 * Entry: 0x42f950; label: FUN_0042f950
 */

void FUN_0042f950(int param_1,undefined4 *param_2)

{
  FUN_0062c610(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0xd,*param_2,
               *(undefined4 *)(param_1 + 0x220),param_2[2]);
  FUN_00681f40("FS_WaterJump",param_1 + 0x80);
  FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f000000,0);
  FUN_0054a8d0(**(undefined4 **)(param_1 + 0xca4),1,0);
  return;
}


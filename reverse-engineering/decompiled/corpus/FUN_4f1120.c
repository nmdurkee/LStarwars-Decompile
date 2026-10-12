/* Ghidra analysis pseudocode, not original source.
 * ev_45a150495450541a978e32c6b8aebbcc21ab633f871105898ebe02d8fbcf8855
 * Entry: 0x4f1120; label: FUN_004f1120
 */

undefined4 FUN_004f1120(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (6 < *(int *)(param_1 + 0x570)) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(param_1 + 0x570) + 1;
  *(int *)(param_1 + 0x570) = iVar1;
  *(undefined4 *)(param_1 + 0x530 + iVar1 * 4) = param_2;
  *(undefined4 *)(param_1 + 0x550 + *(int *)(param_1 + 0x570) * 4) = 0;
  return *(undefined4 *)(param_1 + 0x570);
}


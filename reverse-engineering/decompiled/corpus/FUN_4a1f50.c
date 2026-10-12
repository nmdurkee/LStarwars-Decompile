/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a1f50; label: FUN_004a1f50
 */

void FUN_004a1f50(int param_1)

{
  if ((param_1 != 0) && ((*(uint *)(param_1 + 0x1f8) & 0x40000) == 0)) {
    *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffdffff;
    *(undefined4 *)(param_1 + 0xd14) = 0;
    *(undefined4 *)(param_1 + 0xd18) = 0;
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
  FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
  return;
}


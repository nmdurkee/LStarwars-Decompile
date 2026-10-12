/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x620fe0; label: FUN_00620fe0
 */

void FUN_00620fe0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_0080f7ec;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)(PTR_DAT_0080f7ec + 0x44);
    param_1[1] = *(undefined4 *)(puVar1 + 0x48);
    param_1[2] = *(undefined4 *)(puVar1 + 0x4c);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(puVar1 + 0x50);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(puVar1 + 0x54);
  }
  return;
}


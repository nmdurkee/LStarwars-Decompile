/* Ghidra analysis pseudocode, not original source.
 * ev_f2aefed3f5e3d674fa8981eb98e7164ff9ca04f5228331a10d636af196d460c9
 * Entry: 0x48ca80; label: FUN_0048ca80
 */

void FUN_0048ca80(undefined4 param_1)

{
  undefined2 uVar1;
  
  uVar1 = FUN_004f9e70(param_1);
  *(undefined2 *)(DAT_00951b74 + 0xda) = uVar1;
  if (0x200 < *(ushort *)(DAT_00951b74 + 0xda)) {
    *(undefined2 *)(DAT_00951b74 + 0xda) = 0x200;
  }
  return;
}


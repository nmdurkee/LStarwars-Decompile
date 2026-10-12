/* Ghidra analysis pseudocode, not original source.
 * ev_d93daca17d105ef5f57eb8b76e4a8c3d960b6599f63d34fdaa382c813fb01a39
 * Entry: 0x578fe0; label: FUN_00578fe0
 */

void FUN_00578fe0(undefined4 param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_004f9e70(param_1);
  *(undefined1 *)(DAT_00951b74 + 0x8f) = uVar1;
  *(undefined1 *)(DAT_00951b74 + 0x8e) = *(undefined1 *)(DAT_00951b74 + 0x8f);
  return;
}


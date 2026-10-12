/* Ghidra analysis pseudocode, not original source.
 * ev_4597a773e0370c09a0c234dc3483b3ea71e6a654f79adb326cefb52c3abac04d
 * Entry: 0x588f80; label: FUN_00588f80
 */

void FUN_00588f80(int param_1)

{
  int iVar1;
  
  *(uint *)(DAT_00954404 + 0x90) = *(uint *)(DAT_00954404 + 0x90) | 0x40000000;
  *(uint *)(DAT_00954404 + 0x94) = *(uint *)(DAT_00954404 + 0x94) & 0xfff7ffff;
  *(uint *)(DAT_00954404 + 0x94) = *(uint *)(DAT_00954404 + 0x94) & 0xffefffff;
  iVar1 = FUN_004f7fb0(param_1);
  while (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00954404 + 0x90) = *(uint *)(DAT_00954404 + 0x90) & 0xbfffffff;
    }
    else {
      iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"can_get_up");
      if (iVar1 == 0) {
        *(uint *)(DAT_00954404 + 0x94) = *(uint *)(DAT_00954404 + 0x94) | 0x80000;
      }
      else {
        iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"can_direct_land");
        if (iVar1 == 0) {
          *(uint *)(DAT_00954404 + 0x94) = *(uint *)(DAT_00954404 + 0x94) | 0x100000;
        }
      }
    }
    iVar1 = FUN_004f7fb0(param_1);
  }
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4ec330; label: FUN_004ec330
 */

void FUN_004ec330(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_00803bb0 = 0xffffffff;
  iVar1 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,"float_skiff_2",1);
  if ((iVar1 != 0) && (*(int *)(param_1 + 0x295c) != 0)) {
    uVar2 = FUN_005cffb0(&DAT_0087aad8);
    DAT_00803bb0 = FUN_0067c760(uVar2);
  }
  return;
}


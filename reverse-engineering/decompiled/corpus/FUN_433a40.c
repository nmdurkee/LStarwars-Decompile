/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x433a40; label: FUN_00433a40
 */

void FUN_00433a40(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  *(uint *)(param_1 + 0x2c) = (-(uint)(param_3 != 0) & 0xfffffc10) + 0x500;
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0;
  **(undefined4 **)(param_1 + 8) = 0;
  *(undefined1 **)(param_1 + 0x48) = &LAB_00432b30;
  *(code **)(param_1 + 0x4c) = FUN_00432b10;
  *(code **)(param_1 + 0x54) = FUN_00571c80;
  iVar1 = FUN_0064d270(param_1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x100) = 0x41200000;
  }
  return;
}


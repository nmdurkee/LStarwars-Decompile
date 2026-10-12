/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56c040; label: FUN_0056c040
 */

void FUN_0056c040(int param_1)

{
  undefined2 uVar1;
  
  *(undefined1 *)(param_1 + 0x107a) = 0;
  uVar1 = FUN_00550070(*(undefined2 *)(param_1 + 0x278),-0x4000 - *(short *)(param_1 + 0x7a4),
                       0x40c00000);
  *(undefined2 *)(param_1 + 0x278) = uVar1;
  uVar1 = FUN_00550070(*(undefined2 *)(param_1 + 0x27c),0,0x41200000);
  *(undefined2 *)(param_1 + 0x27c) = uVar1;
  return;
}


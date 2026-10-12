/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x659910; label: FUN_00659910
 */

void FUN_00659910(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 local_c [12];
  
  FUN_005da860(local_c,DAT_02962114,DAT_02923194);
  uVar2 = FUN_005cf9c0(local_c);
  FUN_005b3800(&DAT_0292ff14 + DAT_02962010 * 0xb5 + param_1 * 3,param_2,uVar2);
  uVar1 = (undefined2)DAT_02962110;
  param_1 = DAT_02962010 * 0x16a + param_1;
  (&DAT_0292ff74)[param_1] = (undefined2)DAT_0296210c;
  (&DAT_0292ff84)[param_1] = uVar1;
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56ca60; label: FUN_0056ca60
 */

undefined4 * FUN_0056ca60(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)0x0;
  if ((param_3 != 0) &&
     (puVar1 = (undefined4 *)FUN_00552670(param_1,param_2,8), puVar1 != (undefined4 *)0x0)) {
    *(short *)((int)puVar1 + 6) = (short)param_3;
    uVar2 = FUN_00552670(param_1,param_2,(param_3 & 0xffff) << 5);
    *puVar1 = uVar2;
  }
  return puVar1;
}


/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56ca60; label: FUN_0056ca60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


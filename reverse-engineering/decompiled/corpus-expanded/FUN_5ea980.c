/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ea980; label: FUN_005ea980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005ea980(int *param_1,int *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (*param_1 == 0) {
    return 0;
  }
  puVar3 = (undefined4 *)FUN_004f4f40(*param_1);
  uVar1 = *puVar3;
  uVar4 = puVar3[1];
  iVar2 = *param_2;
  *param_2 = iVar2 + 0x28;
  *(undefined4 *)(iVar2 + 0x1c) = uVar4;
  *(undefined4 *)(iVar2 + 0x20) = 0x200000;
  uVar4 = FUN_005e5210(iVar2);
  FUN_005ea800(uVar1,uVar4,4,0,param_2,param_3);
  return uVar1;
}


/* Ghidra pseudocode, not original source.
 * ev_64ab134b4afd9c8d0a163dd8f67d256d98012891aab565beeb69ac94b847fa54
 * Entry: 0x5db690; label: FUN_005db690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005db690(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00607d70(0xe,7,param_2);
  FUN_005c1f70();
  uVar1 = param_1[6];
  iVar2 = *DAT_02854d10;
  *(undefined4 *)(iVar2 + 0x10) = param_1[5];
  *(undefined4 *)(iVar2 + 0x14) = uVar1;
  FUN_006009e0(*param_1,param_1[1],0);
  FUN_005c1f70();
  uVar1 = param_1[0xd];
  iVar2 = *DAT_02854d10;
  *(undefined4 *)(iVar2 + 0x10) = param_1[0xc];
  *(undefined4 *)(iVar2 + 0x14) = uVar1;
  FUN_006009e0(param_1[7],param_1[8],0);
  FUN_006009a0();
  return 1;
}


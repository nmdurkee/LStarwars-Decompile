/* Ghidra pseudocode, not original source.
 * ev_64ab134b4afd9c8d0a163dd8f67d256d98012891aab565beeb69ac94b847fa54
 * Entry: 0x5db360; label: FUN_005db360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005db360(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  FUN_00607ec0(0xc,5,0,0);
  FUN_005c1f70();
  uVar1 = param_1[1];
  puVar3 = (undefined4 *)*DAT_02854d10;
  uVar2 = param_1[2];
  *puVar3 = *param_1;
  puVar3[1] = uVar1;
  *(undefined4 *)(*DAT_02854d10 + 8) = uVar2;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_005c1f70();
  uVar1 = param_2[1];
  puVar3 = (undefined4 *)*DAT_02854d10;
  uVar2 = param_2[2];
  *puVar3 = *param_2;
  puVar3[1] = uVar1;
  *(undefined4 *)(*DAT_02854d10 + 8) = uVar2;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_005c1f70();
  uVar1 = param_3[1];
  puVar3 = (undefined4 *)*DAT_02854d10;
  uVar2 = param_3[2];
  *puVar3 = *param_3;
  puVar3[1] = uVar1;
  *(undefined4 *)(*DAT_02854d10 + 8) = uVar2;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_006009c0();
  return;
}


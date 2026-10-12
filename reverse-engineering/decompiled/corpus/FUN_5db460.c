/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5db460; label: FUN_005db460
 */

void FUN_005db460(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  FUN_00607ec0(0xf,5,0,0);
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
  FUN_005c1f70();
  uVar1 = param_1[1];
  uVar2 = param_1[2];
  puVar3 = (undefined4 *)*DAT_02854d10;
  *puVar3 = *param_1;
  puVar3[1] = uVar1;
  *(undefined4 *)(*DAT_02854d10 + 8) = uVar2;
  *DAT_02854d10 = *DAT_02854d10 + 0x18;
  DAT_02854d14 = DAT_02854d14 + 1;
  FUN_006009c0();
  return;
}


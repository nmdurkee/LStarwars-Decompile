/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a1320; label: FUN_006a1320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a1320(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = *(int *)(param_1[0x10] + 0x68);
  iVar2 = *(int *)(*(int *)(param_1[0x10] + 4) + 0x1c);
  puVar1 = param_1 + 1;
  FUN_006a15c0(param_1);
  FUN_006a3940(puVar1,*param_2,param_2[1]);
  iVar3 = FUN_006a3bb0(puVar1,1);
  if (iVar3 != 0) {
    return 0xffffff79;
  }
  iVar4 = FUN_006a3bb0(puVar1,*(undefined4 *)(iVar4 + 0x2c));
  if (iVar4 == -1) {
    return 0xffffff78;
  }
  param_1[10] = iVar4;
  iVar4 = **(int **)(iVar2 + 0x20 + iVar4 * 4);
  param_1[7] = iVar4;
  if (iVar4 == 0) {
    param_1[6] = 0;
    param_1[8] = 0;
  }
  else {
    uVar5 = FUN_006a3bb0(puVar1,1);
    param_1[6] = uVar5;
    iVar4 = FUN_006a3bb0(puVar1,1);
    param_1[8] = iVar4;
    if (iVar4 == -1) {
      return 0xffffff78;
    }
  }
  param_1[0xc] = param_2[4];
  param_1[0xd] = param_2[5];
  param_1[0xe] = param_2[6];
  param_1[0xf] = param_2[7];
  uVar5 = param_2[3];
  param_1[9] = 0;
  *param_1 = 0;
  param_1[0xb] = uVar5;
  return 0;
}


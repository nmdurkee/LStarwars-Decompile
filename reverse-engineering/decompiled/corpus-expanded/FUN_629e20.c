/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x629e20; label: FUN_00629e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00629e20(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = DAT_02912eac;
  if ((DAT_02912f30 == 0) || (param_1 == DAT_02912eac)) {
    if (param_1[2] == 0) {
      param_1[2] = *param_1;
    }
    iVar1 = param_1[2];
    if (((iVar1 == 0) || ((*(byte *)(iVar1 + 0x11) & 2) != 0)) ||
       (*(code **)(iVar1 + 0x3c) == (code *)0x0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(iVar1 + 0x3c))(param_1,iVar1,param_2,param_3);
      puVar3 = DAT_02912eac;
    }
    if (((DAT_02912f30 == 0) || (param_1 == puVar3)) && (param_1 == DAT_02912eb0)) {
      if (param_1[2] == 0) {
        param_1[2] = *param_1;
      }
      if ((DAT_02912f30 == 0) || (param_1 == puVar3)) {
        FUN_00629080(param_1,param_2,param_3,uVar2);
      }
    }
  }
  FUN_00627320(param_1,param_3);
  return;
}


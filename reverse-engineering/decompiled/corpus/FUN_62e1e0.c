/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62e1e0; label: FUN_0062e1e0
 */

void FUN_0062e1e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *local_48;
  undefined4 local_40 [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((param_4 != (undefined4 *)0x0) || (param_5 != (undefined4 *)0x0)) {
    iVar2 = 0;
    local_48 = (int *)(param_1 + 0x14);
    puVar3 = param_4;
    puVar5 = param_5;
    do {
      if (*local_48 != 0) {
        FUN_005daae0(*(undefined4 *)(param_1 + 4),iVar2,param_2,param_3,local_40);
        if (param_4 != (undefined4 *)0x0) {
          *puVar3 = local_10;
          puVar3[1] = local_c;
          puVar3[2] = local_8;
        }
        if (param_5 != (undefined4 *)0x0) {
          puVar4 = local_40;
          puVar6 = puVar5;
          for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
            *puVar6 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar6 = puVar6 + 1;
          }
        }
      }
      local_48 = local_48 + 1;
      iVar2 = iVar2 + 1;
      puVar5 = puVar5 + 0x10;
      puVar3 = puVar3 + 3;
    } while (iVar2 < 0x10);
  }
  return;
}


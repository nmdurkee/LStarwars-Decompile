/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c3700; label: FUN_005c3700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c3700(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = DAT_009737e0;
  if (DAT_009737e0 != 0) {
    puVar3 = param_1;
    puVar4 = (undefined4 *)(DAT_009737e0 + 0x90);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar3 = param_2;
    puVar4 = (undefined4 *)(iVar1 + 0xd0);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(iVar1 + 0x110) = param_3;
    *(undefined4 *)(iVar1 + 0x114) = param_4;
    *(undefined4 *)(iVar1 + 0x118) = param_5;
    iVar1 = DAT_009737e8;
    puVar3 = (undefined4 *)(DAT_009737e8 + 0x14);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar3 = (undefined4 *)(iVar1 + 0x54);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_2;
      param_2 = param_2 + 1;
      puVar3 = puVar3 + 1;
    }
    *(undefined4 *)(iVar1 + 0x94) = param_3;
    *(undefined4 *)(iVar1 + 0x98) = param_4;
    *(undefined4 *)(iVar1 + 0x9c) = param_5;
  }
  return;
}


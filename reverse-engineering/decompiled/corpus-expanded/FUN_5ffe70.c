/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x5ffe70; label: thunk_FUN_005ffdc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_005ffdc0(undefined1 *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *param_1 = 0x52;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  iVar3 = 0x20;
  puVar1 = (undefined4 *)(param_1 + 0x20);
  do {
    puVar2 = puVar1 + 8;
    iVar3 = iVar3 + -1;
    *puVar1 = 0x3f800000;
    puVar1[1] = 0x40000000;
    puVar1[2] = 0x40400000;
    puVar1[4] = 0x40800000;
    puVar1[5] = 0x40a00000;
    puVar1[6] = 0x40c00000;
    puVar1[3] = 0xbf800000;
    puVar1[7] = 0x43000000;
    puVar1 = puVar2;
  } while (iVar3 != 0);
  *puVar2 = 0;
  *param_2 = (int)puVar2 + (4 - (int)param_1);
  return;
}


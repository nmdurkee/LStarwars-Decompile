/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x5ffdc0; label: FUN_005ffdc0
 */

void FUN_005ffdc0(undefined1 *param_1,int *param_2)

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


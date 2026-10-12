/* Ghidra analysis pseudocode, not original source.
 * ev_f0b2ce2d5885583ae7420409f057ba3a395d2cbd12cd318b48692f86b50c0045
 * Entry: 0x655a40; label: FUN_00655a40
 */

void FUN_00655a40(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 != -1) {
    param_1 = param_1 * 0x330;
    puVar2 = param_2;
    puVar3 = (undefined4 *)(param_1 + 0x40 + DAT_029620a4);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    *(undefined4 *)(param_1 + 400 + DAT_029620a4) = param_2[0xc];
    *(undefined4 *)(param_1 + 0x194 + DAT_029620a4) = param_2[0xd];
    *(undefined4 *)(param_1 + 0x198 + DAT_029620a4) = param_2[0xe];
    *(undefined4 *)(param_1 + 0x70 + DAT_029620a4) = 0;
    *(undefined4 *)(param_1 + 0x74 + DAT_029620a4) = 0;
    *(undefined4 *)(param_1 + 0x78 + DAT_029620a4) = 0;
    *(undefined4 *)(param_1 + 0x300 + DAT_029620a4) = 0;
  }
  return;
}


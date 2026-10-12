/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46cc30; label: FUN_0046cc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046cc30(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  
  if (DAT_00951b50 != 0) {
    *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) & 0xfffffffe;
    return;
  }
  iVar1 = *(int *)(PTR_DAT_00802c54 + 0x50b8);
  iVar3 = *(int *)(iVar1 + 0xc) * 0x2c + *(int *)(iVar1 + 4);
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
  if (0x3f < *(int *)(*(int *)(PTR_DAT_00802c54 + 0x50b8) + 0xc)) {
    *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x50b8) + 0xc) = 0;
  }
  if ((*(byte *)(iVar3 + 0x17) & 1) != 0) {
    FUN_0046b1d0(PTR_DAT_00802c54,iVar3 + 8,*(undefined1 *)(iVar3 + 0x25),
                 *(undefined1 *)(iVar3 + 0x16),0,1);
  }
  FUN_0046c610((int)*(short *)(param_1 + 0x13e),iVar3);
  *(byte *)(iVar3 + 0x17) = *(byte *)(iVar3 + 0x17) & 0xf7 | 0x17;
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(param_1 + 0x38);
  *(undefined2 *)(iVar3 + 0x26) = 0;
  if (*(int *)(PTR_DAT_00802c54 + 0x13c) == 0) {
    uVar2 = 0xff;
  }
  else {
    uVar2 = FUN_005d92b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),iVar3 + 8);
  }
  *(undefined4 *)(iVar3 + 0x1c) = 0x49f42400;
  *(undefined2 *)(iVar3 + 0x20) = 0;
  *(undefined2 *)(iVar3 + 0x22) = 0;
  *(undefined4 *)(iVar3 + 0x28) = 0x40a00000;
  *(undefined1 *)(iVar3 + 0x24) = uVar2;
  *(byte *)(iVar3 + 0x17) = *(byte *)(iVar3 + 0x17) & 0xbf | 0x20;
  *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) & 0xfffffffe;
  return;
}


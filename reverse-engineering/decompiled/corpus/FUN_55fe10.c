/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55fe10; label: FUN_0055fe10
 */

void FUN_0055fe10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x128);
  *(undefined4 *)(param_1 + 0x295c) = 0;
  if ((*(byte *)(iVar1 + 100) & 8) != 0) {
    *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    uVar2 = FUN_0066b8c0(*(undefined4 *)(param_1 + 0x11c),(uint *)(param_1 + 0x104),
                         *(undefined4 *)(param_1 + 0x108),0,param_1 + 0x80,
                         *(undefined4 *)(param_1 + 0x13c),0,*(undefined2 *)(iVar1 + 0x9a),
                         *(undefined2 *)(iVar1 + 0x9a),*(undefined2 *)(iVar1 + 0x98));
    *(undefined4 *)(param_1 + 0x295c) = uVar2;
  }
  return;
}


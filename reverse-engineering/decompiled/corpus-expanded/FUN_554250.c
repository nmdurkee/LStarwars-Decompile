/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x554250; label: FUN_00554250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00554250(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  *(undefined4 *)(param_1 + 0x46e0) = 0;
  *(undefined4 *)(param_1 + 0x46e4) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xf2) == '\0') {
    return 0;
  }
  puVar1 = (uint *)(param_1 + 0x104);
  uVar2 = FUN_005a0760(puVar1,param_1 + 0x108,0,*(undefined1 *)(*(int *)(param_1 + 0x128) + 0x105));
  *(undefined4 *)(param_1 + 0x46e8) = uVar2;
  uVar3 = *puVar1 + 0xf & 0xfffffff0;
  *puVar1 = uVar3;
  *(uint *)(param_1 + 0x46e0) = uVar3;
  *puVar1 = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf2) * 0x304 + uVar3;
  _memset(*(void **)(param_1 + 0x46e0),0,(uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf2) * 0x304);
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xf2) != '\0') {
    iVar5 = 0;
    do {
      uVar2 = FUN_005a05f0(puVar1,param_1 + 0x108,*(undefined4 *)(param_1 + 0x46e8),
                           *(undefined4 *)(param_1 + 0x2960));
      *(undefined4 *)(*(int *)(param_1 + 0x46e0) + 0x68 + iVar5) = uVar2;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x304;
    } while (iVar4 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf2));
  }
  *puVar1 = *puVar1 + 3 & 0xfffffffc;
  return *(undefined4 *)(param_1 + 0x46e0);
}


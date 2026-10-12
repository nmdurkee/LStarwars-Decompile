/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5ae7d0; label: FUN_005ae7d0
 */

undefined4 FUN_005ae7d0(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar2 = param_1;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xf5) != '\0') {
    puVar1 = (uint *)(param_1 + 0x104);
    puVar3 = (uint *)(*(int *)(param_1 + 0x104) + 3U & 0xfffffffc);
    *(uint **)(param_1 + 0x5108) = puVar3;
    *puVar1 = (uint)(puVar3 + 4);
    iVar6 = 0;
    uVar4 = FUN_005a0760(puVar1,param_1 + 0x108,0,*(undefined1 *)(*(int *)(param_1 + 0x128) + 0xf5))
    ;
    puVar3[3] = uVar4;
    uVar4 = *puVar1 + 3 & 0xfffffffc;
    *puVar1 = uVar4;
    *puVar3 = uVar4;
    *puVar1 = *puVar1 + (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf5) * 0x28;
    _memset((void *)*puVar3,0,(uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf5) * 0x28);
    if (*(char *)(*(int *)(param_1 + 0x128) + 0xf5) != '\0') {
      param_1 = 0;
      do {
        uVar5 = FUN_005a05f0(puVar1,iVar2 + 0x108,puVar3[3],*(undefined4 *)(iVar2 + 0x2960));
        *(undefined4 *)(*puVar3 + 0x20 + param_1) = uVar5;
        param_1 = param_1 + 0x28;
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)(uint)*(byte *)(*(int *)(iVar2 + 0x128) + 0xf5));
    }
    *puVar1 = *puVar1 + 3 & 0xfffffffc;
  }
  return *(undefined4 *)(iVar2 + 0x5108);
}


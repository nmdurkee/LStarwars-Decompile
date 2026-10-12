/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x472a50; label: FUN_00472a50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00472a50(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x5074) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xeb) != '\0') {
    uVar2 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x5074) = uVar2;
    puVar1 = *(undefined4 **)(param_1 + 0x5074);
    *(uint *)(param_1 + 0x104) = uVar2 + 0x10;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    uVar2 = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 0x104) = uVar2;
    *(uint *)(*(int *)(param_1 + 0x5074) + 0xc) = uVar2;
    *(int *)(param_1 + 0x104) =
         *(int *)(param_1 + 0x104) + (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xfd) * 0xa0;
    _memset(*(void **)(*(int *)(param_1 + 0x5074) + 0xc),0,
            (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xfd) * 0xa0);
  }
  return *(undefined4 *)(param_1 + 0x5074);
}


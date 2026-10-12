/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a6ed0; label: FUN_005a6ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005a6ed0(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x46bc) = 0;
  *(undefined4 *)(param_1 + 0x46c0) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xff) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x46bc) = uVar1;
    *(uint *)(param_1 + 0x104) = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xff) * 0xd4 + uVar1;
  }
  return uVar1;
}


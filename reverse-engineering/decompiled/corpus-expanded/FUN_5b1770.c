/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b1770; label: FUN_005b1770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b1770(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
  *(uint *)(param_1 + 0x46d0) = uVar1;
  *(uint *)(param_1 + 0x104) = uVar1 + 0xf00;
  *(undefined4 *)(param_1 + 0x46cc) = 0;
  _memset(*(void **)(param_1 + 0x46d0),0,0xf00);
  uVar1 = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
  *(uint *)(param_1 + 0x46d8) = uVar1;
  *(uint *)(param_1 + 0x104) = uVar1 + 0xc00;
  *(undefined4 *)(param_1 + 0x46d4) = 0;
  _memset(*(void **)(param_1 + 0x46d8),0,0xc00);
  return 1;
}


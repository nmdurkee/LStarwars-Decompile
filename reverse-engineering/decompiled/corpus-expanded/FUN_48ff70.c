/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48ff70; label: FUN_0048ff70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0048ff70(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x5068) = 0;
  *(undefined4 *)(param_1 + 0x506c) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xeb) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x5068) = uVar1;
    *(uint *)(param_1 + 0x104) = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xeb) * 0xa0 + uVar1;
  }
  return uVar1;
}


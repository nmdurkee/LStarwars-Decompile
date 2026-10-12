/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x468780; label: FUN_00468780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00468780(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    if ((param_2 != 0) && ((*(byte *)(iVar1 + 0xa0) & 1) == 0)) {
      FUN_005a1230(*(undefined4 *)(iVar1 + 0x28));
    }
    *(uint *)(iVar1 + 0xa0) =
         *(uint *)(iVar1 + 0xa0) ^ ((uint)(param_2 != 0) ^ *(uint *)(iVar1 + 0xa0)) & 1;
    uVar2 = *(uint *)(iVar1 + 0xa0);
    if (param_2 != 0) {
      *(undefined4 *)(iVar1 + 0x48) = 0;
      *(undefined4 *)(iVar1 + 0x50) = 0;
      *(uint *)(iVar1 + 0xa0) = uVar2 & 0xfffeffaf;
      if ((*(byte *)(iVar1 + 0x74) & 8) != 0) {
        *(uint *)(iVar1 + 0xa0) = uVar2 & 0xfffefdaf;
      }
      *(uint *)(iVar1 + 0xa0) = *(uint *)(iVar1 + 0xa0) & 0xffff87ff;
      FUN_005a0670(*(undefined4 *)(iVar1 + 0x28));
      *(undefined4 *)(iVar1 + 0x68) = 0x3f800000;
      *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(iVar1 + 0x10);
      *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(iVar1 + 0x14);
      *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x18);
      FUN_005a0c20(*(undefined4 *)(iVar1 + 0x28),(undefined4 *)(iVar1 + 0x1c),iVar1 + 0x68,2,1,1);
    }
  }
  return;
}


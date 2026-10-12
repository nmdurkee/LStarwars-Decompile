/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x60a2b0; label: FUN_0060a2b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0060a2b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != param_2) {
    iVar1 = param_2;
    do {
      iVar2 = iVar1 + -8;
      *(undefined4 *)((param_3 - param_2) + iVar2) = *(undefined4 *)(iVar1 + -8);
      *(undefined4 *)((param_3 - param_2) + 4 + iVar2) = *(undefined4 *)(iVar1 + -4);
      iVar1 = iVar2;
    } while (iVar2 != param_1);
  }
  return param_3 + (param_2 - param_1 >> 3) * -8;
}


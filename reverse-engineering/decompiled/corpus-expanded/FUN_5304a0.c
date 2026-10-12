/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x5304a0; label: FUN_005304a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005304a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0051fc60(param_1,param_2,param_4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x28) = param_3;
  }
  return;
}


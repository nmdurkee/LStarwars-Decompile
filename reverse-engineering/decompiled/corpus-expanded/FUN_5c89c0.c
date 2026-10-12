/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c89c0; label: FUN_005c89c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c89c0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_3 * 0x380 + in_ECX;
  FUN_005c8810(iVar1 + 0x280,*(undefined4 *)(iVar1 + 0x2a0),param_2);
  return;
}


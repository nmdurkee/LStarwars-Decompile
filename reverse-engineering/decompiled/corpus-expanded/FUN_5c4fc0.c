/* Ghidra pseudocode, not original source.
 * ev_2dc15e7d3c3d1805147447414f3f14c0abe3c311ca5fc4e615c2e0419915bb96
 * Entry: 0x5c4fc0; label: FUN_005c4fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c4fc0(int param_1,int param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_006056f0(param_1 / 2,param_2 / 2,1,1,2);
  *(undefined4 *)(in_ECX + 0x18) = uVar1;
  FUN_005f7d00(uVar1,2,2,0);
  FUN_005f7ed0(*(undefined4 *)(in_ECX + 0x18),2,2);
  return;
}


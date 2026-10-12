/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43e390; label: FUN_0043e390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0043e390(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    *(uint *)(iVar1 + 0x60) =
         *(uint *)(iVar1 + 0x60) ^ ((uint)(param_2 == 0) * 2 ^ *(uint *)(iVar1 + 0x60)) & 2;
  }
  return;
}


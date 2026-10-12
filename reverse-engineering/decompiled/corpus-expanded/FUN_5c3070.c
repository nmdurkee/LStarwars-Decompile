/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c3070; label: FUN_005c3070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c3070(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1 * 0x380 + in_ECX;
  *(undefined4 *)(iVar1 + 0x354 + *(int *)(iVar1 + 0x374) * 4) = param_2;
  *(int *)(iVar1 + 0x374) = *(int *)(iVar1 + 0x374) + 1;
  return;
}


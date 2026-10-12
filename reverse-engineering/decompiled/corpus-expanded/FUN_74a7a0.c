/* Ghidra pseudocode, not original source.
 * ev_e0447f8e73d2150c5385a8aa294440164da99c01f5f62ba5bd70b4e5b4546b39
 * Entry: 0x74a7a0; label: FUN_0074a7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0074a7a0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_007493d0(param_1,in_ECX + 0xbb0,0x5000,in_ECX + 0xbc0);
  *(int *)(in_ECX + 0x208) = iVar1;
  return iVar1 != 0;
}


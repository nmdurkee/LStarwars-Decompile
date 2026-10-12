/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6bebd0; label: FUN_006bebd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006bebd0(void)

{
  int iVar1;
  int in_ECX;
  float local_10;
  undefined1 local_c [12];
  
  local_10 = 1.0;
  iVar1 = FUN_005cfac0(in_ECX + 0x18);
  if (iVar1 != 0) {
    FUN_005d0260(in_ECX + 0x18,local_c,&local_10);
  }
  return (float10)local_10;
}


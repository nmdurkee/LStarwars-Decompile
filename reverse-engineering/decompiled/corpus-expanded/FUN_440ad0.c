/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440ad0; label: FUN_00440ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440ad0(void)

{
  int iVar1;
  undefined4 in_stack_00000014;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&local_c,in_stack_00000014,1);
  iVar1 = FUN_005cfac0(&local_c);
  if (iVar1 != 0) {
    iVar1 = FUN_005cfd60(&local_c);
    return (float10)iVar1;
  }
  return (float10)0;
}


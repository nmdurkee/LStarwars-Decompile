/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x5401a0; label: FUN_005401a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005401a0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f8b10(param_1,&DAT_007614fc);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_004f8b10(param_1,&DAT_007614f8);
  return (-(uint)(iVar1 != 0) & 0xfffffffe) + 1;
}


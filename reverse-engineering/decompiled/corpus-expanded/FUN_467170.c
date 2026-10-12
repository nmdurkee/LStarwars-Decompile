/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467170; label: FUN_00467170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00467170(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    FUN_005a15e0(*(undefined4 *)(iVar1 + 0x28),param_2);
    *(uint *)(iVar1 + 0xa0) =
         *(uint *)(iVar1 + 0xa0) ^ ((uint)(param_2 != 0) * 2 ^ *(uint *)(iVar1 + 0xa0)) & 2;
  }
  return;
}


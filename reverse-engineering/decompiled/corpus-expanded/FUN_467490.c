/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467490; label: FUN_00467490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00467490(void)

{
  undefined4 *puVar1;
  int in_EAX;
  float local_20;
  float local_1c;
  undefined1 local_18 [4];
  float local_14;
  undefined1 local_c [4];
  float local_8;
  
  if ((in_EAX != 0) && (*(int *)(in_EAX + 0x28) != 0)) {
    puVar1 = *(undefined4 **)(*(int *)(in_EAX + 0x28) + 0x18);
    local_1c = 1e+09;
    local_20 = -1e+09;
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      FUN_005d0130(puVar1 + 1,local_18,local_c);
      if (local_14 < local_1c) {
        local_1c = local_14;
      }
      if (local_20 < local_8) {
        local_20 = local_8;
      }
    }
    return (float10)(local_20 - local_1c);
  }
  return (float10)0;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c25c0; label: FUN_006c25c0
 */

void FUN_006c25c0(void)

{
  int in_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if ((*(int *)(in_ECX + 100) == 1) || (*(int *)(in_ECX + 100) == 2)) {
    local_20 = *(undefined4 *)(in_ECX + 0x50);
    local_1c = *(undefined4 *)(in_ECX + 0x54);
    local_18 = *(undefined4 *)(in_ECX + 0x58);
    local_14 = *(undefined4 *)(in_ECX + 0x5c);
    FUN_005b3b30(&local_20,&local_20);
  }
  return;
}


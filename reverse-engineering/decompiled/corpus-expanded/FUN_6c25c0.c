/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c25c0; label: FUN_006c25c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


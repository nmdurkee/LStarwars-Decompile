/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x493c70; label: FUN_00493c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00493c70(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = DAT_00826494;
  if (DAT_00826494 == 3) {
    iVar1 = *(int *)(in_ECX + 0x62c);
  }
  return iVar1;
}


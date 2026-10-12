/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x441340; label: FUN_00441340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00441340(void)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  
  if (((in_EAX != 0) && (*(char *)(in_EAX + 0x7b5) == 'J')) && (*(int *)(in_EAX + 0x798) != 0)) {
    if ((in_ECX != 0) && (iVar1 = FUN_004f8b10(*(int *)(in_EAX + 0x798) + 0x58), iVar1 != 0)) {
      return 0;
    }
    return 1;
  }
  return 0;
}


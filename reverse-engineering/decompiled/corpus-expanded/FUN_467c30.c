/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467c30; label: FUN_00467c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_00467c30(undefined4 param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0:
    return "AtEnd";
  case 1:
    return "NotAtStart";
  case 2:
    return "AtStart";
  case 3:
    return "StackComplete";
  case 4:
    return "StackCompleteInOrder";
  case 5:
    return "Destroyed/Thrown";
  case 6:
    return "Complete";
  case 7:
    return "BeingUsed";
  default:
    return (char *)0x0;
  }
}


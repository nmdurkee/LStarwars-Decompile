/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x558830; label: FUN_00558830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_00558830(undefined4 param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0:
    return "AtEnd";
  case 1:
    return "NotAtStart";
  case 2:
    return "Proximity";
  case 3:
    return "AtStart";
  case 4:
    return "PlayingForward";
  default:
    return (char *)0x0;
  }
}


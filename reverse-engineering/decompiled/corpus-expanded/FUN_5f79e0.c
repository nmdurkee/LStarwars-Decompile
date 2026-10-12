/* Ghidra pseudocode, not original source.
 * ev_051ca52d2d0f5927e6fa186b1b96c133d3b61d010079a76ac2917bb13fe5eb00
 * Entry: 0x5f79e0; label: FUN_005f79e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f79e0(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0x15:
  case 0x16:
    return 2;
  default:
    return 0;
  case 0x4b:
    return 4;
  case 0x53:
    return 5;
  }
}


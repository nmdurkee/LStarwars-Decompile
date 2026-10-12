/* Ghidra pseudocode, not original source.
 * ev_051ca52d2d0f5927e6fa186b1b96c133d3b61d010079a76ac2917bb13fe5eb00
 * Entry: 0x5f7940; label: FUN_005f7940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f7940(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return 1;
  case 1:
    return 2;
  case 2:
    return 3;
  case 3:
    return 4;
  default:
    return 0xffffffff;
  }
}


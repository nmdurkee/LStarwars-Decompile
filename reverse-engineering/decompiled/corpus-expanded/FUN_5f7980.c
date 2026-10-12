/* Ghidra pseudocode, not original source.
 * ev_051ca52d2d0f5927e6fa186b1b96c133d3b61d010079a76ac2917bb13fe5eb00
 * Entry: 0x5f7980; label: FUN_005f7980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f7980(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 1:
    return 0x16;
  case 2:
    return 0x15;
  default:
    return 0xffffffff;
  case 4:
    return 0x4b;
  case 5:
    return 0x53;
  case 10:
    return 0x72;
  }
}


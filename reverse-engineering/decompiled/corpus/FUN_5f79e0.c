/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f79e0; label: FUN_005f79e0
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


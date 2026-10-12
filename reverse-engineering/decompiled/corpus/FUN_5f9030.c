/* Ghidra analysis pseudocode, not original source.
 * ev_a85358c7a67f9df9af49bd13a9e5d6f2df9e1c4faca93f034535aa61df0d1386
 * Entry: 0x5f9030; label: FUN_005f9030
 */

undefined4 FUN_005f9030(undefined4 param_1)

{
  switch(param_1) {
  case 0:
  case 1:
    return 0x10;
  case 2:
    return 0x18;
  case 3:
    return 0x20;
  case 4:
    return 4;
  case 5:
  case 0x14:
    return 8;
  default:
    return 0;
  }
}


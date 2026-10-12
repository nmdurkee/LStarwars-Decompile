/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d1d70; label: FUN_005d1d70
 */

char FUN_005d1d70(void)

{
  undefined1 *puVar1;
  int unaff_ESI;
  
  FUN_004f7fb0();
  puVar1 = *(undefined1 **)(unaff_ESI + 0x510);
  switch(*puVar1) {
  case 0x21:
    goto switchD_005d1d91_caseD_21;
  default:
    FUN_005c12e0(puVar1,*(undefined4 *)(unaff_ESI + 0x51c));
    return '\0';
  case 0x3c:
    if (puVar1[1] == '=') {
      return '\x03';
    }
    if (puVar1[1] != '>') {
      return '\x01';
    }
switchD_005d1d91_caseD_21:
    return '\x05';
  case 0x3d:
    return '\0';
  case 0x3e:
    return (puVar1[1] == '=') * '\x02' + '\x02';
  }
}


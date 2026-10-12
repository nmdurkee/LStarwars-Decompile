/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d1d70; label: FUN_005d1d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


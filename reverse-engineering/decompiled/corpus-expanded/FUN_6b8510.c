/* Ghidra pseudocode, not original source.
 * ev_6e4df963812b3a1824100f136853f234100848169b29b7b6e42d47a7916e68c6
 * Entry: 0x6b8510; label: FUN_006b8510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b8510(void)

{
  uint in_EAX;
  
  if (DAT_02854c31 != '\0') {
    *(uint *)(*DAT_02854d10 + 0xc) =
         ((int)in_EAX >> 0x10 & 0xffU) + (in_EAX & 0xff) * 0x10000 + (in_EAX & 0xff000000) +
         (in_EAX & 0xff00);
    return;
  }
  *(uint *)(*DAT_02854d10 + 0xc) =
       ((int)in_EAX >> 1 & 0x7f00U) + (in_EAX & 0xfe) * 0x8000 + ((int)in_EAX >> 0x11 & 0x7fU) +
       (in_EAX & 0xff000000);
  return;
}


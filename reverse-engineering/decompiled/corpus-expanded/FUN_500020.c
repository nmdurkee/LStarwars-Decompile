/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x500020; label: FUN_00500020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00500020(void)

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


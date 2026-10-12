/* Ghidra pseudocode, not original source.
 * ev_051ca52d2d0f5927e6fa186b1b96c133d3b61d010079a76ac2917bb13fe5eb00
 * Entry: 0x5f77d0; label: FUN_005f77d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f77d0(void)

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


/* Ghidra pseudocode, not original source.
 * ev_12b000564e8cba1f3519ff70f1088df218803466ba65b3333f742de5377565cf
 * Entry: 0x4200c0; label: FUN_004200c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004200c0(void)

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


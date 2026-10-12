/* Ghidra pseudocode, not original source.
 * ev_0b3cdb0849a5c3a2f544331fa814d8282bd684db9c1ec6ffa505f1c54b54b4d0
 * Entry: 0x508f70; label: FUN_00508f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00508f70(void)

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


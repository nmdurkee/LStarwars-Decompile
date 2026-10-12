/* Ghidra pseudocode, not original source.
 * ev_184291d84d57a0e0f71d3c8a05fa8a71135e786a990f62c870cdb26b01607f61
 * Entry: 0x60f3d0; label: FUN_0060f3d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060f3d0(void)

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


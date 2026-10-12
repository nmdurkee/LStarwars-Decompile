/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x632280; label: FUN_00632280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00632280(void)

{
  uint in_EAX;
  
  if (in_EAX < 0x11) {
    if (4 < in_EAX) {
      return (-(uint)(8 < in_EAX) & 8) + 8;
    }
    if (2 < in_EAX) {
      in_EAX = 4;
    }
    return in_EAX;
  }
  if (in_EAX < 0x41) {
    return (-(uint)(0x20 < in_EAX) & 0x20) + 0x20;
  }
  if (in_EAX < 0x81) {
    return 0x80;
  }
  if (0x100 < in_EAX) {
    return (-(uint)(0x200 < in_EAX) & 0x200) + 0x200;
  }
  return 0x100;
}


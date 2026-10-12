/* Ghidra pseudocode, not original source.
 * ev_be0e8c275e05089d0d3721217efe04c64b57d8015b7c05fc7983bdf2d5551943
 * Entry: 0x6e69d0; label: __allshl
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __allshl
   
   Library: Visual Studio */

longlong __allshl(void)

{
  uint in_EAX;
  byte in_CL;
  int in_EDX;
  
  if (0x3f < in_CL) {
    return 0;
  }
  if (in_CL < 0x20) {
    return CONCAT44(in_EDX << (in_CL & 0x1f) | in_EAX >> 0x20 - (in_CL & 0x1f),
                    in_EAX << (in_CL & 0x1f));
  }
  return (ulonglong)(in_EAX << (in_CL & 0x1f)) << 0x20;
}


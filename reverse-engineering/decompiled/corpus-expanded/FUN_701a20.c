/* Ghidra pseudocode, not original source.
 * ev_7661b65940d612abb24c352a2878817c29de5a09135c60a7ac694e4ecef30f99
 * Entry: 0x701a20; label: __aullshr
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __aullshr
   
   Library: Visual Studio 2005 Release */

ulonglong __aullshr(void)

{
  uint in_EAX;
  byte in_CL;
  uint in_EDX;
  
  if (0x3f < in_CL) {
    return 0;
  }
  if (in_CL < 0x20) {
    return CONCAT44(in_EDX >> (in_CL & 0x1f),
                    in_EAX >> (in_CL & 0x1f) | in_EDX << 0x20 - (in_CL & 0x1f));
  }
  return (ulonglong)(in_EDX >> (in_CL & 0x1f));
}


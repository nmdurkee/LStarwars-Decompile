/* Ghidra pseudocode, not original source.
 * ev_626d54f17f079edfd1ff8b6caea4a3c32539f18361fa5c980ebe5ce2dfd8aaf4
 * Entry: 0x6fa280; label: ___get_fpsr_sse2
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    ___get_fpsr_sse2
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

undefined4 ___get_fpsr_sse2(void)

{
  undefined4 local_8;
  
  if (DAT_029a9c48 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = MXCSR;
  }
  return local_8;
}


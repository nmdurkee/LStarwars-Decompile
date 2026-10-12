/* Ghidra analysis pseudocode, not original source.
 * ev_0bf9b7e593526bfec203cc134385061e8cfbfb74a64816bf5716f75cb05b36af
 * Entry: 0x6fa280; label: ___get_fpsr_sse2
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


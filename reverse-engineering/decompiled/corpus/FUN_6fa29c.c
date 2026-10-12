/* Ghidra analysis pseudocode, not original source.
 * ev_0bf9b7e593526bfec203cc134385061e8cfbfb74a64816bf5716f75cb05b36af
 * Entry: 0x6fa29c; label: ___set_fpsr_sse2
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___set_fpsr_sse2
   
   Library: Visual Studio 2005 Release */

void ___set_fpsr_sse2(uint param_1)

{
  if (DAT_029a9c48 != 0) {
    if (((param_1 & 0x40) == 0) || (DAT_0082a068 == 0)) {
      MXCSR = param_1 & 0xffffffbf;
    }
    else {
      MXCSR = param_1;
    }
  }
  return;
}


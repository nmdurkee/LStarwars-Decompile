/* Ghidra analysis pseudocode, not original source.
 * ev_0bf9b7e593526bfec203cc134385061e8cfbfb74a64816bf5716f75cb05b36af
 * Entry: 0x6fab47; label: ___initmbctable
 */

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 2005 Release */

undefined4 ___initmbctable(void)

{
  if (DAT_029a9c58 == 0) {
    __setmbcp(-3);
    DAT_029a9c58 = 1;
  }
  return 0;
}


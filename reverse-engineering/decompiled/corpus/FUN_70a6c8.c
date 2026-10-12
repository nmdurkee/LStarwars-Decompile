/* Ghidra analysis pseudocode, not original source.
 * ev_aee1a4f0943f0e53edaf0cbac59fb891b878b74e3aefed4690394b4ea17c7eca
 * Entry: 0x70a6c8; label: ___free_lconv_num
 */

/* Library Function - Single Match
    ___free_lconv_num
   
   Library: Visual Studio 2005 Release */

void ___free_lconv_num(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((undefined *)*param_1 != PTR_DAT_0082aa08) {
      _free((undefined *)*param_1);
    }
    if ((undefined *)param_1[1] != PTR_DAT_0082aa0c) {
      _free((undefined *)param_1[1]);
    }
    if ((undefined *)param_1[2] != PTR_DAT_0082aa10) {
      _free((undefined *)param_1[2]);
    }
  }
  return;
}


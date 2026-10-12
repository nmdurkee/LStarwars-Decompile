/* Ghidra pseudocode, not original source.
 * ev_3d36383f96f3bc0df86ca3b0bd2be0f2b31f3818026a757d33379a6c98cf77a3
 * Entry: 0x70a6c8; label: ___free_lconv_num
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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


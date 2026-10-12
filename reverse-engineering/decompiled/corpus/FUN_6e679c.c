/* Ghidra analysis pseudocode, not original source.
 * ev_436cabf158ac3440cfd7f7b18cfc1716350a7e3fc3c1046d0c76060bee472dbc
 * Entry: 0x6e679c; label: FUN_006e679c
 */

void FUN_006e679c(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00777ca0;
  FUN_0060ca50();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}


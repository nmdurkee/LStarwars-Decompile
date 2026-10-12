/* Ghidra pseudocode, not original source.
 * ev_be0e8c275e05089d0d3721217efe04c64b57d8015b7c05fc7983bdf2d5551943
 * Entry: 0x6e6757; label: FUN_006e6757
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e6757(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00777c94;
  FUN_0060ca50();
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}


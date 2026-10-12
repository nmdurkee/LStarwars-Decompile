/* Ghidra pseudocode, not original source.
 * ev_742d340bc2a041ef5ff6078bdc4a89a7f4acdb81012c0f9f5c92fd03ca8daa18
 * Entry: 0x5fa1d0; label: FUN_005fa1d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fa1d0(void)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = &PTR_FUN_0076a75c;
  exception::~exception(in_ECX);
  return;
}


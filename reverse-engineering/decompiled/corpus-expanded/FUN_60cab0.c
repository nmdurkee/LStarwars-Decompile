/* Ghidra pseudocode, not original source.
 * ev_0c11dca3c01e2e078e91e20b90f08271c2558dc41f56def09ad2bffabccf1687
 * Entry: 0x60cab0; label: FUN_0060cab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060cab0(byte param_1)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = &PTR_FUN_0076a8cc;
  if (0xf < *(uint *)(in_ECX + 0x24)) {
    FUN_006e85b0(*(undefined4 *)(in_ECX + 0x10));
  }
  *(undefined4 *)(in_ECX + 0x24) = 0xf;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  in_ECX[0x10] = (exception)0x0;
  exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}


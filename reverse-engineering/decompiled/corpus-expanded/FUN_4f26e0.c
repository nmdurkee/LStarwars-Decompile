/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f26e0; label: FUN_004f26e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f26e0(short *param_1,short *param_2)

{
  short sVar1;
  
  sVar1 = *param_2;
  if (sVar1 == 0) {
    *param_1 = *param_2;
    return;
  }
  do {
    if (((ushort)(sVar1 - 0x41U) < 0x1a) || ((ushort)(sVar1 - 0xc0U) < 0x20)) {
      sVar1 = sVar1 + 0x20;
    }
    param_2 = param_2 + 1;
    *param_1 = sVar1;
    sVar1 = *param_2;
    param_1 = param_1 + 1;
  } while (sVar1 != 0);
  *param_1 = *param_2;
  return;
}


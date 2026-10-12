/* Ghidra pseudocode, not original source.
 * ev_d4822431da3638fa8d20ce7973e149332a7479471103665647c7faa9758e6d9d
 * Entry: 0x60ec40; label: thunk_FUN_0060e9e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 thunk_FUN_0060e9e0(void)

{
  int iVar1;
  int *in_ECX;
  
  if (*in_ECX != 2) {
    return 0xa1000003;
  }
  if (0 < in_ECX[0x44]) {
    iVar1 = FUN_004fa5f0(in_ECX + 1,in_ECX[0x41]);
    if (iVar1 == 0) {
      return 0xa1000001;
    }
    FUN_004f6de0(iVar1,0,0,2);
    FUN_004f03d0(iVar1,in_ECX + 0x45,in_ECX[0x44]);
    FUN_004f99e0(iVar1);
    in_ECX[0x44] = 0;
    in_ECX[0x41] = 2;
  }
  return 0;
}


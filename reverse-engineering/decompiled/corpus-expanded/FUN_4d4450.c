/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d4450; label: FUN_004d4450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d4450(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (((iVar1 != 0) && (DAT_00881ae8 != 0)) && (DAT_00881c28 < '\x10')) {
    iVar1 = FUN_004d4380(*(undefined4 *)(param_1 + 0x510));
    if (-1 < iVar1) {
      (&DAT_00881b18)[DAT_00881c28] = (char)iVar1;
      DAT_00881c28 = DAT_00881c28 + '\x01';
    }
  }
  return;
}


/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6cca00; label: FUN_006cca00
 */

void FUN_006cca00(int param_1)

{
  int iVar1;
  undefined1 local_60 [16];
  undefined1 local_50 [76];
  
  if (2 < *(int *)(param_1 + 8)) {
    FUN_006cbc00(param_1);
  }
  iVar1 = FUN_006ca2f0(local_60);
  if (iVar1 != 0) {
    FUN_006c8760(0x20,DAT_02973abc,local_50,0);
    FUN_006c49b0(local_60,local_50);
  }
  return;
}


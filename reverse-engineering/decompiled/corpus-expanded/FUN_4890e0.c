/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x4890e0; label: FUN_004890e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004890e0(void)

{
  int iVar1;
  int iVar2;
  int in_EDX;
  
  iVar1 = DAT_0087b2c4;
  if ((in_EDX != -1) && (DAT_0087b2c4 < 0x30)) {
    if (DAT_0087b2c4 < 2) {
      *(short *)((int)&DAT_0093d590 + DAT_0087b2c4 * 2) = (short)in_EDX;
    }
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if ((short)(&DAT_0087a840)[iVar2 * 2] == in_EDX) {
          return 0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    (&DAT_0087a840)[iVar1 * 2] = (short)in_EDX;
    *(undefined2 *)(&DAT_0087a842 + iVar1 * 4) = 1;
    DAT_0087b2c4 = iVar1 + 1;
    (&DAT_0087a840)[DAT_0087b2c4 * 2] = 0xffff;
    return 1;
  }
  return 0;
}


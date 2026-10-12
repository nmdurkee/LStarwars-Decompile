/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x6069a0; label: FUN_006069a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006069a0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  *(undefined2 *)(in_ECX + 3) = 0;
  in_ECX[4] = 0;
  *(undefined2 *)(in_ECX + 5) = 0;
  *(undefined2 *)((int)in_ECX + 0x16) = 0;
  *(undefined2 *)(in_ECX + 6) = 0xffff;
  FUN_005fb810();
  if (DAT_02854c30 == '\0') {
    _memset(&DAT_00986a88,0,0x400);
    DAT_02854c30 = '\x01';
  }
  iVar1 = 0;
  do {
    if ((&DAT_00986a88)[iVar1] == 0) {
      (&DAT_00986a88)[iVar1] = in_ECX;
      *(short *)(in_ECX + 6) = (short)iVar1;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x100);
  return;
}


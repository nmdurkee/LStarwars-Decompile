/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x605bd0; label: FUN_00605bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00605bd0(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = DAT_02854bc8;
  if ((*DAT_02854bc8 != 0) || (piVar1 = DAT_02854bc8, (short)DAT_02854bc8[3] != 0)) {
    FUN_005fb810();
    piVar1 = DAT_02854bc8;
    *piVar2 = 0;
    *(undefined1 *)(piVar2 + 1) = 0;
    piVar2[2] = 0;
    *(undefined2 *)(piVar2 + 3) = 0;
    piVar2[4] = 0;
    *(undefined2 *)(piVar2 + 5) = 0;
    *(undefined2 *)((int)piVar2 + 0x16) = 0;
  }
  piVar2[0x28] = 1;
  if ((piVar1[7] != 0) || (piVar2 = piVar1, (short)piVar1[10] != 0)) {
    FUN_005fb810();
    piVar2 = DAT_02854bc8;
    piVar1[7] = 0;
    *(undefined1 *)(piVar1 + 8) = 0;
    piVar1[9] = 0;
    *(undefined2 *)(piVar1 + 10) = 0;
    piVar1[0xb] = 0;
    *(undefined2 *)(piVar1 + 0xc) = 0;
    *(undefined2 *)((int)piVar1 + 0x32) = 0;
  }
  piVar1[0x28] = 1;
  if ((piVar2[0xe] != 0) || ((short)piVar2[0x11] != 0)) {
    FUN_005fb810();
    piVar2[0xe] = 0;
    *(undefined1 *)(piVar2 + 0xf) = 0;
    piVar2[0x10] = 0;
    *(undefined2 *)(piVar2 + 0x11) = 0;
    piVar2[0x12] = 0;
    *(undefined2 *)(piVar2 + 0x13) = 0;
    *(undefined2 *)((int)piVar2 + 0x4e) = 0;
  }
  piVar1 = DAT_02854bcc;
  piVar2[0x28] = 1;
  if ((*piVar1 != 0) || ((short)piVar1[3] != 0)) {
    FUN_005fb810();
    *piVar1 = 0;
    *(undefined1 *)(piVar1 + 1) = 0;
    piVar1[2] = 0;
    *(undefined2 *)(piVar1 + 3) = 0;
    piVar1[4] = 0;
    *(undefined2 *)(piVar1 + 5) = 0;
    *(undefined2 *)((int)piVar1 + 0x16) = 0;
  }
  piVar1[0x28] = 1;
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68b890; label: FUN_0068b890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068b890(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (DAT_02921884 != -1) {
    iVar4 = *(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14);
    iVar2 = DAT_02921884 * 0x50 + DAT_02962a14;
    if (iVar4 != 1) {
      if (param_1 < iVar4 + -1) {
        do {
          puVar3 = (undefined4 *)
                   (DAT_02962a18 + (*(short *)(iVar2 + 0x40) * DAT_02962a10 + param_1) * 0x20);
          *puVar3 = puVar3[8];
          puVar3[1] = puVar3[9];
          puVar3[2] = puVar3[10];
          iVar4 = (*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 + param_1) *
                  0x20 + DAT_02962a18;
          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 0x2c);
          iVar4 = (*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 + param_1) *
                  0x20 + DAT_02962a18;
          *(undefined2 *)(iVar4 + 0x10) = *(undefined2 *)(iVar4 + 0x30);
          iVar4 = (*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 + param_1) *
                  0x20 + DAT_02962a18;
          *(undefined2 *)(iVar4 + 0x12) = *(undefined2 *)(iVar4 + 0x32);
          iVar2 = DAT_02921884 * 0x50 + DAT_02962a14;
          param_1 = param_1 + 1;
        } while (param_1 < *(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14) + -1);
      }
      piVar1 = (int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14);
      *piVar1 = *piVar1 + -1;
      FUN_00689f70();
      return;
    }
  }
  return;
}


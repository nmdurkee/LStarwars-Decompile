/* Ghidra pseudocode, not original source.
 * ev_67e04bb194beb06fa3ce238b04e3098eb4f9bf275f7ff551e45745ee5a93428c
 * Entry: 0x547060; label: FUN_00547060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00547060(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  iVar1 = param_2 + 0x10;
  piVar2 = (int *)FUN_004eef40(iVar1 * param_1 + 0x20,
                               "d:\\projects\\legosagapc\\nu2api.saga\\gamelib\\listman.c",0x67);
  if (piVar2 != (int *)0x0) {
    piVar5 = piVar2 + 8;
    iVar4 = 1;
    *(short *)((int)piVar2 + 0x12) = (short)param_2;
    *piVar2 = (int)piVar5;
    piVar2[2] = 0;
    piVar2[3] = 0;
    *(short *)(piVar2 + 4) = (short)param_1;
    *(short *)(piVar2 + 5) = (short)iVar1;
    *(undefined2 *)((int)piVar2 + 0x16) = 0;
    piVar3 = piVar5;
    if (1 < param_1) {
      do {
        piVar5 = (int *)((int)piVar3 + iVar1);
        piVar3[1] = (int)piVar5;
        *(short *)(piVar3 + 3) = (short)iVar4 + -1;
        *piVar3 = (int)piVar2;
        iVar4 = iVar4 + 1;
        piVar3 = piVar5;
      } while (iVar4 < param_1);
    }
    piVar5[1] = 0;
    piVar2[1] = (int)piVar5;
    *(short *)(piVar5 + 3) = (short)iVar4 + -1;
    *piVar5 = (int)piVar2;
    piVar2[6] = DAT_0297ad54;
  }
  return;
}


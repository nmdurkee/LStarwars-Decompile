/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c3ec0; label: FUN_006c3ec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c3ec0(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 *puStack_14;
  char *pcStack_10;
  undefined1 local_4 [4];
  
  if (DAT_02973a50 != 0) {
    piVar1 = *(int **)(DAT_02973a50 + 0x10);
    iVar2 = *(int *)(param_2 + 0xc);
    if (*piVar1 != 0) {
      do {
        if (piVar1[1] == *(int *)(iVar2 + 4)) {
          pcStack_10 = (char *)*piVar1;
          goto LAB_006c3ef3;
        }
        piVar1 = piVar1 + 2;
      } while (*piVar1 != 0);
    }
    pcStack_10 = "Unknown";
LAB_006c3ef3:
    puStack_14 = DAT_02973a54;
    FUN_0061e530();
    pcStack_10 = (char *)0x0;
    puStack_14 = local_4;
    (**(code **)(**(int **)(DAT_02973a50 + 8) + 4))
              (*(undefined4 *)(DAT_02973a50 + 0xc),DAT_02973ab0);
    if (*(int *)(iVar2 + 4) == 0) {
      puStack_14 = (undefined1 *)((uint)puStack_14 & ~(1 << ((byte)DAT_02973a58 & 0x1f)));
    }
    else {
      puStack_14 = (undefined1 *)((uint)puStack_14 | 1 << ((byte)DAT_02973a58 & 0x1f));
    }
    iVar2 = 0;
    (**(code **)(**(int **)(DAT_02973a50 + 8) + 8))
              (*(undefined4 *)(DAT_02973a50 + 0xc),DAT_02973ab0,&puStack_14,0,0);
    FUN_006279f0(iVar2);
    FUN_00624220(iVar2);
    if (iVar2 == DAT_02973a7c) {
      DAT_02973a7c = 0;
    }
    if (iVar2 == DAT_02973a80) {
      DAT_02973a80 = 0;
    }
  }
  return;
}


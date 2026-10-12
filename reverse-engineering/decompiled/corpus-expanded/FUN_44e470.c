/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44e470; label: FUN_0044e470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044e470(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    iVar2 = *piVar1;
    if ((param_6 != 0) && (iVar4 = 0, 0 < param_5)) {
      do {
        if ((DAT_009238b0 == (code *)0x0) ||
           (iVar3 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar4 * 4),param_3 + 0x13f),
           iVar3 == 0)) {
          iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757e80);
          if (iVar3 == 0) {
            *(undefined1 *)(param_2 + 0x68) = 1;
          }
          else {
            fVar5 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar4 * 4));
            *(float *)(param_3 + 0x180) = (float)fVar5;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x10a8) != 0)) {
      iVar4 = *(int *)(iVar2 + 0x10a8);
      FUN_0052fcb0(param_3,iVar4 + 0x438,*(undefined4 *)(iVar4 + 1000),iVar4 + 0x420,2,
                   *(undefined4 *)(param_3 + 0x180));
      if (*(char *)(param_2 + 0x68) != '\0') {
        *(int *)(param_3 + 0x1e4) = *(int *)(iVar2 + 0x10a8) + 0x5c;
      }
    }
    return 0;
  }
  return 1;
}


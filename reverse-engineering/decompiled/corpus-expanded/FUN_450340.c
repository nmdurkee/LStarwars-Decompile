/* Ghidra pseudocode, not original source.
 * ev_4aa7baba24777c7cef62b6758f8d176321ddee5c4eaac4ea92e033f295beb802
 * Entry: 0x450340; label: FUN_00450340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00450340(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  ushort *puVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  if (((param_3 == 0) || (piVar3 = *(int **)(param_3 + 0xd0), piVar3 == (int *)0x0)) ||
     (*piVar3 == 0)) {
    return 1;
  }
  iVar4 = *piVar3;
  if (param_6 != 0) {
    *(undefined4 *)(param_2 + 0x6c) = 0;
    if (0 < param_5) {
      do {
        iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"target=opponent");
        if (iVar5 == 0) {
          iVar5 = *(int *)(param_3 + 0xe4);
          *(int *)(param_2 + 0x6c) = iVar5;
joined_r0x004503e7:
          if (iVar5 == 0) {
            return 1;
          }
        }
        else {
          iVar5 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"target=");
          if (iVar5 != 0) {
            iVar5 = FUN_00440120(param_1,iVar5 + 7);
            *(int *)(param_2 + 0x6c) = iVar5;
            goto joined_r0x004503e7;
          }
          iVar5 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"forcepush_highlight_only");
          if (iVar5 == 0) {
            *(undefined1 *)(param_2 + 0x68) = 1;
          }
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_5);
    }
    if (((*(char *)(iVar4 + 0x7b5) == '\x1b') && (*(char *)(param_2 + 0x68) == '\0')) &&
       ((*(int *)(iVar4 + 0x790) != 0 && (*(int *)(param_2 + 0x6c) == 0)))) {
      puVar1 = (ushort *)(*(int *)(iVar4 + 0xca4) + 0x5a);
      *puVar1 = *puVar1 | 0x10;
      *(undefined4 *)(iVar4 + 0xd20) = *(undefined4 *)(iVar4 + 0x790);
      *(uint *)(iVar4 + 0xe20) =
           *(uint *)(iVar4 + 0xe20) ^
           ((uint)*(byte *)(param_2 + 0x68) << 10 ^ *(uint *)(iVar4 + 0xe20)) & 0x400;
      *(uint *)(iVar4 + 0xe20) = *(uint *)(iVar4 + 0xe20) & 0xfffdffff;
      *(undefined1 *)(iVar4 + 0x7b5) = 0xff;
      FUN_004a3270(iVar4,0,0);
    }
  }
  iVar6 = FUN_0055bc80(iVar4,0);
  if (iVar6 == 0) {
    if ((DAT_0093b2a4 != 0) &&
       (param_7 = *(float *)(param_2 + 0x9c) - param_7, *(float *)(param_2 + 0x9c) = param_7,
       param_7 < 0.0)) {
      *(undefined4 *)(param_2 + 0x9c) = 0x3f000000;
      puVar2 = (uint *)(*(int *)(iVar4 + 0xca4) + 8);
      *puVar2 = *puVar2 | DAT_0080228c;
      return 0;
    }
  }
  else {
    puVar1 = (ushort *)(*(int *)(iVar4 + 0xca4) + 0x5a);
    *puVar1 = *puVar1 | 0x10;
    *(undefined4 *)(iVar4 + 0xd20) = *(undefined4 *)(param_2 + 0x6c);
    *(uint *)(iVar4 + 0xe20) =
         *(uint *)(iVar4 + 0xe20) ^
         ((uint)*(byte *)(param_2 + 0x68) << 10 ^ *(uint *)(iVar4 + 0xe20)) & 0x400;
    if (*(int *)(param_2 + 0x70) == 0) {
      if ((*(char *)(iVar4 + 0x7b5) == '\x1b') && (*(int *)(iVar4 + 0x790) != 0)) {
        *(int *)(param_2 + 0x70) = *(int *)(iVar4 + 0x790);
      }
    }
    else if (*(int *)(param_2 + 0x70) != *(int *)(iVar4 + 0x790)) {
      return 1;
    }
  }
  return 0;
}


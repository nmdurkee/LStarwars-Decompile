/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x449cf0; label: FUN_00449cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00449cf0(undefined4 param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  
  if (((((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
       (*piVar2 != 0)) &&
      ((iVar3 = *(int *)(param_3 + 0x144), iVar3 != 0 &&
       ((uint)*(byte *)(param_3 + 0x148) == *(byte *)(iVar3 + 7) - 1)))) &&
     ((*(byte *)(iVar3 + 8) == 1 ||
      ((int)((ulonglong)(uint)*(byte *)(iVar3 + 7) %
            (ulonglong)(longlong)(int)(uint)*(byte *)(iVar3 + 8)) == 1)))) {
    iVar3 = *piVar2;
    *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) | 0x1000000;
    sVar1 = *(short *)(iVar3 + 0x1064);
    if (((sVar1 == DAT_007f1888) || (sVar1 == DAT_007f1894)) || (sVar1 == DAT_007f1890)) {
      FUN_0041bc20(iVar3,(int)DAT_007f188c,(int)sVar1,1);
      *(undefined1 *)(iVar3 + 0x107f) =
           *(undefined1 *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0xf4);
      *(undefined1 *)(iVar3 + 0x107e) =
           *(undefined1 *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0xf4);
    }
    else if (sVar1 == DAT_007f1898) {
      FUN_0041bc20(iVar3,(int)DAT_007f189c,(int)sVar1,1);
      *(undefined1 *)(iVar3 + 0x107f) =
           *(undefined1 *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0xf4);
      *(undefined1 *)(iVar3 + 0x107e) =
           *(undefined1 *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0xf4);
      return 1;
    }
  }
  return 1;
}


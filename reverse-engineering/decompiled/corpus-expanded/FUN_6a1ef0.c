/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a1ef0; label: FUN_006a1ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

undefined4 FUN_006a1ef0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_94 [124];
  undefined4 uStack_18;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 0x1c);
  if (param_2 < 1) {
    uStack_18 = 0x6a1f1b;
    if (*(int *)(param_1 + 0x1c) == 0) {
      FUN_006a1e00();
    }
    FUN_006a1d30(param_1,*(int *)(iVar2 + 4) * 3);
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x14);
    iVar5 = 0;
    *(int *)(param_1 + 0x14) =
         *(int *)(param_1 + 0x14) + *(int *)(iVar2 + 4) * 2 + *(int *)(iVar2 + 4);
    if (0 < *(int *)(iVar1 + 4)) {
      do {
        iVar3 = *(int *)(param_1 + 0x20);
        if (iVar3 < 0x41) {
          _memset((void *)(*(int *)(*(int *)(param_1 + 8) + iVar5 * 4) + iVar3 * 4),0,
                  (*(int *)(param_1 + 0x14) - iVar3) * 4);
        }
        else {
          iVar4 = iVar3;
          if (*(int *)(iVar2 + 4) < iVar3) {
            iVar4 = *(int *)(iVar2 + 4);
          }
          FUN_006b1580(*(int *)(*(int *)(param_1 + 8) + iVar5 * 4) + (iVar3 - iVar4) * 4,auStack_94,
                       iVar4,0x20);
          iVar3 = *(int *)(param_1 + 0x20);
          iVar4 = *(int *)(*(int *)(param_1 + 8) + iVar5 * 4);
          FUN_006b1890(auStack_94,iVar4 + -0x80 + iVar3 * 4,0x20,iVar4 + iVar3 * 4,
                       *(int *)(param_1 + 0x14) - iVar3);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(iVar1 + 4));
      return 0;
    }
  }
  else {
    param_2 = param_2 + *(int *)(param_1 + 0x14);
    if (*(int *)(param_1 + 0x10) < param_2) {
      return 0xffffff7d;
    }
    *(int *)(param_1 + 0x14) = param_2;
    if ((*(int *)(param_1 + 0x1c) == 0) &&
       (*(int *)(iVar2 + 4) < param_2 - *(int *)(param_1 + 0x30))) {
      uStack_18 = 0x6a200d;
      FUN_006a1e00();
    }
  }
  return 0;
}


/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47f8f0; label: FUN_0047f8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0047f8f0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *param_2;
  if ((*(int *)(iVar1 + 0x10b4) == 0) ||
     (*(int *)(*(int *)(iVar1 + 0x10b4) + 0x14) != *(int *)(param_1 + 0x15c))) {
    uVar2 = FUN_0056cd10(*(undefined4 *)(PTR_DAT_00802c54 + 0x467c),*(undefined4 *)(param_1 + 0x15c)
                        );
    *(undefined4 *)(iVar1 + 0x10b4) = uVar2;
  }
  if (*(int *)(iVar1 + 0x10b4) != 0) {
    iVar5 = *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
    iVar4 = (uint)*(byte *)((*(byte *)(param_1 + 0x160) == 0) + 0x10 + *(int *)(param_1 + 0x15c)) *
            0x5c + iVar5;
    iVar5 = (uint)*(byte *)(*(byte *)(param_1 + 0x160) + 0x10 + *(int *)(param_1 + 0x15c)) * 0x5c +
            iVar5;
    iVar3 = FUN_0043c9a0(iVar1,iVar4,0);
    if (iVar3 == 0) {
      if (*(float *)(iVar5 + 8) < *(float *)(iVar4 + 8)) {
        FUN_0043cbb0(iVar1,iVar4,iVar5,3);
        return 1;
      }
      if ((*(char *)(iVar1 + 0x281) != '\0') &&
         (*(float *)(iVar1 + 0x60) < *(float *)(iVar5 + 0x18))) {
        return 0;
      }
      FUN_0043cbb0(iVar1,iVar4,iVar5,4);
    }
  }
  return 1;
}


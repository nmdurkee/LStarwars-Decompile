/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x480f50; label: FUN_00480f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00480f50(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_3;
  if (*(char *)(iVar1 + 0x7b5) == '\x1f') {
    iVar2 = *(int *)(iVar1 + 0x44c);
    *(undefined4 *)(iVar1 + 0x754) = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(iVar1 + 0x758) = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(iVar1 + 0x75c) = *(undefined4 *)(iVar2 + 0xc);
    *(ushort *)((int)param_3 + 0x292) = *(ushort *)((int)param_3 + 0x292) | 0x4000;
    return 1;
  }
  FUN_0043cbf0(iVar1);
  return 0;
}


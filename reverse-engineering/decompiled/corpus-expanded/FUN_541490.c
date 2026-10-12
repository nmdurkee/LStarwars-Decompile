/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x541490; label: FUN_00541490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00541490(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_1 != (int *)0x0) && (iVar2 = param_2 * 0x13c + *param_1, *(int *)(iVar2 + 0xf8) != 0))
     && (iVar3 = 0, *(short *)(iVar2 + 0xfc) != 0)) {
    iVar1 = 0;
    do {
      FUN_005cfc00(*(int *)(iVar2 + 0xf8) + iVar1,param_3);
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0xc;
    } while (iVar3 < (int)(uint)*(ushort *)(iVar2 + 0xfc));
  }
  return;
}


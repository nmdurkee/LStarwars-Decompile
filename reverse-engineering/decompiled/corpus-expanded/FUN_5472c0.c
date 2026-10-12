/* Ghidra pseudocode, not original source.
 * ev_67e04bb194beb06fa3ce238b04e3098eb4f9bf275f7ff551e45745ee5a93428c
 * Entry: 0x5472c0; label: FUN_005472c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005472c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_0297ad54;
  if (*param_1 != 0) {
    if (param_1[6] != DAT_0297ad54) {
      (*(code *)PTR_FUN_00800820)();
    }
    iVar1 = *param_1;
    iVar2 = *(int *)(iVar1 + 4);
    *param_1 = iVar2;
    if (iVar2 == 0) {
      param_1[1] = 0;
    }
    else {
      *(undefined4 *)(iVar2 + 8) = 0;
    }
    *(ushort *)(iVar1 + 0xe) = *(ushort *)(iVar1 + 0xe) | 1;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(short *)((int)param_1 + 0x16) = *(short *)((int)param_1 + 0x16) + 1;
    if (param_1[6] != iVar3) {
      (*(code *)PTR_FUN_00800824)();
    }
    return iVar1 + 0x10;
  }
  return 0;
}


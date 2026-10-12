/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e6f60; label: thunk_FUN_004e6b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_004e6b70(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iStack_8;
  short sStack_4;
  
  iStack_8 = 0;
  if (0 < DAT_0088a284) {
    piVar4 = &DAT_0088964c;
    do {
      iVar2 = *piVar4;
      if (iVar2 == 0) {
        piVar1 = piVar4 + -3;
        iVar2 = FUN_005cfd60(piVar1);
        if (iVar2 != 0) {
          *(undefined1 *)((int)piVar4 + 10) = 0;
          iVar2 = FUN_005d0330(piVar1);
          if (iVar2 != 0) {
            uVar3 = FUN_006e6b90();
            FUN_005b4dd0(iVar2,uVar3);
            uVar3 = FUN_006e6b90();
            FUN_005b5060(iVar2,uVar3);
            FUN_005ea660(piVar1);
            goto LAB_004e6d10;
          }
        }
LAB_004e6cf0:
        if (*(char *)((int)piVar4 + 10) == '\0') {
          *(undefined1 *)((int)piVar4 + 10) = 1;
          if (*piVar4 != 0) {
            *(undefined4 *)(*piVar4 + 0xa0) = 0;
            FUN_004e66c0(*piVar4);
          }
        }
      }
      else {
        if (((*(uint *)(iVar2 + 0x94) & 0x4000) == 0) || ((*(uint *)(iVar2 + 0x94) & 1) != 0))
        goto LAB_004e6cf0;
        *(undefined1 *)((int)piVar4 + 10) = 0;
        sStack_4 = (short)(int)ROUND((float)(int)(short)piVar4[1] * _DAT_00925018);
        *(short *)(iVar2 + 0xe8) = *(short *)(iVar2 + 0xe8) + sStack_4;
        sStack_4 = (short)(int)ROUND((float)(int)*(short *)((int)piVar4 + 6) * _DAT_00925018);
        *(short *)(*piVar4 + 0xea) = *(short *)(*piVar4 + 0xea) + sStack_4;
        sStack_4 = (short)(int)ROUND((float)(int)(short)piVar4[2] * _DAT_00925018);
        *(short *)(*piVar4 + 0xec) = *(short *)(*piVar4 + 0xec) + sStack_4;
        *(uint *)(*piVar4 + 0x94) = *(uint *)(*piVar4 + 0x94) | 0x10000;
        FUN_005687f0(*piVar4);
      }
LAB_004e6d10:
      iStack_8 = iStack_8 + 1;
      piVar4 = piVar4 + 6;
    } while (iStack_8 < DAT_0088a284);
  }
  return;
}

